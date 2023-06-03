#include "Queue.h"
#include <iostream>

template <class T>
Queue<T>::Queue(){
	head = tail = nullptr;
}

template <class T>
bool Queue<T>::isEmpty() {
	return head == nullptr;
}
template <class T>
void Queue<T>::enQueue(T x) {
	if (head == nulptr) {
		head = new Node{ x , nullptr };
		tail = head;
	}
	else {
		tail->next = new Node{ x,nullptr };
		tail = tail->next;
	}
}
template <class T>
T Queue<T>::deQueue() {
	if (head == nullptr) {
		cout << "Empty Queue";
		exit(-1);
	}
	T retVal = head->d;
	Node* temp = head;
	head = head->next;
	delete head;
	if (head == nullptr)
		tail = nullptr;
	return retVal;
}
template <class T>
T Queue<T>::front() {
	if (head == nullptr) {
		cout << "Empty Queue";
		exit(-1);
	}
	return head->d;
}
template <class T>
 void Queue<T>::print() {
	Node *p = head;
	while (p != nullptr) {
		output << p->d;
		p = p->next;
	}
	return output;
}