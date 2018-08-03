// ----- PROBLEM 2 : HEADS OR TAILS -----
/* INSTRUCTIONS:
	1. Create a function that creates a random list using a limited number of values.
	2. Create another function that checks for the number of matches in a list.
	3. Create a random list of Hs and Ts and then output how many of each were generated.
*/

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>

// Returns a random list of a predefined size from a list of possible characters supplied
std::vector<char> RandomList(std::vector<char> possible_values, int num_of_values)
{
	srand(time(NULL));
	std::vector<char> ListToGenerate;
	for (int i = 0; i < num_of_values; i++)
	{
		int randIndex = rand() % possible_values.size();
		ListToGenerate.push_back(possible_values[randIndex]);
	}

	return ListToGenerate;
}

// Returns the number of matches of a character found in the list supplied
int CheckForMatches(std::vector<char> list, char value_to_find)
{
	int matches = 0; // Number of matches found
	for (char x : list)
		if (x == value_to_find)
			matches++;

	return matches;
}

int main() {
	std::vector<char> ListOfPossibleValues = { 'H', 'T' };

	std::cout << "Generating list of Heads and Tails....\n\n";
	std::vector<char> RandomisedList = RandomList(ListOfPossibleValues, 100);

	std::cout << "Number of Heads : " << CheckForMatches(RandomisedList, 'H') << "\n";
	std::cout << "Number of Tails : " << CheckForMatches(RandomisedList, 'T') << "\n";


	return 0;
}

// ----- END PROBLEM 2 : HEADS OR TAILS -----