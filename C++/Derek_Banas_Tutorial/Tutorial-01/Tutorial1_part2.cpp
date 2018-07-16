// Limits
// Program displays the limits of several variable types

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits> // min and max values for various data types

// Some variable names in this tutorial use *Hungarian Notation*
// g_... ===> global variables
// First letter/s indicates its type
// i... ===> integer
// b... ===> bool
// etc.
int g_iRandNum = 0; // global variable (ADVISED AGAINST USING THESE)

const double PI = 3.14159; // Also global but constant. Therefore no way it can
                           // be inadvertedly changed in the program's execution

int main()
{
    bool bMarried = true;
    char chMyGrade = 'A';
    unsigned short int u16Age = 43;
    short int siWeight = 180;
    int nDays = 7;
    long lBigNum = 1100000;
    float fPi = 3.15159;
    double abBigFloat = 1.111111111111111111111;
    long double ldPi = 3.14159;
    auto whatWillIBe = true;

    // Print the minimum and maximum values of variable type bool
    std::cout << "Min bool " << std::numeric_limits<bool>::min() << "\n";
    std::cout << "Min bool " << std::numeric_limits<bool>::max() << "\n\n";

    // Print the minimum and maximum values of variable type char
    std::cout << "Min char " << std::numeric_limits<char>::min() << "\n";
    std::cout << "Min char " << std::numeric_limits<char>::max() << "\n\n";

    // Print the minimum and maximum values of variable type unsigned short int
    std::cout << "Min unsigned short int " << std::numeric_limits<unsigned short int>::min() << "\n";
    std::cout << "Min unsigned short int " << std::numeric_limits<unsigned short int>::max() << "\n\n";

    // Print the minimum and maximum values of variable type short int
    std::cout << "Min short int " << std::numeric_limits<short int>::min() << "\n";
    std::cout << "Min short int " << std::numeric_limits<short int>::max() << "\n\n";

    // Print the minimum and maximum values of variable type int
    std::cout << "Min int " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Min int " << std::numeric_limits<int>::max() << "\n\n";

    // Print the minimum and maximum values of variable type long
    std::cout << "Min long " << std::numeric_limits<long>::min() << "\n";
    std::cout << "Min long " << std::numeric_limits<long>::max() << "\n\n";

    // Print the minimum and maximum values of variable type float
    std::cout << "Min float " << std::numeric_limits<float>::min() << "\n";
    std::cout << "Min float " << std::numeric_limits<float>::max() << "\n\n";

    // Print the minimum and maximum values of variable type double
    std::cout << "Min double " << std::numeric_limits<double>::min() << "\n";
    std::cout << "Min double " << std::numeric_limits<double>::max() << "\n\n";

    // Print the minimum and maximum values of variable type long double
    std::cout << "Min long double " << std::numeric_limits<long double>::min() << "\n";
    std::cout << "Min long double " << std::numeric_limits<long double>::max() << "\n\n";

    
    return 0;
}