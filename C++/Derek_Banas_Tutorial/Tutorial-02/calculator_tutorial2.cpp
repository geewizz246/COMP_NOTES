// Performs basic calculations based on user input
// e.g. 7 + 11 = 19

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
    std::string sCalculation = ""; // Stores the calculation to be executed
    std::vector<std::string> vecsCalc; 
    double dbNum1 = 0, // Store number 1
        dbNum2 = 0, // Store number 2
        result = 0; // Store result

    
    std::cout << "Enter a calculation (e.g. 5 + 6) : ";
   
    getline(std::cin, sCalculation);
    std::stringstream ss(sCalculation); // Receive calculation into stringstream object
    std::string sIndivStr;
    char cDelim = ' '; // Delimiter

    while (getline(ss, sIndivStr, cDelim))
    {
        vecsCalc.push_back(sIndivStr);
    }

    // Assume first and last strings in vector vecsCalc are numbers
    dbNum1 = std::stoi(vecsCalc[0]);
    dbNum2 = std::stoi(vecsCalc[2]);
    std::string operation = vecsCalc[1]; // get operation ('+', '-', '*', or '/')

    if (operation == "+") // add
        printf("%.2f + %.2f = %.2f\n\n", dbNum1, dbNum2, (dbNum1 + dbNum2));

    else if (operation == "-") // subtract
        printf("%.2f - %.2f = %.2f\n\n", dbNum1, dbNum2, (dbNum1 - dbNum2));

    else if (operation == "*") // multiply
        printf("%.2f * %.2f = %.2f\n\n", dbNum1, dbNum2, (dbNum1 * dbNum2));

    else if (operation == "/") // divide
        printf("%.2f / %.2f = %.2f\n\n", dbNum1, dbNum2, (dbNum1 / dbNum2));

    else
        printf("Please only enter '+', '-', '*', or '/' as operations.\n\n");

    
    return 0;
}