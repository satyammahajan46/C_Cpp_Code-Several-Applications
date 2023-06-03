#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
template <class T>
class Queue
{
private:
	struct Node {
		T d;
		Node *next;
	};
	Node *head, *tail;
public:
	Queue();
	bool isEmpty();
	void enQueue(T x);
	T deQueue();
	T front();
	void print();

};
#endif

