// Functions
//
// Program introducing concept of functions

#include <iostream>
#include <string>

// FUNCTION PROTOTYPES

// Returns result of adding two numbers
double AddNumbers(double num1, double num2);

// END FUNCTION PROTOTYPES

int main() {
    double num1, num2;

    std::cout << "Enter Num 1 : ";
    std::cin >> num1;
    std::cout << "Enter Num 2 : ";
    std::cin >> num2;

    // std::cout << num1 << " + " << num2 << " = " 
    //     << AddNumbers(num1, num2) << '\n';

    
    printf("%.1f + %.1f = %.1f\n",
    num1, num2, AddNumbers(num1, num2));

    // AddNumbers(num1, num2) returns the result of adding
    // num1 and num2

    
    return 0;
}

// FUNCTION IMPLEMENTATIONS

double AddNumbers(double num1, double num2) {
    return num1 + num2;
}

// END FUNCTION IMPLEMENTATIONS