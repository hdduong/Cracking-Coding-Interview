#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;
// sort stack accesing order (max item on top) 
// push, pop, peak, isEmpty

class StackSort {
public:
	StackSort();
	void push(int data);
	void pop();
	int peek();
	bool isEmpty();
	void printStack();
protected:
	stack<int> myStack;
};

StackSort::StackSort() {
	myStack = stack<int>();
}



void StackSort::push(int data) {
	if (this->isEmpty()) {
		myStack.push(data);
		return;
	}
	
	int top_data = this->peek();

	if (top_data <= data) {
		myStack.push(data);
		return;
	}
	else if (top_data > data) {
		int tmp_data = this->peek();
		this->pop();
		this->push(data);
		this->push(tmp_data);
	}

}

void StackSort::pop() {
	return myStack.pop();
}

int StackSort::peek() {
	return myStack.top();
}

bool StackSort::isEmpty() {
	return myStack.empty();
}

void StackSort::printStack() {
	if (myStack.empty())
		return;

	while (!this->isEmpty()) {
		int tmpData = this->peek();
		cout << tmpData << " ";
		this->pop();
	}
}

void main() {
	StackSort aStack;
	aStack.push(3);
	aStack.push(1);
	aStack.push(2);

	aStack.printStack();

	cout << endl;
}