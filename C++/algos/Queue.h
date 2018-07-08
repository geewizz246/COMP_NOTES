#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Queue{
private:
	class Node;
	
	Node* lastPtr = nullptr;
	int num_elements = 0;

public:
	~Queue(); //destructor
	void enqueue(int);
	void dequeue();
	int front() const;
	int back() const;
	int size() const;
	void clear(); 
};

#endif

