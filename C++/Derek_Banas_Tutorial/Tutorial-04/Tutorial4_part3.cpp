// Exception Handling
// 
// Example 2

#include <iostream>
#include <vector>

int main() {
    // ----- EXCEPTION HANDLING EX 2 -----

    try {
        std::cout << "Throwing exception\n";
        
        // Another way to throw an exception
        throw std::runtime_error("Error Occured");

        // This point is never reached
        std::cout << "Can you print me?";
    }

    // All exceptions are based on std::exception
    catch (std::exception &exp) {

        // what() ===> Prints an explanatory string
        std::cout << "Handled Exception : " <<
            exp.what() << "\n";
    }

    // catch (...) ===> Catch all exceptions
    // If exceptions aren't caught any place else 
    // this will catch it
    catch (...) {
        std::cout << "Default exception catch\n";
    }

    // ----- END OF EXCEPTION HANDLING EX 2 -----

    
    return 0;
}