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

    /* -------------------------------- */
    /* ------ OPERATOR FUNCTIONS ------ */
    /* -------------------------------- */

        // Creates a C string representation which is a pointer to an array that is null terminated
        operator const char* ();

        // Overload + operator to add two fractions
        Fraction operator + (const Fraction& f2);

        // Overload - operator to subtract two fractions
        Fraction operator - (const Fraction& f2);

        // Overload * operator to multiply two fractions 
        Fraction operator * (const Fraction& f2);

        // Overload / operator to divide two fractions
        Fraction operator / (const Fraction& f2);

        // Overload == operator to check for fraction equality
        bool operator == (const Fraction& f2);

        // Overload > operator to check if one fraction is greater than the other
        bool operator > (const Fraction& f2);

        // Overload < operator to check if one fraction is less than the other
        bool operator < (const Fraction& f2);

        // Overload = operator to do assignment
        void operator = (const Fraction& fractionToCopy);



    /* ------------------------------- */
    /* ------ GENERAL FUNCTIONS ------ */
    /* ------------------------------- */

        // Return the numerator
        int getNumerator() const { return numerator; }

        // Return the denominator
        int getDenominator() const { return denominator; }

        // Simplify given fraction
        void simplify(Fraction&);

        // Make two fractions have the same denominator
        // void commonDenom(Fraction& f1, Fraction& f2);
};


#endif