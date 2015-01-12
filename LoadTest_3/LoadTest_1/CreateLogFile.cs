using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace LoadTest_1
{
    class CreateLogFile : IDisposable
    {
        string sLogFormat { get; set; }
        string sErrorTime { get; set; }
        readonly object _lock = new object();
        string path { get; set; }
        private StreamWriter sw;

        public CreateLogFile()
        {


            //sLogFormat used to create log files format :
            // dd/mm/yyyy hh:mm:ss AM/PM ==> Log Message
            sLogFormat = DateTime.Now.ToShortDateString().ToString() + " " + DateTime.Now.ToLongTimeString().ToString() + " ==> ";

            //this variable used to create log filename format "
            //for example filename : ErrorLogYYYYMMDD
            string sYear = DateTime.Now.Year.ToString();
            string sMonth = DateTime.Now.Month.ToString();
            string sDay = DateTime.Now.Day.ToString();
            sErrorTime = sYear + sMonth + sDay;

            string logsDirectory = System.IO.Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), "Logs");

            if (!System.IO.Directory.Exists(logsDirectory))
            {
                System.IO.Directory.CreateDirectory(logsDirectory);
            }

            path = System.IO.Path.Combine(logsDirectory, String.Format("{0}_{1:yyyy-MM-dd_hh-mm-ss-tt}.txt", "Log", DateTime.Now));

            sw = new StreamWriter(path, true) { AutoFlush = true };
        }

        public void ErrorLog(string sErrMsg)
        {
            lock (_lock)
            {
                //sw.WriteLine(sLogFormat + sErrMsg);
                sw.WriteLine(sLogFormat + sErrMsg);
            }
        }

        public void Dispose()
        {
            sw.Flush();
            sw.Close();
        }
    }
}
