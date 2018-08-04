// ----- PROBLEM : PRINT ARRAY HORIZONTALLY -----
/* EXAMPLE
 ---------------
 |  0 |  1 |  2 |
 ---------------
 | 10 |  8 |  2 |
 ---------------
*/

#include <iostream>
#include <vector>

/***********FUNCTION PROTOTYPES***********/

// Prints int vector in horizontal format
void PrintHorzVector(std::vector<int>&);

/***********END FUNCTION PROTOTYPES***********/


int main() {
    std::vector<int> aVec = { 10, 20, 30, 8, 5, 35, 28, 62, 9, 0 };
    PrintHorzVector(aVec);

    
    return 0;
}


/***********FUNCTION IMPLEMENTATIONS***********/

void PrintHorzVector(std::vector<int>& theVec)
{
    int dashes = theVec.size() * 5;

    for (int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";

    for (int n = 0; n < theVec.size(); n++)
        printf("| %2d ", n);
    std::cout << "|\n";

    for (int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";

    for (int n = 0; n < theVec.size(); n++)
        printf("| %2d ", theVec[n]);
    std::cout << "|\n";

    for (int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";
}

/***********END FUNCTION IMPLEMENTATIONS***********/

// ----- END PROBLEM : PRINT ARRAY HORIZONTALLY -----