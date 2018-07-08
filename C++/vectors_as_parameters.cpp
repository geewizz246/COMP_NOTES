//How to pass vectors as parameters into functions
#include <iostream>
#include <vector>

using namespace std;

//function declaration
void fillVector(vector<int>&);
//fillVector
//@param vector<int>& - the vector to be filled
//being passed to the function by reference to save system memory

void printVector(const vector<int>&);
//printVector
//@param const vector<int>& - the vector to be printed

void reverse(const vector<int>&);
//reverse
//@param const vector<int>& - vector to be printed backwards

void printEvens(const vector<int>&);
//printsEven - only prints even numbers in vector
//@param const vector<int>&

void replace(vector<int>&);
//replace
//@param vector<int>&

//Main Function
int main() {
	vector<int> myVector;

	fillVector(myVector);
	printVector(myVector);
	reverse(myVector);
	printEvens(myVector);
	replace(myVector);

	return 0;
}

//Function Definitions
//Function to fill the vector with numbers
void fillVector(vector<int>& V) {
	cout << "Type in a list of numbers (-1 to stop): ";
	int input;
	cin >> input;

	while (input != -1) {
		V.push_back(input);
		cin >> input;
	}
}

//Function to print the vector
void printVector(const vector<int>& V) {
	cout << "\n\nVector: ";

	for (unsigned int i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}

	cout << endl;
}

//Function to print the vector in reverse
void reverse(const vector<int>& V) {
	cout << "\n\nVector in reverse: ";

	for (unsigned int i = V.size(); i > 0; i--) {
		cout << V[i-1] << " ";
	}

	cout << endl;
}

//Function to print even numbers in the vector
void printEvens(const vector<int>& V) {
	cout << "\n\nEven numbers in vector: ";

	for (unsigned int i = 0; i < V.size(); i++) {
		if (V[i] % 2 == 0)
			cout << V[i] << " ";
	}

	cout << endl;
}


//Function to replace one element in the vector with another
void replace(vector<int>& V) {
	int old, replace;

	cout << "\n\nEnter the integer being replaced: ";
	cin >> old;
	cout << "Enter the new integer: ";
	cin >> replace;	

	for (unsigned int i = 0; i < V.size(); i++) {
		if (V[i] == old)
			V[i] = replace;
	}

	printVector(V);
}