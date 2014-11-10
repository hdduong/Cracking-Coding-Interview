#include <stdlib.h>
#include <iostream>

using namespace std;

void print(int * arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void allSubset(int arr[], int n, int * arrValue, int resultLength, bool *  visited) {
	
	if (n >= 1) {
		for (int i = 0; i <=n; i++)
			cout << arr[i] << endl;
	}

	for (int length = 2; length <= n + 1; length++) { //loop each length
		
		for (int start = 0; start <= n; start++) { //start at	
		
			for (int k = start; k <= n; k++) {
				visited[k] = false;
			}

			resultLength = 0;

			for (int j = start; j <= n; j++) { // loop all element of current subuset
				if (visited[j] == false) {
					resultLength++;
					arrValue[resultLength - 1] = arr[j];
					if (resultLength == length) { 
						print(arrValue,resultLength);
						resultLength--;
					}
					visited[j] = true;
				}
			}

		}
	}

}

void main() {
	int arr[] = {1, 2, 3 ,4};
	int size = sizeof(arr)/ sizeof(int);
	int n = size -1;

	int *arrValue = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		arrValue[i] = INT_MIN;
	}

	bool * visited = (bool *) malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	int resultLength = 0;
	
	allSubset(arr,n,arrValue,resultLength,visited);

}