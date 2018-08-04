#include <iostream>
#include <string>
#include <vector>

int main() {
    // ----- PROBLEM : SECRET STRING -----
    // Receive an uppercase string and hide its meaning
    // by turning it into ascii codes
    // Translate it back to the original letters

    std::string upStr, secretStr;

    std::cout << "Enter an uppercase string : ";
    std::cin >> upStr;

    // Cycle through the string, changing each character to
    // its equivalent ASCII code
    for (char x : upStr)
    {
        secretStr += std::to_string(int(x));
    }

    std::cout << "Secret string : " << secretStr << "\n";

    // Convert secretStr back to the original string
    std::string originalStr; 

    // Cycle through numbers in string 2 at a time
    for (int i = 0; i < secretStr.size(); i += 2)
    {
        // Get the 2 digit ascii code
        std::string sCharCode = "";
        sCharCode += secretStr[i];
        sCharCode += secretStr[i + 1];
        
        // Convert the string to an int
        int iCharCode = std::stoi(sCharCode);

        // Convert the int to a char
        char cCharCode = iCharCode;

        // Add the character to originalStr
        originalStr += cCharCode;
    }

    std::cout << "Original string : " << originalStr << "\n";

    // ----- END OF PROBLEM : SECRET STRING -----

    // ----- BONUS PROBLEM -----
    // Allow the user to enter upper and lowercase
    // letters by subtracting and adding 1 value
    // ----- END OF BONUS PROBLEM -----

    
    return 0;
}