// ************** TUTORIAL 1 **************
// In this tutorial, we will be covering:
//	- commonly used libraries
//	- command line arguments for main()
//	- limits
//  - working with strings
//		> conversion of strings to other types
//  - using printf statements
//
// Commonly used libraries and command line arguments for main()

#include <cstdlib>  // contains general purpose functions such as for converting variable types, 
                    // random number generators, memory management, searching, sorting etc.
#include <iostream> // input and output operations
#include <string>
#include <vector>
#include <sstream> // contains functions for manipulating strings

// int argc ===> number of arguments entered at the command line (in command prompt).
// By default, the number of arguments is 1 - that being the path name (or just name)
// of the program.
// char** argv ===> array of character arrays (strings) containing each argument
// entered at the command prompt.
int main(int argc, char** argv)
{
    std::cout << "Hello World\n";

    if (argc != 1) // if number of arguments is not 1
    {
        std::cout << "You entered " << argc << "arguments\n";
    }

    // Print out each argument
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}