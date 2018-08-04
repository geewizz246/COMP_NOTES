// ************** TUTORIAL 4 **************
// https://www.youtube.com/watch?v=HD72quXVuE4
// In this tutorial we will be covering:
//  - While
//  - Break & Continue
//  - Do While
//  - Exception Handling
//
// While Loops, Continue and Break

#include <iostream>
#include <vector>

int main() {
    // ----- WHILE / BREAK / CONTINUE -----
    // While loops continue to run the code in them
    // as long as a condition is true

    // Create the variable used in the while condition
    // before the while loop
    int i = 1;

    while (i <= 20)
    {
        // If a value is even don't print it
        if ((i % 2) == 0)
        {
            i += 1;

            // Continue skips the rest of the code
            // and jumps back to the beginning
            // of the loop
            continue;
        }

        // Break stops execution of the loop and jumps 
        // to the line after the loops closing }
        if (i == 15)
            break;

        std::cout << i << '\n';

        i += 1;
    }

    
    return 0;
}