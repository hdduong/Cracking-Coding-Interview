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
	
	void swap(Node<T> *a, Node<T> *b);
	void parition(T X);
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

template <class T>
void Node<T>::swap(Node<T>* a, Node<T> *b) {
	T data = a->getData();
	a->data = b->getData();
	b->data = data;
}


// partition around value X
template <class T>
void Node<T>::parition(T X) {
	// find node X // assume that X is available
	Node<T> *tmp = this;
	while (tmp != nullptr) {
		if (tmp->getData() == X)
			break;
		tmp = tmp->getNext();
	}

	Node<T>* last = this;
	while (last->next != nullptr) {
		last = last->getNext();
	}

	// exchange data with X and last node
	swap(tmp,last);

	// start partition
	Node<T> *prev = nullptr;
	tmp = this;
	while (tmp != nullptr) {
		if (tmp->getData() < X ) {
			if (prev == nullptr) prev = this;
			else prev= prev->getNext();
			swap(prev,tmp);
		}
		tmp = tmp->getNext();
	}

	if (prev->getData() != X) {
		prev = prev->getNext();
		swap(prev,last);
	}
}

void main() {
	Node<int> * node1 = new Node<int>(2);
	Node<int> * node2 = new Node<int>(3,node1);
	Node<int> * node3 = new Node<int>(4,node2);
	Node<int> * node4 = new Node<int>(5); node4->Insert(node3);
	Node<int> * node5 = new Node<int>(1); node5->Insert(node4);
	
	node5->printNode();
	node5->parition(4);
	node5->printNode();
	
}