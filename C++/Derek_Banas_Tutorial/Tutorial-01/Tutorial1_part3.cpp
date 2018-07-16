// Working with strings
// Program converts strings into numbers

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main()
{
    std::string sQuestion("Enter Number 1 : "); // Initialise sQuestion
    std::string sNum1, sNum2;
    
    std::cout << sQuestion;
    getline(std::cin, sNum1);
    
    std::cout << "Enter Number 2 : ";
    getline(std::cin, sNum2);

    // Convert strings sNum1 and sNum2 to integers
    int nNum1 = std::stoi(sNum1);
    int nNum2 = std::stoi(sNum2);

    // Print using a printf statement (part of <cstdlib> library)
    printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2)); // %% just prints one %

    
    return 0;
}