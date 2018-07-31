// ************** TUTORIAL 6 **************
// https://www.youtube.com/watch?v=VPT9jXt3GC0
// In this tutorial we will be covering:
//  - Various Problems in C++
//
// ----- PROBLEM 1 -----
// Converting a string into a vector

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> StringToVector(std::string theString, char separator);

int main() {
    std::vector<std::string> vec
        = StringToVector("This is a random string", ' ');

    for (std::string str : vec)
    {
        std::cout << str << "\n";
    }
    
    return 0;
}

std::vector<std::string> StringToVector(std::string theString, char separator)
{
    std::vector<std::string> vecsWords; // store each individual word from theString

    std::stringstream ss(theString); // create a stringstream object
    std::string sIndivStr; // stores each individual string from theString 

    while (getline(ss, sIndivStr, separator))
    {
        vecsWords.push_back(sIndivStr); // push each individual string into vector vecsWords
    }

    return vecsWords;
}