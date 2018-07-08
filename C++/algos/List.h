#include <iostream>

using namespace std;

#ifndef LIST_H
#define LIST_H

class List{
private:
	class Node;
	Node* frontPtr = nullptr; //pointer to front of list
	int num_elements = 0; //number of elements in list

public:
	~List(); //destructor
	void insert(int val, int k); //insert element at position k
	void remove(int k); //remove element from position k
	int size() const; //return size of list
	int getElem(int k) const; //return element at position k
	void printList() const; //print list
	void clear(); //clear list
};

#endif

