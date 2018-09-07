// Program to create a structure to hold fractions and related operations
#include <iostream>
#include <sstream>
#include <string>
#include "Fraction.h"

int main() {
    Fraction f1, f2;
    std::cout << "* OPERATIONS WITH FRACTIONS *\n"
        << "When entering fractions, separate the numerator and denominator by a space.\n"
        << "E.g.\t\"2 3\" results in fraction 2/3\n\n\n\n";
    std::cout << "Enter fraction 1 (numerator and denominator, separated by a space) : ";
    std::cin >> f1.numerator >> f1.denominator;
    std::cout << "Enter fraction 2 (numerator and denominator, separated by a space) : ";
    std::cin >> f2.numerator >> f2.denominator;

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