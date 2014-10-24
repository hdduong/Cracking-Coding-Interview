#include <iostream>
using namespace std;

template <class T>
class Node{

public: 
	Node(); 
	Node(const T& item, Node<T> *nextPtr = nullptr);
	Node<T> * getNext();
	T getData();
	void Insert(Node<T> *aNode); // insert at front
	void printNode(); // print from current node
	
	Node<T> * getKthLast(int k);
private:
	Node<T>* next;
	T data;
};

template <class T>
Node<T>::Node() {
}

template <class T>
Node<T>::Node(const T& dataItem, Node<T> * nextPtr) {
	this->data = dataItem;
	this->next = nextPtr;
}

template <class T> 
Node<T> * Node<T>::getNext() {
	return this->next;
}

template <class T>
T Node<T>::getData() {
	return data;
}

//insert a Node in after current Node
template <class T>
void Node<T>::Insert(Node<T> * aNode) { 
	this->next = aNode;
}

template <class T> 
void Node<T>::printNode() {
	Node<T>* tmp = this;
	while(tmp != nullptr) {
		cout << tmp->getData() << " ";
		tmp = tmp->getNext();
	}
	cout << endl;
}


// find kth element from last. 
template <class T>
Node<T>* Node<T>::getKthLast(int k) {
	Node<T> * firstNode = this;
	Node<T> * secondNode = nullptr;

	int count = 0; 
	while (count < k) {
		firstNode = firstNode->getNext();
		count++;
	}

	secondNode = this;
	while(firstNode->next != nullptr) {
		firstNode = firstNode->getNext();
		secondNode = secondNode->getNext();
	}
	return secondNode;
}

void main() {
	Node<int> * node1 = new Node<int>(2);
	Node<int> * node2 = new Node<int>(3,node1);
	Node<int> * node3 = new Node<int>(4,node2);
	Node<int> * node4 = new Node<int>(5); node4->Insert(node3);
	Node<int> * node5 = new Node<int>(1); node5->Insert(node4);

	node5->printNode();

	Node<int> * kNode = node5->getKthLast(1);
	cout << kNode->getData() << endl;
}