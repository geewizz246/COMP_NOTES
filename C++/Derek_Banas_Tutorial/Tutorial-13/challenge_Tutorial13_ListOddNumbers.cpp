// ----- PROBLEM 1 : LIST ODD NUMBERS -----
// Create a function that receives a list and a function.
// The function passed will return True or False if a list value is odd.
// The surrounding function will return a list of odd numbers.

#include <iostream>
#include <vector>
#include <functional>

// Determines if a value is odd
bool IsOdd(int num)
{
	if (num % 2 != 0)
		return true;
	else
		return false;
}

// Returns a list of odd numbers
std::vector<int> OddNumbers(std::vector<int> list, std::function<bool(int)> isOdd)
{
	std::vector<int> oddNums;
	for (int i = 0; i < list.size(); i++)
		if (isOdd(list[i]))
			oddNums.push_back(list[i]);
	
	return oddNums;
}

int main() {
	std::vector<int> numbers = { 12, 83, 4, 7, 49, 0, 32, 45 },
		listOfOdds = OddNumbers(numbers, IsOdd);

	std::cout << "Odd Numbers : ";
	for (auto x : listOfOdds)
		std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}

// ----- END PROBLEM 1 : LIST ODD NUMBERS -----