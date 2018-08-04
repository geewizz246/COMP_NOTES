// ************** TUTORIAL 12 **************
// https://youtu.be/gc7Eqba1c5g
// In this tutorial we will be covering:
//  - Operator Overloading
//	- File I/O
//
// ----- OPERATOR OVERLOADING TUTORIAL -----

#include <iostream>
#include <string>
#include <sstream> // std::ostringstream

// Create a custom Box class with overloaded operators
class Box {
public:
	double length;
	double width;
	double breadth;
	std::string boxString; // Used to hold a string representation of a box

	Box() 
	{
		length = 1, width = 1, breadth = 0;
	}

	Box(double l, double w, double b)
	{
		length = l, width = w, breadth = b;
	}

	// You can define custom operators just like
	// you define functions
	// This is a unary operator because it operates
	// on 1 object
	// Other Unary Operators : --, *(pointer dereference),
	// -> (Member Selection), !, & (Address of), +, -
	Box& operator ++ () {
		length++;
		width++;
		breadth++;
		return *this;
	}

	// Creates a C string representation which is a
	// pointer to an array that is null terminated
	operator const char* () {
		// Creates a stream that can be loaded with 
		// characters that can then be accessed as
		// a string object
		std::ostringstream boxStream;
		boxStream << "Box : "
			<< length << ", "
			<< width << ", "
			<< breadth;

		// Return a string representation of the stream
		boxString = boxStream.str();

		// Returns the pointer to the string array
		return boxString.c_str();
	}

	// Binary operators operate on 2 objects
	// +, -, *, /, %, ==, !=, >, <, >=, <=, &&, ||, 
	// !, =, +=, -=, *=, /=, ^, [], &, |

	// Adding boxes
	Box operator + (const Box& box2) {
		Box boxSum;
		boxSum.length = length + box2.length;
		boxSum.width = width + box2.width;
		boxSum.breadth = breadth + box2.breadth;
		return boxSum;
	}

	// Access items using the subscript operator
	double operator [] (int x) {
		if (x == 0)
			return length;
		else if (x == 1)
			return width;
		else if (x == 2)
			return breadth;
		else
			return -1; // Doesn't exist
	}

	// Check for box equality
	bool operator == (const Box& box2) {
		return ((length == box2.length)
			&& (width == box2.width)
			&& (breadth == box2.breadth));
	}

	bool operator > (const Box& box2) {
		double thisSize = length + width + breadth;
		double box2Size = box2.length + box2.width + box2.breadth;

		if (thisSize > box2Size)
			return true;
		else
			return false;
	}

	// Overload the assignment operator
	void operator = (const Box& boxToCopy) {
		length = boxToCopy.length;
		width = boxToCopy.width;
		breadth = boxToCopy.breadth;
	}
};


int main() {
	Box box(10, 10, 10);

	// Will increment all values in the box by 1
	++box;
	std::cout << box << "\n";

	// Add boxes
	Box box2(5, 5, 5);
	std::cout << "Box1 + Box2 = "
		<< box + box2 << "\n";

	// Access data with subscript operator
	std::cout << "Box length : "
		<< box[0] << "\n";

	// Displays true or false for booleans
	std::cout << std::boolalpha;
	std::cout << "Are boxes equal : "
		<< (box == box2) << "\n";

	// Is box < box2
	std::cout << "Is box < box2 : "
		<< (box < box2) << "\n";

	// Is box > box2
	std::cout << "Is box > box2 : "
		<< (box > box2) << "\n";

	// Assign box2 to box
	box = box2;
	std::cout << box << "\n";

	return 0;
}

// ----- END OPERATOR OVERLOADING TUTORIAL -----