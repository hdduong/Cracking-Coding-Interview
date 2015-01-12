using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace LoadTest_1
{
    class Program
    {
        static void Main(string[] args)
        {
         CreateLogFile Err = new CreateLogFile();

         List<UrlObject> listObject = importURL("5.complain.csv");

            //List<UrlObject> subList = getSubList(ref listObject, 0, 100);
            List<UrlObject> subList = createSubListDiffrentPool(ref listObject, 300);
            if (subList != null)
            {
                bool errorOccur = createHTTPSequentialRequest(ref subList, Err);
                if (errorOccur) Console.WriteLine("Issue Occurs");
            }    


        }

        public static List<UrlObject> getSubList(ref List<UrlObject> parentList, int firstIndex, int secondIndex)
        {
            if (firstIndex > parentList.Count -1) return null;
            if (secondIndex > parentList.Count - 1) secondIndex = parentList.Count - 1;

            List<UrlObject> sublist = parentList.GetRange(firstIndex, secondIndex);
            
            return sublist;
        }

       
        public static List<UrlObject> createSubList(ref List<UrlObject> parentList, int startIndex, int step)
        {
            if (startIndex > parentList.Count - 1) return null;

            int secondIndex = startIndex + step;
            if (secondIndex  > parentList.Count - 1) secondIndex = parentList.Count - 1;

            List<UrlObject> sublist = parentList.GetRange(startIndex, secondIndex);

            return sublist;

        }

        //first index 0, 300, 600, 900, 1200, 1500, 1800, 2100, 2400, 2700, 3000
        public static List<UrlObject> createSubListDiffrentPool(ref List<UrlObject> parentList, int step)
        {
            int startIndex = 0;
            List<UrlObject> sublist = new List<UrlObject>();
            while (startIndex <= 1500)
            {
                if (startIndex > parentList.Count - 1) return sublist;

                int secondIndex = startIndex + step;
                if (secondIndex > parentList.Count - 1) step = parentList.Count - startIndex - 1;

                List<UrlObject> sl = parentList.GetRange(startIndex, step);
                sublist.AddRange(sl);

                startIndex += 300;
            }
            return sublist;

        }

        public static bool createHTTPRequest(ref List<UrlObject> list, CreateLogFile Err) 
        {
           
            bool errorOccurs = false;


            Parallel.ForEach (list, urlObject =>
            {
                string responseMessage = string.Empty;
                WebRequest request = WebRequest.Create(urlObject.URL);
                request.Timeout = 100000;
                request.Credentials = CredentialCache.DefaultCredentials;
                try
                {
                    System.Diagnostics.Stopwatch timer = new Stopwatch();
                    timer.Start();
                    WebResponse response = request.GetResponse();
                    timer.Stop();
                    TimeSpan timeTaken = timer.Elapsed;
                    urlObject.StatusCode = ((HttpWebResponse)response).StatusCode.ToString();
                    urlObject.StatusDescription = ((HttpWebResponse)response).StatusDescription.ToString();
                    response.Close();
                    responseMessage += urlObject.URL + " " + urlObject.StatusCode + " " + urlObject.StatusDescription + " " + timeTaken.ToString();
                    Err.ErrorLog(responseMessage);
                }
                catch (WebException ex)
                {
                    var response = ex.Response;
                    responseMessage += urlObject.URL + " " + ex.Message;
                    errorOccurs = true;
                    Err.ErrorLog(responseMessage);
                }
            }
            );

            return errorOccurs;
            
        }

        public static bool createHTTPSequentialRequest(ref List<UrlObject> list, CreateLogFile Err)
        {

            bool errorOccurs = false;


            foreach(UrlObject urlObject in list)
            {
                string responseMessage = string.Empty;
                WebRequest request = WebRequest.Create(urlObject.URL);
                request.Timeout = 100000;
                request.Credentials = CredentialCache.DefaultCredentials;
                try
                {
                    System.Diagnostics.Stopwatch timer = new Stopwatch();
                    timer.Start();
                    WebResponse response = request.GetResponse();
                    timer.Stop();
                    TimeSpan timeTaken = timer.Elapsed;
                    urlObject.StatusCode = ((HttpWebResponse)response).StatusCode.ToString();
                    urlObject.StatusDescription = ((HttpWebResponse)response).StatusDescription.ToString();
                    response.Close();
                    responseMessage += urlObject.URL + " " + urlObject.StatusCode + " " + urlObject.StatusDescription + " " + timeTaken.ToString();
                    Err.ErrorLog(responseMessage);
                }
                catch (WebException ex)
                {
                    var response = ex.Response;
                    responseMessage += urlObject.URL + " " + ex.Message;
                    errorOccurs = true;
                    Err.ErrorLog(responseMessage);
                }
            }

            return errorOccurs;

        }

        public static List<UrlObject> importURL(string textFile)
        {
            List<UrlObject> listObject = new List<UrlObject>();

            var reader = new StreamReader(File.OpenRead(textFile));

            while (!reader.EndOfStream)
            {
                var line = reader.ReadLine();
                var values = line.Split(',');

                UrlObject urlObject = new UrlObject();
                urlObject.URL = values[0].Trim();
                urlObject.pool = values[1].Trim() ;

                listObject.Add(urlObject);
            }

            return listObject;
        }
    }
}
