// ----- LAMBDA EXPRESSIONS TUTORIAL CONT'D -----

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> // std::sort

/***********FUNCTION PROTOTYPES***********/

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

/***********END FUNCTION PROTOTYPES***********/


int main() {
	
	// ----- PERFORMING OPERATIONS USING MULTIPLE VECTORS -----
	// Add values in separate vectors and save them to another

	std::vector<int> vec1 = { 1,2,3,4,5 };
	std::vector<int> vec2 = { 1,2,3,4,5 };
	std::vector<int> vec3(5);
	transform(vec1.begin(), vec1.end(),
		vec2.begin(), vec3.begin(),
		[](int x, int y) {return x + y; });

	std::cout << "vec3 :\n";
	for (auto val : vec3)
		std::cout << val << "\n";

	// ----- END PERFORMING OPERATIONS USING MULTIPLE VECTORS -----

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

// ----- END LAMBDA EXPRESSIONS TUTORIAL -----