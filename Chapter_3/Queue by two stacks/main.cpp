#include <stdlib.h>
#include <iostream>

using namespace std;

class Node {
public:
	int _data;
	Node *next;
};

class MyStack {
public:
	MyStack();

	void push(int data);
	void pop();
	bool isEmpty();
	int peek();
	void printStack();
	
	Node* getStackTop();
	void setStackTop(Node * _node);
protected:
	Node *stack_top;
};

MyStack::MyStack() {
	stack_top = NULL;
}

Node * MyStack::getStackTop() {
	return stack_top;
}

void MyStack::setStackTop(Node * node) {
	stack_top = node;
}

bool MyStack::isEmpty() {
	if (stack_top == NULL)
		return true;

	return false;
}


void MyStack::push(int data) {
	Node * tmpNode = (Node*)malloc(sizeof(Node));
	tmpNode->_data = data;
	tmpNode->next = NULL;

	if (this->isEmpty()) { 
		stack_top = tmpNode;
		return;
	}

	tmpNode->next = this->stack_top;
	stack_top = tmpNode;
}

int MyStack::peek() {
	if (this->isEmpty()) { 
		return INT_MIN;
	}

	return (stack_top->_data);
}


void MyStack::printStack() {
	Node* tmp = this->stack_top;

	if (this->isEmpty()) return;

	while (tmp != NULL) {
		cout << tmp->_data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


void MyStack::pop() {
	if (this->isEmpty()) {
		return;
	}

	Node* tmp = stack_top;
	stack_top = stack_top->next;
	free(tmp);
}

class MyQueue {
public:
	MyQueue();
	void enqueue(int data);
	void dequeue();
	void printQueue();
protected:
	MyStack *firstStack;
	MyStack *secondStack;
};

MyQueue::MyQueue() {
	firstStack = (MyStack*) malloc(sizeof(MyStack));
	firstStack->setStackTop(NULL);
	
	secondStack = (MyStack*) malloc(sizeof(MyStack));
	secondStack->setStackTop(NULL);
}

void MyQueue::enqueue(int data) {
	firstStack->push(data);
}

void MyQueue::dequeue() {
	while(!firstStack->isEmpty()) {
		int tmpData = firstStack->peek();
		firstStack->pop();
		secondStack->push(tmpData);
	}

	secondStack->pop();

	while(!secondStack->isEmpty()) {
		int tmpData = secondStack->peek();
		secondStack->pop();
		firstStack->push(tmpData);
	}
}

void MyQueue::printQueue() {
	firstStack->printStack();
}

void main() {

	MyQueue myQueue = MyQueue();
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(1);

	myQueue.printQueue();

	myQueue.dequeue();
	myQueue.printQueue();

	/*
	MyStack myStack = MyStack();
	myStack.push(2);
	myStack.push(3);
	myStack.push(1);
	myStack.printStack();

	myStack.pop();
	myStack.printStack();
	*/
}