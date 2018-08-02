// Main.cpp
// https://eecs.wsu.edu/~nroy/courses/cpts122/labs/Lab9_cpts122.htm
#include <iostream>
#include "Mammal.h"
#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
#include "GuineaPig.h"

using namespace std;

int main() {
	Mammal* theArray[5]; // Pointer to an array of Mammal objects
	Mammal* ptr; // Mammal type pointer
	int choice;

	for (int i = 0; i < 5; i++) {
		cout << "(1)dog (2)cat (3)horse (4)guinea pig : ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				ptr = new Dog;
				break;
			case 2:
				ptr = new Cat;
				break;
			case 3:
				ptr = new Horse;
				break;
			case 4:
				ptr = new GuineaPig;
				break;
			default:
				ptr = new Mammal;
				break;
		}

		theArray[i] = ptr; // Add object to array
	}

	for (auto mammal : theArray)
		mammal->Speak();

	// Always free dynamically allocated objects
	for (auto mammal : theArray)
		delete mammal;

	return 0;
}