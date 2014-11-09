#include <stdio.h>
#include <iostream>
#include <vector>

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

void printPath(vector<int> path) {
	for (auto it = path.begin(); it != path.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void findGivenSumHelper(Node * root, int sum, vector<int> &path) {

	if ( (root == NULL) && (sum == 0) ) {
		printPath(path);
		return;
	}

	if (( root == NULL) && (sum != 0)) {
		return;
	}

	if ( (root != NULL) && (root->_data == sum) ) {
		path.push_back(root->_data);
		printPath(path);
		path.pop_back();
	}

	if ( ( root!= NULL) && (sum == 0) ) {
		if (root->_data == 0) {
			path.push_back(root->_data);
			printPath(path);
		} else if (root->_data != 0) {
			
		}
	}

	if ( (root != NULL) && (root->_data != sum)) {
		path.push_back(root->_data);
		findGivenSumHelper(root->left, sum - root->_data,path);
		findGivenSumHelper(root->right, sum - root->_data,path);	
		
		path.pop_back();
		// start from child node
		if (!path.empty()) return;  // 1 (3)  6 case

		findGivenSumHelper(root->left, sum,path);
		findGivenSumHelper(root->right, sum,path);
	}

}


void findGivenSum(Node * root, int sum) {
	vector<int> path = vector<int>();
	findGivenSumHelper(root, sum, path);
	
}

void main() {
	Node * root = newNode(1);
	Node * left = newNode(2);
	Node * right = newNode(3);
	Node * leftLeft = newNode(4);
	Node * leftRight = newNode(5);
	Node * rightLeft = newNode(6);
	Node * rightRight = newNode(7);

	root->left = left;
	root->right = right;

	left->left = leftLeft;
	left->right = leftRight;

	right->left = rightLeft;
	right->right = rightRight;

	findGivenSum(root, 7);
}


