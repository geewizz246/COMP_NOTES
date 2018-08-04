// Prints the even numbers in a vector.
// Vector consists of numbers from 1 to 10 inclusive.

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> myVec(10);
    std::iota(std::begin(myVec), std::end(myVec), 1); // populate myVec with values from 1 to 10

    // Cycle through myVec and print the even numbers
    std::cout << "Even numbers: ";
    for (auto num : myVec)
    {
        if (num % 2 == 0)
            std::cout << num << "  ";
    }
    std::cout << "\n\n";

    
    return 0;
}