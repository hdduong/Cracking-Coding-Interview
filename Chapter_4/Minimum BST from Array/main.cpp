#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
	int _data;
	Node * left;
	Node * right;
};


Node * newNode(int data) {
	Node * aNewNode = (Node *)malloc(sizeof(Node));
	aNewNode->_data = data;
	aNewNode->left = aNewNode->right = NULL;

	return aNewNode;
}

Node * buildTreeUntil(int arr[], int start, int end) {
	if (start > end) return NULL;
	int middle = start + (end - start)/ 2;

	Node *root = newNode(arr[middle]);

	root->left = buildTreeUntil(arr,start,middle-1);
	root->right = buildTreeUntil(arr,middle+1, end);

	return root;
}

Node * buildTree(int arr[], int size) {
	int n = size - 1;
	int start = 0;
	return buildTreeUntil(arr,start,n);
}


void printTree(Node * root) {
	if (root == NULL) return;
	
	cout << root->_data << " ";
	printTree(root->left);
	printTree(root->right);

	
}

void main() {
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(int);

	Node* root = buildTree(arr,size);
	printTree(root);

	cout << endl;
}