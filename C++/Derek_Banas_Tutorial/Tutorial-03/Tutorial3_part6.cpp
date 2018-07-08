// Pointers cont'd
// Pointers and arrays
// Program demonstrates pointers in functions

#include <iostream>

// FUNCTION PROTOTYPES

// Doubles each member of the integer array
void DoubleArray(int* arr, int size);

// END FUNCTION PROTOTYPES

int main() {
    int arr[] = { 1, 2, 3, 4 };
    DoubleArray(arr, 4);
    for (int i = 0; i < 4; ++i)
        printf("arr[%d] : %d\n", i, arr[i]);

    system("Pause");
    return 0;
}

// FUNCTION IMPLEMENTATIONS

void DoubleArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = arr[i] * 2;
}

// END FUNCTION IMPLEMENTATIONS