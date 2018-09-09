#include "Fraction.h"

// Returns the highest common factor of two integers
int findHCF(int n1, int n2)
{
    if (n1 == 0)
        return n2;

    return findHCF(n2 % n1, n1);
}

// Returns the lowest common multiple of two integers
int findLCM(int n1, int n2)
{
    return (n1 * n2) / findHCF(n1, n2);
}



/* -------------------------- */
/* ------ CONSTRUCTORS ------ */
/* -------------------------- */

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1; // Denominator should never be 0
    fractionString = "0";
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;

    // Ensure denominator is not 0
    if (denominator == 0 && numerator != 0)
    {
        std::cout << "Zero denominator error\n";
        exit(1);
    }
    this->denominator = denominator;
    fractionString = std::to_string(numerator) + "/" + std::to_string(denominator);
}



/* -------------------------------- */
/* ------ OPERATOR FUNCTIONS ------ */
/* -------------------------------- */

Fraction::operator const char* ()
{
    std::ostringstream fractionStream;
    if (numerator == 0)
        fractionStream << "0";
    else if (numerator == denominator)
        fractionStream << "1";
    else if (numerator % denominator == 0)
        fractionStream << (numerator / denominator);
    else
        fractionStream << numerator << "/" << denominator;

    fractionString = fractionStream.str();

    return fractionString.c_str();
}

/*
std::ostream& operator << (std::ostream& out, const Fraction& f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}
*/

std::istream& operator >> (std::istream& in, Fraction& f)
{
    std::cout << "Numerator : ";
    in >> f.numerator;
    std::cout << "Denominator : ";
    in >> f.denominator;

    return in;
}

Fraction Fraction::operator + (const Fraction& f2)
{
    int lcm = findLCM(denominator, f2.denominator); // Lowest Common Multiple

    Fraction result = { ((numerator * (lcm / denominator)) + (f2.numerator * (lcm / f2.denominator))), lcm };
    simplify(result);

    return result;
}

Fraction Fraction::operator - (const Fraction& f2)
{
    int lcm = findLCM(denominator, f2.denominator); // Lowest Common Multiple

    Fraction result = { ((numerator * (lcm / denominator)) - (f2.numerator * (lcm / f2.denominator))), lcm };
    simplify(result);

    return result;
}

Fraction Fraction::operator * (const Fraction& f2)
{
    Fraction result = { (numerator * f2.numerator), (denominator * f2.denominator) };
    simplify(result);

    return result;
}

Fraction Fraction::operator / (const Fraction& f2)
{
    Fraction result = { (numerator * f2.denominator), (denominator * f2.numerator) };
    simplify(result);

    return result;
}

const bool Fraction::operator == (const Fraction& f2)
{
    int lcm = findLCM(denominator, f2.denominator); // Lowest Common Multiple

    // Perform comparison between numerators
    return ((numerator * (lcm / denominator)) == (f2.numerator * (lcm / f2.denominator)));
}

const bool Fraction::operator > (const Fraction& f2)
{
    int lcm = findLCM(denominator, f2.denominator); // Lowest Common Multiple
    int thisSize = numerator * (lcm / denominator); // Size of fraction 1
    int f2Size = f2.numerator * (lcm / f2.denominator); // Size of fraction 2
    
    // Perform comparison
    if (thisSize > f2Size)
        return true;
    else
        return false;
}

const bool Fraction::operator < (const Fraction& f2)
{
    int lcm = findLCM(denominator, f2.denominator); // Lowest Common Multiple
    int thisSize = numerator * (lcm / denominator); // Size of fraction 1
    int f2Size = f2.numerator * (lcm / f2.denominator); // Size of fraction 2

    // Perform comparison
    if (thisSize < f2Size)
        return true;
    else
        return false;
}

void Fraction::operator = (const Fraction& fractionToCopy)
{
    numerator = fractionToCopy.numerator;
    denominator = fractionToCopy.denominator;
}



/* ------------------------------- */
/* ------ GENERAL FUNCTIONS ------ */
/* ------------------------------- */

void Fraction::simplify(Fraction& fract)
{
    // If numerator is 0, assume that fraction cannot be simplified
    if (fract.numerator == 0)
        return;

    // abs() ====> returns the absolute value (or magnitude) of a number 
    // e.g. abs(-4) results in 4

    int hcf = findHCF(abs(fract.numerator), abs(fract.denominator));
    fract.numerator /= hcf;
    fract.denominator /= hcf;
}

double Fraction::toDouble() const
{
    return (double(numerator) / double(denominator));
}

/*
void Fraction::commonDenom(Fraction& f1, Fraction& f2)
{
    int lcm = findLCM(f1.denominator, f2.denominator); // Lowest Common Multiple
    f1.numerator *= (lcm / f1.denominator);
    f2.numerator *= (lcm / f2.denominator);
    f1.denominator = lcm, f2.denominator = lcm;
}
*/
