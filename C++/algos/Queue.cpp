#include 'Queue.h'
#include <iostream>
#include <stdexcept>

using namespace std;

class Queue::Node
{
public:
	int data = 0;
	Node* link = nullptr;
};

Queue::~Queue()
{
	clear();
}

int Queue::size()
{
	return num_elements;
}

void Queue::enqueue(int val)
{
	Node* newPtr = new Node{val};
	
	if (num_elements == 0)
	{
		lastPtr = newPtr;
		newPtr->link = lastPtr;
	}
	else
	{
		newPtr->link = lastPtr->link;
		lastPtr->link = newPtr;
		lastPtr = newPtr;
	}

	num_elements++;
}

void Queue::dequeue()
{
	if (num_elements <= 0)
		throw out_of_range("Queue::dequeue() failed. No elements in queue.");

	Node* delPtr = lastPtr->link;
	
	if (num_elements == 1)
		lastPtr = nullptr;
	else
		lastPtr->link = delPtr->link;

	delete delPtr;
	num_elements--;
}

int Queue::front()
{
	return lastPtr->link->data;
}

int Queue::back()
{
	return lastPtr->data;
}

void Queue::clear()
{
	while (num_elements > 0)
		dequeue();
}