// Determines the school level of a student based on their age
// Conditions: 
//  - ages <= 5, nursery
//  - ages 6 to 11 inclusive, primary school
//  - ages 12 to 16, secondary school
//  - ages 17 and 18, 6th form / college
//  - ages > 18, university

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string sAge = "0";

    std::cout << "Enter your age : ";
    getline(std::cin, sAge);
    
    int nAge = std::stoi(sAge);
    
    if (nAge <= 5)
        std::cout << "You belong in Nursery.\n\n";
    else if (nAge >= 6 && nAge <= 11)
        std::cout << "You belong in Primary School.\n\n";
    else if (nAge >= 12 && nAge <= 16)
        std::cout << "You belong in Secondary School.\n\n";
    else if (nAge >= 17 && nAge <= 18)
        std::cout << "You belong in 6th Form or College.\n\n";
    else
        std::cout << "You belong in University.\n\n";

    
    return 0;
}