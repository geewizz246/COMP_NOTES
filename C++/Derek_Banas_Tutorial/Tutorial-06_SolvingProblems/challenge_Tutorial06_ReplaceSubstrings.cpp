// ----- PROBLEM 5. REPLACE ALL SUBSTRINGS -----

#include <iostream>
#include <string>
#include <vector>

/***********FUNCTION PROTOTYPES***********/

// Returns all the indexes where the substring is found
std::vector<int> FindSubstringMatches(std::string theString, std::string substring);

// Replace all occurrances of a given substring with a new substring
std::string ReplaceSubstring(std::string theString, std::string substring, std::string newString);

/***********END FUNCTION PROTOTYPES***********/


int main() {
    std::string phrase = "To be or not to be";
    std::string substring = "be";
    std::string newSubstring = "know";

    std::cout << "Original string : " << phrase << "\n\n";
    phrase = ReplaceSubstring(phrase, substring, newSubstring);

    std::cout << "New string : " << phrase << "\n";

    
    return 0;
}


/***********FUNCTION IMPLEMENTATIONS***********/

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

std::string ReplaceSubstring(std::string theString, std::string substring, std::string newString)
{
    // Get a vector that contains all matching indexes
    std::vector<int> matches = FindSubstringMatches(theString, substring);

    if (matches.size() != 0)
    {
        // Get size difference between substring and newString
        int lengthDifference = newString.size() - substring.size();

        // Times through loop
        int timesLooped = 0;

        for (auto index : matches) {
            theString.replace(index + (timesLooped * lengthDifference),
                substring.size(), newString);
            timesLooped++;
        }
    }

    return theString;
}

/***********END FUNCTION IMPLEMENTATIONS***********/