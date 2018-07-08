// ----- PROBLEM 4. FIND ALL INDEX MATCHES RETURN VECTOR -----

#include <iostream>
#include <string>
#include <vector>

// Returns all the indexes where the substring is found
std::vector<int> FindSubstringMatches(std::string theString, std::string substring);

int main() {
    std::string phrase = "To be or not to be";
    std::string substring = "be";

    std::vector<int> matches = FindSubstringMatches(phrase, substring);
    
    std::cout << "Indexes for substring \"" << substring << "\":\n";
    
    for (int i = 0; i < matches.size(); i++)
        std::cout << matches[i] << "\n";

    system("Pause");
    return 0;
}

std::vector<int> FindSubstringMatches(std::string theString, std::string substring)
{
    std::vector<int> matchingIndexes;

    //Check for matching substring
    int index = theString.find(substring, 0);

    while (index != std::string::npos /*until index is the end of string*/)
    {
        matchingIndexes.push_back(index);
        index = theString.find(substring, index + 1);
    }

    return matchingIndexes;
}
