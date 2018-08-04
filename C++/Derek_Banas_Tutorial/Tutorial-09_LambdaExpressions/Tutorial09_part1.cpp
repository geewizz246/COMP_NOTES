// ************** TUTORIAL 9 **************
// https://www.youtube.com/watch?v=482weZjwVHY
// In this tutorial we will be covering:
//  - Lambda Expressions
//  - Sort
//  - Copy_If
//  - For_Each
//	- Transform
//	- Recursive Lambda Functions and Problems
//
// ----- LAMBDA EXPRESSIONS TUTORIAL -----

#include <iostream>
#include <vector>
#include <ctime> // Needed for random number generation
#include <algorithm> // std::sort, std::for_each

/***********FUNCTION PROTOTYPES***********/

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

/***********END FUNCTION PROTOTYPES***********/


int main() {
	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);

	std::cout << "Vector before sort:\n";
	for (auto x : vecVals)
		std::cout << x << "\n";

	// Lambda Expressions make it easy to perform list
	// operations in one line of code. You designate
	// them with []
	// Here we sort a vector
	std::sort(vecVals.begin(), vecVals.end(),
		[](int x, int y) { return x < y; }); // Sort in ascending order
											 // To sort descending, return x > y

	std::cout << "\n\nVector after sort:\n";
	for (auto x : vecVals)
		std::cout << x << "\n";

	// copy_if works like filter does in other languages
	// Here we keep only even values in a new vector
	// PLEASE NOTE : an enclosing-function local variable cannot be 
	// referenced in a lambda body unless it is in the capture list
	// [] ===> empty capture list
	std::vector<int> evenVecVals;

	std::copy_if(vecVals.begin(), vecVals.end(), 
		std::back_inserter(evenVecVals),
		[](int x) { return (x % 2) == 0; });

	std::cout << "\n\nEven Vector Values:\n";
	for (auto x : evenVecVals)
		std::cout << x << "\n";

	// ----- SUM A LIST -----
	int sum = 0;

	// for_each cycles through all values
	// [&] captures all variables used
	// in the body of the lambda by reference
	std::for_each(vecVals.begin(), vecVals.end(),
		[&](int x) {sum += x; });

	std::cout << "\n\nSum of vecVals : " << sum << "\n";

	// ----- END SUM A LIST -----


	return 0;
}


/***********FUNCTION IMPLEMENTATIONS***********/

std::vector<int> GenerateRandVec(int numOfNums, int min, int max) 
{
	std::vector<int> vecValues;

	// Seed the random number generator
	srand(time(NULL));

	int i = 0, randVal = 0;

	while (i < numOfNums) 
	{
		// The min added on increases result based on min
		// The remainder of modulus can't be greater
		// then the divisor. We have to adjust down
		// based on the addition from min
		randVal = min + std::rand() % ((max + 1) - min);
		vecValues.push_back(randVal);
		i++;
	}
	return vecValues;
}

/***********END FUNCTION IMPLEMENTATIONS***********/