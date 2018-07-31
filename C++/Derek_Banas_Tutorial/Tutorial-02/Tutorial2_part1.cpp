// ************** TUTORIAL 2 **************
// https://www.youtube.com/watch?v=tT8ICXAO_-4
// In this tutorial we will be covering: 
//  - conditional operators
//  - logical operators
//  - arrays
//  - vectors
//	- strings with stringstream
//
// Conditional Operators & Logical Operators
// Program determines if a user's birthday is important

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main() 
{
    std::string sAge = "0";
    std::cout << "Enter your age : ";
    getline(std::cin, sAge);
    int nAge = std::stoi(sAge); // convert sAge to an integer

    if ((nAge >= 1) && (nAge <= 18))
        std::cout << "Important Birthday\n";
    else if ((nAge == 21) || (nAge == 50))
        std::cout << "Important Birthday\n";
    else if (nAge >= 65)
        std::cout << "Important Birthday\n";
    else
        std::cout << "Not an Important Birthday\n";

    
    return 0;
}