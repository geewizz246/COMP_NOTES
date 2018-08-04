// ************** TUTORIAL 11 **************
// https://www.youtube.com/watch?v=k7O7AGfDI2c
// In this tutorial we will be covering:
//  - Friend Classes
//	- Structures
//  - Polymorphism
//  - Abstract Classes
//  - Virtual, Override & Final
//
// ----- STRUCT TUTORIAL -----

#include <iostream>

// Classes have default private fields and methods, while structs have public
// Structs are used to model new data types, while classes model more complex real world objects
struct Shape {
	// Variables are public by default
	double length, width;

	// Constructors are public by default
	Shape(double l = 1, double w = 1) {
		length = l;
		width = w;
	}

	// Structs can also contain functions
	double Area() {
		return length * width;
	}

	// Structs can contain private members
private:
	int ID;
};

// You can inherit a strut from a struct
struct Circle : Shape {
	// Override the constructor
	// You can also do this with structs
	Circle(double width) {
		this->width = width;
	}

	// Override Area()
	double Area() {
		return 3.14159 * std::pow((width / 2), 2);
		// width / 2 = radius
	}
};

int main() {
	// Create a struct
	Shape square(10, 10);

	// Call a Struct function
	std::cout << "Square Area : " << square.Area() << "\n";

	Circle circle(10);
	std::cout << "Circle Area : " << circle.Area() << "\n";

	// You can initialise a struct or a class using an aggregate
	Shape rectangle{ 10, 15 };
	std::cout << "Rectangle Area : " << rectangle.Area() << "\n";

	return 0;
}

// ----- END STRUCT TUTORIAL -----