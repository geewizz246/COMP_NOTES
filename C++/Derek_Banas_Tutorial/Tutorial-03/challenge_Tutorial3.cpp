#include <iostream>
#include <vector>

// #----- FUNCTION PROTOTYPES -----#

std::vector<int> Range(int start, int max, int step);

// #----- FUNCTION PROTOTYPES ------#

int main() {
    // ----- PROBLEM CREATE A RANGE FUNCTION -----
    // Create a function that receives a starting value,
    // max value and an increment amount between
    // values and receive a vector in return

    std::vector<int> range = Range(1, 10, 2);

    for (auto x : range)
        std::cout << x << " ";
    std::cout << std::endl;

    // ----- END PROBLEM CREATE A RANGE FUNCTION -----

    // ----- PROBLEM CALCULATE COMPOUNDING INTEREST -----
    double investment = 0.0;
    double interestRate = 0.0;
    int nYears = 0;

    std::cout << "How much to invest : ";
    std::cin >> investment;
    std::cout << "Interest rate : ";
    std::cin >> interestRate;
    std::cout << "Number of years : ";
    std::cin >> nYears;
    
    // Convert interestRate into a percentage
    interestRate *= 0.01;

    for (auto x : Range(1, nYears, 1))
        investment = investment + (investment * interestRate);

    std::cout << "Value after " << nYears << " years : "
        << investment << "\n\n";
    
    // ----- END PROBLEM CALCULATE COMPOUNDING INTEREST -----

    system("Pause");
    return 0;
}

// #----- FUNCTION IMPLEMENTATIONS -----#

std::vector<int> Range(int start, int max, int step) {
    std::vector<int> range;
    for (int i = start; i <= max; i += step) {
        range.push_back(i);
    }

    return range;
}

// #----- FUNCTION IMPLEMENTATIONS ------#