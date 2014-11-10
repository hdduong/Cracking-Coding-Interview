#include <stdlib.h>
#include <iostream>

using namespace std;

void print(char * arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void printValid(int eachType, int openLeft, int closeLeft, char * ret, int length) {
	if (openLeft == 0) {
		while(closeLeft > 0) {
			ret[length] = ')';
			length++;
			closeLeft--;
		}
		print(ret, length);
		return;
	}

	// openLeft > 0
	ret[length] = '(';
	length++;

	printValid(eachType, openLeft-1,closeLeft,ret, length);

	length--;

	if (openLeft < closeLeft) {
		ret[length] = ')';
		length++;
		printValid(eachType, openLeft,closeLeft-1,ret, length);
	}

}
void main() {
	int no_couple_parentheses = 3;
	int length = no_couple_parentheses * 2;

	int openLeft = no_couple_parentheses;
	int closeLeft = no_couple_parentheses;

	char * ret = (char *) malloc(sizeof(char) * length);

	int currentLength = 0;

	printValid(no_couple_parentheses,openLeft,closeLeft,ret,currentLength);
}