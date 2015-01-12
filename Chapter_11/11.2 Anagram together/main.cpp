#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

// 0(n) space
// 0(nlgn) complexity

struct Node {
	size_t index;
	char * strAnagram;
};

int compareChar(const void*lhs, const void* rhs) {
	return ( *(char*)(lhs) - *(char*)(rhs) );
}

//true if the first argument goes before the second argument 
bool compareString(Node* lhs, Node* rhs)  {
	if (strcmp(lhs->strAnagram,rhs->strAnagram) > 0) // error with >=
		return true;
	
	return false;
}


void printAnagaram(list<Node *> &v) {
	for(list<Node * >::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << (*iter)->strAnagram << endl;
	}
}

void printSoruceAnagaram(char* arrStr[], list<Node *> &v) {
	for(list<Node * >::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << arrStr[(*iter)->index] << endl;
	}
}


void neighborAnagram(char* arrStr[], size_t arrSize) {
	list<Node * > result;
	
	for (int i = 0; i < arrSize; i++) {
		Node * aNode = new Node;
		aNode->index = i;
		
		aNode->strAnagram = new char[strlen(arrStr[i])];
		strcpy(aNode->strAnagram ,arrStr[i]);

		result.push_back(aNode);
	}

	//sort in each string
	for(list<Node * >::iterator iter = result.begin(); iter != result.end(); iter++) {
		Node * aNode = *iter;	
		qsort(aNode->strAnagram,strlen(aNode->strAnagram),sizeof(char),compareChar);
	}

	//printAnagaram(result);
	result.sort(compareString);
	//printAnagaram(result);

	printSoruceAnagaram(arrStr,result);
}


int main() {
	// array of stirng
	char* arrStr[] = {"spot","listen","nestil","tops","silent"};
	size_t arrSize = 5;

	neighborAnagram(arrStr,arrSize);

	return 0;
}