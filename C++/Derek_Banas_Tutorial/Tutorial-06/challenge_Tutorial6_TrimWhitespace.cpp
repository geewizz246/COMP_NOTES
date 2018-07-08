// ----- PROBLEM 3. STRIP WHITESPACE -----

#include <iostream>
#include <string>

std::string TrimWhitespace(std::string);

int main() {
    std::string aStr = "       Just some random words       \n\n";
    aStr = TrimWhitespace(aStr);

    std::cout << "*" << aStr << "*\n";
	
	system("Pause");
	return 0;
}

std::string TrimWhitespace(std::string theString)
{
    std::string whitespaces(" \t\f\n\r");

    // find_last_not_of finds the last character
    // that doesn't match a list of defined characters
    theString.erase(theString.find_last_not_of(whitespaces) + 1);

    // find_first_not_of does the same for the front of the string
    theString.erase(0, theString.find_first_not_of(whitespaces));

    return theString;
}