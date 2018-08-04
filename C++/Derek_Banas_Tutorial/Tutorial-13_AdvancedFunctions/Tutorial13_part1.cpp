// ************** TUTORIAL 13 **************
// https://youtu.be/TGOXttOoI0U
// In this tutorial we will be covering:
//  - Passing Functions to Functions
//	- Vectors of Functions
//
// ----- BEGINNING OF TUTORIAL -----

#include <iostream>
#include <vector>
#include <functional> // std::function

// 1. Created to store as a variable and to pass into other functions
// Takes in a number and returns the value multiplied by 2
double MultBy2(double num) { return num * 2; }

// 2. Functions can receive other functions.
//    The first double is the return type followed by the data types for the parameter/s
// Performs predefined math operations and returns the result
double DoMath(std::function<double(double)> func, double num) {
	return func(num);
}

// Takes in a number and returns the value multiplied by 3
double MultBy3(double num) { return num * 3; }

int main() {
	// 1. You can store functions as variables
	auto times2 = MultBy2;
	std::cout << "5 * 2 = " << times2(5) << "\n";

	// 2. Pass a function into a function
	std::cout << "6 * 2 = " << DoMath(MultBy2, 6) // or DoMath(times2, 6)
		<< "\n";

	// 3. You can store functions in a vector.
	// Create a vector using the function parameters and then load the functions 
	// into the vector
	std::vector<std::function<double(double)>> funcs(2);
	funcs[0] = MultBy2;
	funcs[1] = MultBy3;

	std::cout << "2 * 10 = " << funcs[0](10) << "\n";
	std::cout << "3 * 10 = " << funcs[1](10) << "\n";

	return 0;
}

// ----- END OF TUTORIAL -----