// ----- SMART POINTER TUTORIAL -----
// A Smart pointer is a class that provides the power of pointers, but also handles 
// the reallocation of memory when it is no longer required (the pointer is 
// automatically destroyed).

#include <iostream>
#include <vector>
#include <string>

int main() {
    int amtToStore;
    std::cout << "How many numbers do you want to store : ";
    std::cin >> amtToStore;

    // Smart Pointer Solution
    // This memory will be automatically reallocated
    std::unique_ptr<int[]> pNums(new int[amtToStore]);

    // std::unique_ptr can only have ONE OWNER
    // so this throws an error
    // std::unique_ptr<int[]> pNums2 = pNums;
    // However, this can be done with shared_ptr, which will be covered in a later tutorial

    if (pNums != NULL)
    {
        int i = 0;

        while (i < amtToStore)
        {
            std::cout << "Enter a Number : ";
            std::cin >> pNums[i];
            i++;
        }
    }

    std::cout << "You entered these numbers\n";
    for (int i = 0; i < amtToStore; i++)
        std::cout << pNums[i] << "\n";

    return 0;
}

// -----  END SMART POINTER TUTORIAL -----