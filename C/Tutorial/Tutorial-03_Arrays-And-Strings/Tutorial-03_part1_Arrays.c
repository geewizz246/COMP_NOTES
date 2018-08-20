// ************** TUTORIAL 03 **************
// In this tutorial we will be covering:
//  - Arrays
//  - Multidimensional Arrays
//  - Strings

/* ++++ ARRAYS ++++
---------------------------------------------------------------------------------------------------------------------------
    Arrays are special variables which can hold more than one value of the same type under the same variable name organised 
    with an index.
    Arrays are defined using the following format:
        data_type var_name[size_of_array];
  e.g.  int numbers[10]; <==== array of integers that can hold 10 numbers
    
    To individually populate members of the array:
        var_name[index] = value;
    + NOTE: INDEX VALUES FOR ARRAYS START AT 0. SO AN ARRAY OF SIZE 10 WOULD HAVE INDEXES FROM 0 TO 9. +
  e.g.  numbers[0] = 8;
        numbers[3] = 12;
        numbers[10] = 67; <==== ERROR! numbers[10] IS NOT AN ACCESSIBLE INDEX
*/

#include <stdio.h>

int main() {
    // When defining an array, you can leave the [] brackets empty i.e. not define a size.
    // However, you would need to initialise the array with values if you do so.
    int numbers[] = { 12, 23, 42, 105, 97 };

    // Printing values of an array
    printf("%d, %d, %d, %d, %d\n",
        numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);

    // Changing a value through user input
    printf("Enter a new first value for the int array : ");
    // Accessing individual members of an array requires you to put & before the variable name
    scanf("%d", &numbers[0]);

    printf("%d, %d, %d, %d, %d\n",
        numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]/*, numbers[5]*/);
        // Once again, numbers[5] would cause an error since that index is out of range


    return 0;
}

// ++++ END ARRAYS TUTORIAL ++++