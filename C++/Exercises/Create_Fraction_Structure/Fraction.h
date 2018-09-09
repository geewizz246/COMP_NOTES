#pragma once

#include <iostream>
#include <string>
#include <sstream>

#ifndef FRACTION_H
#define FRACTION_H

// Fraction Object
struct Fraction {
    int numerator;
    int denominator;
    std::string fractionString; // Holds string representation of fraction

    /* -------------------------- */
    /* ------ CONSTRUCTORS ------ */
    /* -------------------------- */
        
    // Default Constructor
    Fraction();

    // Overloaded Constructor
    Fraction(int numerator, int denominator);



    /* -------------------------------- */
    /* ------ OPERATOR FUNCTIONS ------ */
    /* -------------------------------- */

    // Creates a C string representation which is a pointer to an array that is null terminated
    operator const char* ();

    // Alternatively, overload the << operator
    // friend std::ostream& operator << (std::ostream& out, const Fraction& f);

    friend std::istream& operator >> (std::istream& in, Fraction& f);

    // Overload + operator to add two fractions
    Fraction operator + (const Fraction& f2);

    // Overload - operator to subtract two fractions
    Fraction operator - (const Fraction& f2);

    // Overload * operator to multiply two fractions 
    Fraction operator * (const Fraction& f2);

    // Overload / operator to divide two fractions
    Fraction operator / (const Fraction& f2);

    // Overload == operator to check for fraction equality
    const bool operator == (const Fraction& f2);

    // Overload > operator to check if one fraction is greater than the other
    const bool operator > (const Fraction& f2);

    // Overload < operator to check if one fraction is less than the other
    const bool operator < (const Fraction& f2);

    // Overload = operator to do assignment
    void operator = (const Fraction& fractionToCopy);



    /* ------------------------------- */
    /* ------ GENERAL FUNCTIONS ------ */
    /* ------------------------------- */

    // Simplify given fraction
    void simplify(Fraction& fract);

    // Convert to double equivalent
    double toDouble() const;

    // Make two fractions have the same denominator
    // void commonDenom(Fraction& f1, Fraction& f2);
};

#endif
