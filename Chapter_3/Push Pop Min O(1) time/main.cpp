#include <iostream>
#include <stdlib.h>


using namespace std;

struct stackNode {
	int mainValue;
	int minValue;
	stackNode *next;
};


stackNode* newNode(int value) {
	stackNode* aNewNode = (stackNode *)malloc(sizeof(stackNode));
	aNewNode->mainValue = value;
	aNewNode->minValue= value;
	aNewNode->next = NULL;

	return aNewNode;
}


void push(stackNode ** top_ref, int data) {
	if (*top_ref == NULL) {
		*top_ref = newNode(data);
	} else {
		stackNode * aNewNode = newNode(data);
		
		int currentMin = (*top_ref)->minValue;
		if (currentMin < data)
			aNewNode->minValue = currentMin;

		aNewNode->next = *top_ref;
		(*top_ref) = aNewNode;
	}
}

int peakTop(stackNode** top_ref) {
	return (*top_ref)->mainValue;
}

int pop(stackNode ** top_ref) {
	if (*top_ref == NULL)
		return INT_MIN;

	stackNode * tmp = *top_ref;
	int popValue = tmp->mainValue;

	(*top_ref) = (*top_ref)->next;
	free(tmp);

	return popValue;
}

int min(stackNode *top_ref) {
	if (top_ref == NULL)
		return INT_MIN;

	return (top_ref)->minValue;
}

void main() {
	stackNode* stack = NULL;
	push(&stack,5);
	cout << min(stack) << endl;

	push(&stack,6);
	cout << min(stack) << endl;

	push(&stack,3);
	cout << min(stack) << endl;

	push(&stack,7);
	cout << min(stack) << endl;

	pop(&stack);
	cout << min(stack) << endl;

	pop(&stack);
	cout << min(stack) << endl;
}

