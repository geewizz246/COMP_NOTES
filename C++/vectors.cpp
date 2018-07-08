#include <iostream>
#include <vector>
using namespace std;

//Function Declarations
void printVec(vector<int>&);
void printEmpty(const vector<int>&);

int main() {
	
	//format: vector<DataType> nameOfVector

	//****************************
	//****  VECTOR FUNCTIONS  ****
	//****************************
	//.push_back(value) ==> adds an element to the END of the vector (also resizes it)
	//.pop_back ==> removes an element from the END of the vector (also resizes it)
	//.at(index) ==> returns element at a specified index number
	//.size() ==> returns an unsigned int equal to the number of elements in the vector
	//.begin() ==> reads vector from first element (index 0)
	//.insert(nameOfVector.begin() + integer, new value) ==> adds element BEFORE specified index
	//.erase(nameOfVector.begin + integer) ==> removes element AT specified index
	//.clear() ==> removes all elements in vector
	//.empty() ==> returns boolean value if whether vector is empty
	
	vector<int> myVector;
	
	//adding elements
	myVector.push_back(3);
	myVector.push_back(9);
	myVector.push_back(12);
	myVector.push_back(0);
	myVector.push_back(7);
	myVector.push_back(4);
	
	printVec(myVector);

	//removing elements
	myVector.pop_back(); //deletes 4

	printVec(myVector);

	//inserting elements
	myVector.insert(myVector.begin(), 5); //inserts 5 before the element at index 0 (the beginning)
	myVector.insert(myVector.begin() + 3, 29); //inserts 29 before the element at index 0 + 3 = index 3

	printVec(myVector);
	
	//erasing elements
	myVector.erase(myVector.begin() + 2); //erases element at index 0 + 2 = index 2
	
	printVec(myVector);

	//clearing elements
	printEmpty(myVector);

	myVector.clear();

	printEmpty(myVector);
	
	return 0;
}

//Function Definitions
//function to print vectors
void printVec(vector<int>& V) {
	cout << "Vector: \n";
	for (unsigned int i = 0; i < V.size(); i++)
		cout << "\t[" << i << "]\t" << V[i] << '\n';

	cout << endl;
}

//function to determine if vector is empty
void printEmpty(const vector<int>& V) {
	if (V.empty())
		cout << endl << "Is Empty!" << endl;
	else
		cout << endl << "Is NOT Empty" << endl;
}