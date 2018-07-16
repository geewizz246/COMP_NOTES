// ----- PROBLEM : GENERATE FIBONACCI NUMBER -----

#include <iostream>

/***********FUNCTION PROTOTYPES***********/

// Recursive fibonacci function
int fib(int num);

/***********END FUNCTION PROTOTYPES***********/


int main() {
    int index;
    std::cout << "Enter Fibonacci Index : ";
    std::cin >> index;

    printf("Fib(%d) : %d\n", index, fib(index));

    
    return 0;
}



/***********FUNCTION IMPLEMENTATIONS***********/

int fib(int num)
{
    if (num == 1 || num == 0)
        return num;

    return fib(num - 1) + fib(num - 2);
}

/***********END FUNCTION IMPLEMENTATIONS***********/

// ----- END PROBLEM : GENERATE FIBONACCI NUMBER -----