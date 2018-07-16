// ************** TUTORIAL 8 **************
// In this tutorial we will be covering:
//  - Recursion
//  - Factorials
//  - Fibonacci Numbers
//  - Overloaded Functions
//
// ----- RECURSION TUTORIAL -----

#include <iostream>

/***********FUNCTION PROTOTYPES***********/

// Recursive function that returns the factorial of a given number
int Factorial(int num);

/***********END FUNCTION PROTOTYPES***********/


int main() {
    int num;

    std::cout << "Enter a number : ";
    std::cin >> num;

    std::cout << "Factorial : " << Factorial(num) << "\n";
    
    
    return 0;
}


/***********FUNCTION IMPLEMENTATIONS***********/

int Factorial(int num)
{
    if (num == 1)
        return 1;
    
    return num * Factorial(num - 1);
}

/***********END FUNCTION IMPLEMENTATIONS***********/