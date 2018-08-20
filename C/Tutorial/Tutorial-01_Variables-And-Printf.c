// ************** TUTORIAL 01 **************
// Variables and the Printf Function

/* C VARIABLES
----------------------------------------------------------------------------------------
    C has several types of variables, but there are a few basic types:
    * Integers - whole numbers which can be either positive or negative. Defined using:
    - char
    - int
    - short
    - long
    - long long

    * Unsigned integers - whole numbers which can only be positive. Defined using:
    - unsigned char
    - unsigned int
    - unsigned short
    - unsigned long
    - unsigned long long

    * Floating point numbers - real numbers (numbers with fractions). Defined using:
    - float
    - double

    * Structures - will be explained later

    C does NOT have a boolean type. It is usually defined using the following notation:
    #define BOOL char
    #define FALSE 0
    #define TRUE 1
*/

#include <stdio.h>



int main() {
    // Variables are declared in the following format:
    //      datatype name;
    // You can also initialise variables when you create them;
    //      int num = 5;
    int age;
    float weight;
    char sex;

    // You can create multiple variables of the same type at once
    int a = 0, b = 1, c = 2, 
        d = 3, e = 4;

    // Assigning values to variables
    age = 23;
    weight = 50.5;
    sex = 'M';

    // Printing out variables
    // You can combine embedded format tags that are replaced by the values specified
    // in subsequent additional arguments and formatted as requested.
    // Format tags are in the format:
    //  %[flags][width][.precision][length]specifier
    // Some basic examples are:
    //      - %c ====> character
    //      - %d or %i ====> signed decimal integer
    //      - %u ====> unsigned decimal character
    //      - %f ====> decimal floating point
    //      - %s ====> string of characters
    //      - %p pointer address
    //      - %x ====> unsigned hexadecimal integer (%X for capital letters)
    //      - %o ====> signed octal
    // For more info : https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

    // Remember the printf format is:
    //      printf("format string", list, of, variables, ...);
    printf("%d %.2f %c\n", age, weight, sex);
    // %.2f sets the number of digits to be written after the decimal point

    // With printf there are also a number of escape sequences we can use to output special characters:
    //      - \a ====> alert
    //      - \b ====> backspace
    //      - \f ====> formfeed
    //      - \n ====> newline
    //      - \t ====> horizontal tab
    //      - \v ====> vertical tab
    //      - \\ ====> backslash
    //      - \' ====> single quotation mark
    //      - \" ====> double quotation mark
    //      - \? ====> question mark
    printf("\a\tLet's play around \n"
        "\twith \"escape characters\", yeah\?\n");

    return 0;
}