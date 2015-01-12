#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct personCircus {
	int ht;
	int wt;

	personCircus(int height, int weight) : ht(height), wt(weight) {
	}
};

struct longestSequence {
	int count;
	int prevIndex;
};

bool compareHeight(personCircus &rhs, personCircus &lhs) {
	return (rhs.ht < lhs.ht);
}
void printCircus(vector<personCircus> &v) {
	for(vector<personCircus>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << "(" << iter->ht <<"," << iter->wt << ")" << endl;
	}
}

void printCircusResult(vector<personCircus> &v, vector<longestSequence> ls) {
	int maxCount = 0;
	int maxIndex = 0;

	for(int i = 0; i < ls.size(); i++) {
		maxCount = max(ls[i].count,maxCount);
		maxIndex = i;
	}

	cout << "count max: " << maxCount << endl;
	while (maxIndex > -1) {
		cout << "(" << v[maxIndex].ht <<"," << v[maxIndex].wt << ")" << endl;
		maxIndex = ls[maxIndex].prevIndex;
	}
}

void sortCircus(personCircus arr[], int size) {
	vector<personCircus> vPerson;
	vector<longestSequence> longSeq;

	for (int i = 0; i < size; i++) {
		vPerson.push_back(arr[i]);
	}

	// sort by Height
	sort(vPerson.begin(), vPerson.end(), compareHeight);	
	//printCircus(vPerson);


	// find max people in the tower
	// end at i
	for(vector<personCircus>::iterator iter = vPerson.begin(); iter != vPerson.end(); iter++) {
		longestSequence * currentLongest = new longestSequence();
		if (iter == vPerson.begin()) {
			currentLongest->count = 1;
			currentLongest->prevIndex = -1;
			longSeq.push_back(*currentLongest);
		}
		else {
			// loop through all max index before
			// tricky: vPerson and longSeq has similar index
			int maxCount = 1; //max itself
			int maxIndex = -1;
			for(int i = 0; i < longSeq.size(); i++) {
				
				if (vPerson[i].wt <= (iter->wt) ) {
					if (longSeq[i].count + 1 > maxCount) {
						maxCount = longSeq[i].count + 1;
						maxIndex = i;
					}
				}

			}
			
			currentLongest->count = maxCount;
			currentLongest->prevIndex = maxIndex;
			longSeq.push_back(*currentLongest);
		}

				
	}
	printCircusResult(vPerson,longSeq);
	

}


int main() {

	personCircus arr[] = { 
		personCircus(65,100), 
		personCircus(70,150), 
		personCircus(56,90), 
		personCircus(75,190), 
		personCircus(60,95), 
		personCircus(68,110),
		personCircus(63,111),
		personCircus(61,107),
		personCircus(64,112)};
	
	int size = sizeof(arr)/sizeof(personCircus);

	sortCircus(arr,size);

	return 0;
}