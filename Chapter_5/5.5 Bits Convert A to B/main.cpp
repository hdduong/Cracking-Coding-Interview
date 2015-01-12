#include <iostream>
#include <bitset>

using namespace std;

bool isOdd(int number) {
	return (number & 0x1); 
}


void printBinary32IntByBitSet(int number) {
	bitset<32> rep;
	for (int i = 0; i < 32;i++)
		rep[i] = 0;
	
	int j = 0;
	while(number > 0) {
		if (isOdd(number)) rep[j] = 1;
		number = number >> 1;
		j++;
	}

	cout << rep << endl;
}


int bitsToConvert(int a, int b) {
	int k = a ^ b;
	int numBits = 0;
	while (k > 0) {
		if (isOdd(k)) {
			numBits++;
		}
		k = k >> 1;
	}
	return numBits;
}
int main () {
	
	//printBinary32IntByChar(1024);
	printBinary32IntByBitSet(31);
	printBinary32IntByBitSet(14);

	int numBits = bitsToConvert(31,14);
	cout << numBits << endl;
	return 0;
}
