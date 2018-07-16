// ----- PROBLEM 2 -----
// Convert a vector to a string

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string VectorToString(std::vector<std::string>& theVector, char separator);

int main() {
    std::vector<std::string> vCusts(3); // a vector to hold the names of the customers
    // Initialise the customer names
    vCusts[0] = "Bob";
    vCusts[1] = "Sue";
    vCusts[2] = "Tom";

    std::string sCusts = VectorToString(vCusts, ' ');
    std::cout << sCusts << "\n";

    
    return 0;
}

std::string VectorToString(std::vector<std::string>& theVector, char separator)
{
    std::string str = "";
    
    for (std::string cust : theVector)
    {
        str += cust + separator;
    }

    return str;
}
