// Do While Loops
//
// Program makes user guess a random number until they are correct

#include <iostream>
#include <vector>
#include <ctime> // Needed for time functions

int main() {
    
    // ----- PROBLEM CREATE A DO WHILE LOOP WITH WHILE -----

    srand(time(NULL));
    int secretNum = std::rand() % 11;
    int guess = 0;

    while (true) 
    {
        std::cout << "Guess a number between 1 and 10 : ";
        std::cin >> guess;
        if (guess > secretNum)
            std::cout << "Too Big\n";
        if (guess < secretNum)
            std::cout << "Too Small\n";
        if (guess == secretNum)
            break;
    }

    std::cout << "You guessed it!\n";

    // ----- END PROBLEM CREATE A DO WHILE LOOP WITH WHILE -----

    system("Pause");
    return 0;
}