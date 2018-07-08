#include "List.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class List::Node{
public:
	int data = 0;
	Node* link = nullptr;
};

List::~List()
{
	clear();
}

int List::size() const
{
	return num_elements;
}

void List::insert(int val, int k)
{
	if (k < 1 || k > num_elements + 1)
		throw out_of_range("List::insert("+to_string(val)+", "+to_string(k)+") failed. (valid positions are 1 to "+to_string(num_elements)+")");
	
	Node* newPtr = new Node{val};

	if (k == 1)
	{
		newPtr->link = frontPtr;
		frontPtr = newPtr;
	}
	else
	{
		Node* iPtr = frontPtr;

		for (int loc = 1; loc < k - 1; loc++)
			iPtr = iPtr->link;
		
		newPtr->link = iPtr->link;
		iPtr->link = newPtr;
	}
	
	num_elements++;
}

void List::remove(int k)
{
	if (k < 1 || k > num_elements)
		throw out_of_range("List::delete("+to_string(k)+") failed. (valid positions are 1 to "+to_string(num_elements)+")");

	Node* delPtr = nullptr;

	if (k == 1)
	{
		delPtr = frontPtr;
		frontPtr = delPtr->link;
	}
	else
	{
		Node* iPtr = frontPtr;
		
		for (int loc = 1; loc < k - 1; loc++)
			iPtr = iPtr->link;

		delPtr = iPtr->link;
		iPtr->link = delPtr->link;
	}
	
	delete delPtr;
	num_elements--;
}

int List::getElem(int k) const
{
	if (k < 1 || k > num_elements)
		throw out_of_range("List::getElem("+to_string(k)+") failed. (valid positions are 1 to "+to_string(num_elements)+")");

	if (k == 1)
		return frontPtr->data;
	else
	{
		Node* iPtr = frontPtr;
		
		for (int loc = 1; loc < k; loc++)
			iPtr = iPtr->link;

		return iPtr->data;
	}
}

void List::printList() const
{
	cout << "frontptr";
	for (int i = 1; i <= num_elements; i++)
		cout << " -> " << getElem(i);
	cout << endl << endl;
}

void List::clear()
{
	while (frontPtr != nullptr)
		remove(1);
}