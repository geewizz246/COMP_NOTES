// Main.cpp
// https://eecs.wsu.edu/~nroy/courses/cpts122/labs/Lab9_cpts122.htm
#include <iostream>
#include "Task1.h"

using namespace std;

int main() {
	Base* ptr = new Base();
	ptr->testFunction(); // prints "Base class"
	delete ptr;

	ptr = new Derived();
	ptr->testFunction(); // prints "Derived class"
	delete ptr;

	return 0;
}