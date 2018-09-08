#include "Fraction.h"

// Returns the lowest common multiple of two integers
int LCM(int n1, int n2)
{
    int max = n1 > n2 ? n1 : n2;

    do {
        if (max % n1 == 0 && max % n2 == 0)
        {
            return max;
            break;
        }
        else
        {
            max++;
        }
    } while (true);
}

// Returns the highest common factor of two integers
int HCF(int n1, int n2)
{
    int min = n1 < n2 ? n1 : n2;

    do {
        if (n1 % min == 0 && n2 % min == 0)
        {
            return min;
            break;
        }
        else
        {
            min--;
        }
    } while (true);
}



Fraction::operator const char* ()
{
    std::ostringstream fractionStream;
    fractionStream << numerator << "/" << denominator;

    fractionString = fractionStream.str();

    return fractionString.c_str();
}

Fraction Fraction::operator + (const Fraction& f2)
{
    int lcm = LCM(denominator, f2.denominator); // Lowest Common Multiple

    Fraction result = { ((numerator * (lcm / denominator)) + (f2.numerator * (lcm / f2.denominator))), lcm };
    simplify(result);

    return result;
}

Fraction Fraction::operator - (const Fraction& f2)
{
    int lcm = LCM(denominator, f2.denominator);

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

bool Fraction::operator == (const Fraction& f2)
{
    int lcm = LCM(denominator, f2.denominator); // Lowest Common Multiple

    // Perform comparison between numerators
    return ((numerator * (lcm / denominator)) == (f2.numerator * (lcm / f2.denominator)));
}

bool Fraction::operator > (const Fraction& f2)
{
    int lcm = LCM(denominator, f2.denominator); // Lowest Common Multiple
    int thisSize = numerator * (lcm / denominator); // Size of fraction 1
    int f2Size = f2.numerator * (lcm / f2.denominator); // Size of fraction 2
    
    // Perform comparison
    if (thisSize > f2Size)
        return true;
    else
        return false;
}

bool Fraction::operator < (const Fraction& f2)
{
    int lcm = LCM(denominator, f2.denominator); // Lowest Common Multiple
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



void Fraction::simplify(Fraction& fract)
{
    int hcf = HCF(fract.numerator, fract.denominator);
    fract.numerator /= hcf;
    fract.denominator /= hcf;
}

/*
void Fraction::commonDenom(Fraction& f1, Fraction& f2)
{
    int lcm = LCM(f1.denominator, f2.denominator); // Lowest Common Multiple
    f1.numerator *= (lcm / f1.denominator);
    f2.numerator *= (lcm / f2.denominator);
    f1.denominator = lcm, f2.denominator = lcm;
}
*/
