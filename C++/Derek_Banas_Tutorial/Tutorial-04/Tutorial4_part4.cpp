// Do While Loops
//
// Program makes user guess a random number until they are correct

#include <iostream>
#include <vector>
#include <ctime> // Needed for time functions

int main() {
    // ----- DO WHILE LOOPS -----

    // Needed for the time function

    // Do while loops are guaranteed to execute at least once
    // We'll create a secret number guessing game

    // Generate random number from 0 - 10

    // We need to seed the random number generator
    // time() returns the number of seconds since 1, 1, 1970
    srand(time(NULL));

    // If you divide any number it is impossible to get a 
    // remainder >= 11
    int secretNum = std::rand() % 11;
    int guess = 0;

    do {
        std::cout << "Guess a number between 1 and 10 : ";
        std::cin >> guess;
        if (guess > secretNum)
            std::cout << "Too Big\n";
        if (guess < secretNum) 
            std::cout << "Too Small\n";
    } while (secretNum != guess);

    std::cout << "You guessed it!\n";

    // ----- END OF DO WHILE LOOPS -----

    
    return 0;
}