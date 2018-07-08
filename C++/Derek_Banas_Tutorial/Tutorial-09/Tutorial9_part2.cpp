// ----- LAMBDA EXPRESSIONS TUTORIAL CONT'D -----

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> // std::sort

/***********FUNCTION PROTOTYPES***********/

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

/***********END FUNCTION PROTOTYPES***********/


int main() {
	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);

	// ----- MULTIPLY ALL VALUES -----
	std::cout << "Vector before multiplication :\n";
	for (auto x : vecVals)
		std::cout << x << "\n";

	std::vector<int> doubleVec;
	int multiplier;

	std::cout << "Multiply vector by : ";
	std::cin >> multiplier;

	std::for_each(vecVals.begin(), vecVals.end(),
		[multiplier, &doubleVec](int x) // capture multiplier by copy
										// capture doubleVec by reference
	{ doubleVec.push_back(x * multiplier); });

	std::cout << "\n\nVector after multiplication :\n";
	for (auto x : doubleVec)
		std::cout << x << "\n";

	// ----- END MULTIPLY ALL VALUES -----

	system("Pause");
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