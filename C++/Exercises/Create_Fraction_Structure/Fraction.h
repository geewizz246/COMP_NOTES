#include <iostream>
#include <string>

#ifndef FRACTION_H
#define FRACTION_H

// Fraction Object
class Fraction {
private:
    int numerator;
    int denominator;
    std::string fractionString; // Holds string representation of Fraction

public:
    /* ---------------------------------------------- */
    /* ---------------- CONSTRUCTORS ---------------- */
    /* ---------------------------------------------- */
        
    // Default Constructor
    Fraction();

    // Overloaded Constructor
    Fraction(int numerator, int denominator);

    // Set numerator
    void setNumerator(int numerator) { this->numerator = numerator; }

    // Get numerator
    int getNumerator() const { return numerator; }

    // Set denominator
    void setDenominator(int denominator) { this->denominator = denominator; }

    // Get denominator
    int getDenominator() const { return denominator; }


    /* ---------------------------------------------------- */
    /* ---------------- OPERATOR FUNCTIONS ---------------- */
    /* ---------------------------------------------------- */

    // Creates a C string representation which is a pointer to an array that is null terminated
    operator const char* ();

    // Alternatively, overload the << operator
    // friend std::ostream& operator << (std::ostream& out, const Fraction& f);

    // Overload + operator to add two fractions
    Fraction operator + (const Fraction& f2);

    // Operator + operator to add an integer to a fraction
    Fraction operator + (const int& num);

    // Overload - operator to subtract two fractions
    Fraction operator - (const Fraction& f2);

    // Overload - operator to subtract an integer from a fraction
    Fraction operator - (const int& num);

    // Overload * operator to multiply two fractions 
    Fraction operator * (const Fraction& f2);

    // Overload * operator to multiply a fraction by an integer
    Fraction operator * (const int& num);

    // Overload / operator to divide two fractions
    Fraction operator / (const Fraction& f2);

    // Overload / operator to divide a fraction by an integer
    Fraction operator / (const int& num);

    // Overload == operator to check for fraction equality
    const bool operator == (const Fraction& f2);

    // Overload > operator to check if one fraction is greater than the other
    const bool operator > (const Fraction& f2);

    // Overload < operator to check if one fraction is less than the other
    const bool operator < (const Fraction& f2);

    // Overload = operator to do fraction assignement
    void operator = (const Fraction& fractionToCopy);



    /* --------------------------------------------------- */
    /* ---------------- GENERAL FUNCTIONS ---------------- */
    /* --------------------------------------------------- */

    // Simplify given fraction
    void simplify(Fraction& fract);

    // Convert fraction to double equivalent
    double toDouble() const;
};

#endif
