// ----- TERNARY OPERATOR -----

#include <iostream>

int main() {
	int age = 43;
	bool canIVote = (age >= 18) ? true : false;
	
	// Set std::cout to display boolean values as their
	// string equivalents (true or false vs 1 or 0)
	std::cout.setf(std::ios::boolalpha);
	std::cout << "Can I vote : " << canIVote << "\n";

	
	return 0;
}

// ----- END TERNARY OPERATOR -----