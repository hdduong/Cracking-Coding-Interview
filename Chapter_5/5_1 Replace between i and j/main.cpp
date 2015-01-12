#include <iostream>
#include <bitset>

using namespace std;

bool isOdd(int number) {
	return (number & 0x1); 
}

void printBinary32IntByChar(int number) {
	char rep[32];
	for (int i = 0; i < 32;i++)
		rep[i] = '0';
	
	int j = 0;
	while(number > 0) {
		if (isOdd(number)) rep[j] = '1';
		number = number >> 1;
		j++;
	}

	for (int i = 31; i >= 0;i--) {
		cout << rep[i];
	}
	cout << endl;
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

// i < j
int replaceBetweeenIJ(int N, int M, int i, int j) {
	int NFirstPart =  N >> j;
	//printBinary32IntByBitSet(NFirstPart);
	
	int NLastPart = N & (1 << (i+1) - 1);
	//printBinary32IntByBitSet(NLastPart);
	
	int NMiddlePart = M << i;
	//printBinary32IntByBitSet(NMiddlePart);
	
	int result =  ( (NFirstPart << j) | NMiddlePart | NLastPart);
	//printBinary32IntByBitSet(result);

	return result;
}

int main () {
	
	//printBinary32IntByChar(1024);
	printBinary32IntByBitSet(1024);
	printBinary32IntByBitSet(19);

	int N = replaceBetweeenIJ(1024,19,2,6);
	printBinary32IntByBitSet(N);

	return 0;
}