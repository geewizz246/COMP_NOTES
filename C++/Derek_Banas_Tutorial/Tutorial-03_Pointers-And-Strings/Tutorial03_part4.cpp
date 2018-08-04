// Pointers
//
// Program shows basic operations with pointers

#include <iostream>

int main() {
    int age = 43;
    int* pAge = NULL; // Pointer to an integer; initialised to NULL

    // & ===> Reference operator; returns the address of the variable it preceeds
    pAge = &age; // Store the address of age in pAge

    std::cout << "Address : " << pAge << "\n";

    // * ===> Dereference operator; returns the value being pointed to by the pointer
    std::cout << "Value at Address : " << *pAge << "\n\n\n";

    // We can create a pointer to an array and cycle through
    // the data with ++ and --
    int intArray[] = { 1, 2, 3, 4 };
    int* pIntArray = intArray; // Pointer to an integer; intialised to address of intArray

    std::cout << "1st : " << *pIntArray << ", Address : " << pIntArray << "\n";
    pIntArray++; // Cycle to the next address in the array
    std::cout << "2nd : " << *pIntArray << ", Address : " << pIntArray << "\n";
    pIntArray--; // Cycle to the previous address in the array
    std::cout << "1st : " << *pIntArray << ", Address : " << pIntArray << "\n";

    
    return 0;
}