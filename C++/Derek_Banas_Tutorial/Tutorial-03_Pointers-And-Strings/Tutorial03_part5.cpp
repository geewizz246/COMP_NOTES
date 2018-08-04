// Pointers cont'd
//
// Program demonstrates pointers in functions

#include <iostream>

// FUNCTION PROTOTYPES

// Assigns age; takes an int pointer as its parameter
void AssignAge3(int*); 

// END FUNCTION PROTOTYPES

int main() {
    int age = 43;
    AssignAge3(&age); // Pass the address of age into function

    std::cout << "Pointer Age : " << age << "\n";

    
    return 0;
}

// FUNCTION IMPLEMENTATIONS

void AssignAge3(int* pAge) {
    *pAge = 22; // Change the value at the address
}

// END FUNCTION IMPLEMENTATIONS