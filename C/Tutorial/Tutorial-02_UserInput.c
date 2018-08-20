// ************** TUTORIAL 02 **************
// User Input and the Scanf Function

// The scanf function is used to read formatted input from stdin
// scanf format is:
//      scanf("format string", &list, &of, &addresses, &of, &variables);
// Putting '&' in front of a variable name returns its address in memory
// You MUST put & in front of the variables used in scanf.
// (NB - the exception would be arrays - including strings - since arrays in C already have
// built-in pointers to their address in memory)

#include <stdio.h>

int main() {
    int age = 0;
    float height = 0, weight = 0;

    // scanf mostly uses the same format tags as as printf for variable types.
    // For more info : https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
    printf("Enter your age : ");
    scanf("%d", &age);

    // You can receive multiple inputs in one scanf statement
    printf("Enter your height and weight : ");
    scanf("%f%f", &height, &weight);

    printf("Age : %d\n"
        "Height : %.2f\n"
        "Weight : %.2f\n",
        age, height, weight);

    return 0;
}