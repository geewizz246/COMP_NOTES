// Program to create a structure to hold fractions and related operations
#include <iostream>
#include "Fraction.h"

int main() {
    int numerator, denominator;
    std::cout << "* OPERATIONS WITH FRACTIONS *\n"
        << "When entering fractions, separate the numerator and denominator by a space.\n"
        << "E.g.\t\"2 3\" results in fraction 2/3\n\n\n\n";
    
    std::cout << "Enter fraction 1 (numerator and denominator, separated by a space) : ";
    std::cin >> numerator >> denominator;
    Fraction f1 = { numerator, denominator };
    std::cout << "Enter fraction 2 (numerator and denominator, separated by a space) : ";
    std::cin >> numerator >> denominator;
    Fraction f2 = { numerator, denominator };

    std::cout << "Fraction 1 numerator is " << f1.numerator
        << ", denominator is " << f1.denominator
        << " and its double equivalent is " << f1.toDouble() << ".\n";
    std::cout << "Fraction 2 numerator is " << f2.numerator
        << " and denominator is " << f2.denominator 
        << " and its double equivalent is " << f2.toDouble() << ".\n\n";

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << "\n";
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << "\n";
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << "\n";
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << "\n";
    std::cout << std::boolalpha;
    std::cout << f1 << " > " << f2 << "? ====> " << (f1 > f2) << "\n";
    std::cout << f1 << " < " << f2 << "? ====> " << (f1 < f2) << "\n";
    std::cout << f1 << " = " << f2 << "? ====> " << (f1 == f2) << "\n";

    return 0;
}
