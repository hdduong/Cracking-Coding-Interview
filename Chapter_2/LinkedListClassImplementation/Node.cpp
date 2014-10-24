#include "Node.h"

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
	aNode->getNext() = this->next;
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