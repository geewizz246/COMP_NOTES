// ************** TUTORIAL 14 **************
// https://youtu.be/ywNZAebgEZw
// In this tutorial we will be covering:
//  - Including Outside Files
//  - Macro Constants & Macro Functions
//  - Preprocessor Directives
//  - Templates
//  - Iterators
//
// ----- PREPROCESSOR DIRECTIVES TUTORIAL -----


// Anything that starts with a # is a preprocessor directive and they run 
//before the program compiles
#include <iostream>

// This is how you include outside files into your code
#include "Animal.h"

// This is a macro constant that will replace PI with 3.14159 in the code before execution
#define PI 3.14159

// This is a macro function that will do the same with a function
#define AREA_CIRCLE(radius) (PI * (std::pow(radius, 2)))


int main() {
    std::cout << "Circle Area : " << AREA_CIRCLE(10) << std::endl;

    Animal dog;
    dog.name = "Dog";
    std::cout << "Animal name : " << dog.name << std::endl;


    return 0;
}

// ----- END PREPROCESSOR DIRECTIVES TUTORIAL -----