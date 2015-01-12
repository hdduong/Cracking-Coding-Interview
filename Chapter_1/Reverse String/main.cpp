#include <iostream>

using namespace std;

void swap(char * a, char * b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverseStr(char * str) {
	if (str == '\0')
		return;

	int last = strlen(str)-1;
	int first = 0;

	while(first < last) {
		swap(str[first++],str[last--]);
	}
}

int main() {
	char oddStr[] = "Hello";
	char evenStr[] = "Hi";
	
	reverseStr(oddStr);
	reverseStr(evenStr);

	cout << oddStr << endl << evenStr << endl;

	return 0;
}