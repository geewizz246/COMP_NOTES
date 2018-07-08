// This program converts miles to kilometers
// NB:
//  - only 1 decimal place for miles
//  - only 4 decimal places for kilometers
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

// Constants
#define KM_TO_MILES 1.60934 // conversion statistic

int main() 
{
    std::string sMiles;
    std::cout << "Enter miles : ";
    getline(std::cin, sMiles);

    double dMiles = std::stod(sMiles); //convert from string to double
    double dKm = dMiles * KM_TO_MILES;

    printf("%.1f miles equals %.4f kilometers.\n\n", dMiles, dKm);

    system("Pause");
    return 0;
}