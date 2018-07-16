// ----- PROBLEM : DYNAMIC LIST DIVISABLE BY A VALUE -----

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

/***********FUNCTION PROTOTYPES***********/

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

/***********END FUNCTION PROTOTYPES***********/


int main() {
	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
	std::cout << "Generated Random Vector : \n";
	for (auto x : vecVals)
		std::cout << x << "\n";

	int divisor;
	std::vector<int> vecVals2;
	std::cout << "\n\nList of values divisible by : ";
	std::cin >> divisor;

	std::copy_if(vecVals.begin(), vecVals.end(),
		std::back_inserter(vecVals2),
		[divisor](int x) { return (x % divisor) == 0; }); // divisor is now part of the capture list

	for (auto x : vecVals2)
		std::cout << x << "\n";

	
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

// ----- END PROBLEM : DYNAMIC LIST DIVISABLE BY A VALUE -----