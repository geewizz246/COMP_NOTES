// Vectors
// Strings and String Stream
// 
// Program playing around with vectors and string stream

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector> // This library is necessary for using vectors
#include <sstream> // std::stringstream

int main()
{
    // Declaring and initialising vectors
    std::vector<int> vecnRandNums(2); // Empty integer vector of size 2
    // Adding two items into the vector
    vecnRandNums[0] = 10;
    vecnRandNums[1] = 20;

    // To add a third item, we use the push_back() function
    vecnRandNums.push_back(30);

    // Get the size by using the size() function
    std::cout << "Last Index : [" <<
        vecnRandNums.size() - 1 << "] ====> " <<
        vecnRandNums[vecnRandNums.size() - 1] << "\n\n";

    std::string sSentence = "This is a random string.";
    std::vector<std::string> vecsWords;

    // std::stringstream ===> used for objects that receive strings in order to manipulate them
    // in various ways
    std::stringstream ss(sSentence); 
    std::string sIndivStr;
    char cSpace = ' '; // delimiter

    // getline(istream& input_stream, string& str, char delim);
    // The folowing getline does three things
    //  - extract characters from the stringstream ss (just like how input stream from keyboard is cin)
    //  - stores them in string sIndivStr
    //  - stops extracting characters when delimiter (in this case ' '; default is '\n') is found.
    // The While Loop does this until getline can no longer extract characters from the stringstream ss
    while (getline(ss, sIndivStr, cSpace))
    {
        vecsWords.push_back(sIndivStr); // push each individual string into vector vecsWords
    }

    for (int i = 0; i < vecsWords.size(); i++)
        std::cout << vecsWords[i] << "\n";

    
    return 0;
}