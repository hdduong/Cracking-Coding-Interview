#include <stdlib.h>
#include <iostream>

using namespace std;

void countStair(int n, int * count) {
	if (n < 0 ) return;

	if (n == 0) {
		(*count)++;
		return;
	}
	countStair(n-1, count);
	countStair(n-2, count);
	countStair(n-3, count);

}


// DYNAMIC Programming by:
// F(n) = F(n-3) + F(n-2) + F(n-1)

void main() {
	int n = 5;
	if (n <= 0) cout << "invalid input" << endl;

	int * count = (int*)malloc(sizeof(int));
	*count  = 0;

	countStair(n,count);
	cout << *count << endl;

	free(count);
}