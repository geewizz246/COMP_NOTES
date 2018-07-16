// Arrays 
// NB - Once the size of an array has been decided, IT CANNOT CHANGE
// Therefore, arrays in C++ are NOT resizable
//
// Program playing around with arrays

#include <cstdlib>
#include <iostream>

int main()
{
    // Declaring and initialising arrays
    int arrNums1[10] = { 1 }; // Size = 10. Initailised with value '1' at position 0

    int arrNums2[] = { 1, 2, 3 }; // Size not declared. However, since 3 values were used
                                  // to initialise the array, it adopts 3 as its size
    
    int arrNums3[5] = { 8, 9 }; // Size = 5. Initialised with 2 values.

    std::cout << "1st Value : " << arrNums3[0] << "\n";
    arrNums3[0] = 7; // Change the value of the 1st value in arrNums3 to 7
    std::cout << "1st Value : " << arrNums3[0] << "\n";

    //sizeof ===> returns the size in bytes of the variable
    std::cout << "Array size : " 
        << sizeof(arrNums3) /* size of the entire int array (5 * 4 bytes) */ 
        / sizeof(*arrNums3) /* size of the array type in the first location - int = 4 bytes*/
        << "\n";

    //Multi-dimensional Arrays
    int arrNums4[2][2][2] = { {{1, 2}, {3, 4}},
                            {{5, 6}, {7, 8}} }; // A three-dimensional array

    std::cout << arrNums4[0][0][1] << "\n\n"; // Prints 2

    
    return 0;
}
