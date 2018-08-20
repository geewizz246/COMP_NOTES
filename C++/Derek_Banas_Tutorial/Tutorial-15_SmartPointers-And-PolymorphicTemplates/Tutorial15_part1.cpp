// ************** TUTORIAL 15 **************
// https://youtu.be/q_LUYLV3l44
// In this tutorial we will be covering:
//  - Smart Pointers
//  - Malloc
//  - Polymorphic Templates
//
// ----- MALLOC TUTORIAL -----

#include <iostream>

int main() {
    // NB:
    //   malloc() ====> Allocates a block of size bytes of memory, returning a 
    //   pointer to the beginning of the block.

    // When you define a primitive type like int or float you define exactly 
    // the amount of space to set aside

    // If you need to define how much space to set aside you could call malloc() 
    // and tell it how much space to set aside and it returns the address to
    // that memory address

    int amtToStore;
    std::cout << "How many numbers do you want to store : ";
    std::cin >> amtToStore;

    // Create an int pointer and set aside enough space
    int * pNums;

    // Cast the pointer and define how much space to set aside
    pNums = (int *) malloc(amtToStore * sizeof(int));

    // Check if memory was allocated
    if (pNums != NULL)
    {
        int i = 0;

        // Store values
        while (i < amtToStore)
        {
            std::cout << "Enter a Number : ";
            std::cin >> pNums[i];
            i++;
        }
    }

    std::cout << "You entered these numbers\n";
    for(int i = 0; i < amtToStore; i++)
        std::cout << pNums[i] << "\n";

    // Delete the pointer
    delete pNums;

    return 0;
}

// ----- END MALLOC TUTORIAL -----