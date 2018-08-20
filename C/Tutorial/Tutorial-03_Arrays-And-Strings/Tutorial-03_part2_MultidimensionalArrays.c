/* ++++ MULTIDIMENSIONAL ARRAYS ++++
---------------------------------------------------------------------------------------------------------------------------
    In C we can create and use multidimensional arrays
    The general format of a multidimensional array declaration:
        data_type var_name[size1][size2]...[sizeN];
  e.g.  int foo[3][4][5];
      
  e.g.  int numTable[4][3] = {
            { 2, 3, 5 },
            { 4, 6, 10 },
            { 6, 9, 15 },
            { 8, 12, 20 }
        };

  e.g.  char vowels[1][5] = {
            {'a', 'e', 'i', 'o', 'u'}   <==== This one could have just been one-dimensional (char vowels[5])
        };

    ~ Two-Dimensional Arrays~
    The simplest form of multidimensional array is the two-dimensional array.
    You can think of this as a list of one-dimensional arrays.
    It can also be considered a table which will have [x] number of rows and [y] number of columns.
        data_type var_name[x][y];
    For instance, a two-dimensional array b[3][4] could be represented like this:

                Column 0    Column 1    Column 2    Column 3
              -------------------------------------------------
      Row 0   |  b[0][0]  |  b[0][1]  |  b[0][2]  |  b[0][3]  |
              -------------------------------------------------
      Row 1   |  b[1][0]  |  b[1][1]  |  b[1][2]  |  b[1][3]  |
              -------------------------------------------------
      Row 2   |  b[2][0]  |  b[2][1]  |  b[2][2]  |  b[2][3]  |
              -------------------------------------------------

    In this sense, every element in the array b is identified by an element name in the form b[x][y], where
    'b' is the name of the array, and 'i' and 'j' are the indexes that uniquely identify each element in 'b'.

    You don't need to put the [x] value (i.e. the num of rows), because if you initialise it like this:
        char vowels[][5] = {
            { 'A', 'E', 'I', 'O', 'U' },
            { 'a', 'e', 'i', 'o', 'u' },
        };
    the compiler would already know that there are two "dimensons". However, ALWAYS give a [y] value.
*/


#include <stdio.h>

int main() {
    // Initialising a two-dimensional array
    int numTable[4][3] = {
        { 2, 3, 4},     // initialisers for row indexed by 0
        { 4, 6, 8},     // initialisers for row indexed by 1
        { 6, 9, 12},    // initialisers for row indexed by 2
        { 8, 12, 16}    // initialisers for row indexed by 3
    };

    // However the inside braces, which indicate the wanted row, are optional.
    // The following initialisation is the same as the previous example
    //      int numTable = { 2, 3, 4, 4, 6, 8, 6, 9, 12, 8, 12, 16 };

    // Accessing individual two-dimensional array members
    int val = numTable[0][4]; // val = 4
    int a = numTable[0][1] * numTable[2][1]; // a = 3 * 9 = 27

    printf("Val = %d\na = %d\n",
        val, a);


    return 0;
}

// ++++ END MULTIDIMENSIONAL ARRAYS TUTORIAL ++++