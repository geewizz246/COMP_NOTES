/* ++++ STRINGS ++++
---------------------------------------------------------------------------------------------------------------------------
    Strings in C are arrays of characters. We can define simple strings by using pointers to a character array.
    (Pointers will be explained in a later tutorial.)
        char * name = "John Smith";
    This method creates a string that can only be used for reading.

    To define a string that can be manipilated, define it as a character array:
        char name[] = "John Smith";
    This allocates an array variable so we can manipulate it. The empty brackets [] tells the compiler to calculate the size
    of the array automatically.

        char name[] = "John Smith";
        // is the same as
        char name[11] = "John Smith";

    Note that "John Smith" is 10 characters long but the string size is given as 11. This is because each string has a
    string terminator or null terminator (\0): a special character (equal to 0) which indicates the end of the string. The end
    of the string is marked because the program does not know the length of the string - only the compiler knows it. The string 
    size, therefore, has to accommodate for this special character, so "John Smith" is really "John Smith\0".

*/

#include <stdio.h>
#include <string.h> // Include this library when using special string functions.
// There are many string functions, some of which are detailed at:
//  - https://www.tutorialspoint.com/c_standard_library/string_h.htm
//  - http://www.cplusplus.com/reference/cstring/

int main() {
    char * name = "John Smith";
    int age = 27;

    // Formating a string with printf
    printf("%s is %d years old.\n", name, age);

    // String Length
    // The function strlen returns the length of the string which has to be passed as an argument
    printf("Size of string \'name\' = %d\n", strlen(name));

    // String Comparison
    // The function strncmp compares between two strings, returning the number 0 if they are equal, or a different number
    // if they are different. The arguments are the two strings to be compared, and the maximum comparison length.
    // Note that there is a strcmp function that is similar but it is considered somewhat unsafe. If one of the strings is
    // missing the string terminator, it could crash the program
    
    char * person = "George";

    if (strncmp(person, "George", 6) == 0) {
        printf("Hello, George!\n");
    } else {
        printf("Umm I don't know you...\n");
    }

    // String Concatenation
    // The function strncat appends the first n characters of the source string to the destination string,
    // where n is the maximum number of characters to be appended.
    // Note that the destination string has to be large enough to accommodate the size of the appended string.
    // There is also another function - strcat - that does not require an n value, but is considered somewhat unsafe for similar
    // reasons as strcmp. A missing string terminator in the string could cause a buffer overflow and cause the program to crash.
    
    char dest[10] = "Nin"; // destination string 
    char src[] = "tendo"; // string to be appended
    strncat(dest, src, 3); // dest = "Ninten"
    printf("%s\n", dest);

    // String Copying
    // The function strncpy copies the first n characters of the source string and replaces the destination string
    // with what was copied.
    // Again, remember that the destination string must be large enough to accommodate the size of the copied string.
    // The other function, strcpy, is considered somewhat unsafe for the same reasons as strcmp.
    
    char food[10] = "tuna";
    strncpy(food, "cheese", 6);
    printf("%s\n", food);

    // int snprintf ( char * s, size_t n, const char * format, ... );
    // Write formatted output to sized buffer
    // Composes a string with the same text that would be printed if format was used on printf, but instead of being 
    // printed, the content is stored as a C string in the buffer pointed by s (taking n as the maximum buffer capacity to fill).
    // If the resulting string would be longer than n - 1 characters, the remaining characters are discarded and not stored, but 
    // counted for the value returned by the function.
    // A terminating null character is automatically appended after the content written.
    // After the format parameter, the function expects at least as many additional arguments as needed for format.
    // Note there is an sprintf function, but... you know.

    char buffer[100];
    int n = // The functuon returns the size of the resulting string
        snprintf(buffer, 100, "%s is %d years old.\nHis favourite food is %s.", name, age, food); 

    printf("%s\nSize of resulting string = %d\n", buffer, n);


    return 0;
}

// ++++ END STRINGS TUTORIAL ++++