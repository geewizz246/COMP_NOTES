// ************** TUTORIAL 5 **************
// https://www.youtube.com/watch?v=xxMG5HwCK6w
// In this tutorial we will be covering:
//  - Math Functions
//  - Strings
//
// ----- STRING TUTORIAL -----

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Necessary for transform function

int main()
{
    // A C character string is an array of characters
    // with a null character at the end \0
    char cString[] = { 'A', ' ', 's', 't', 'r', 'i', 'n', 'g', '\0' };

    // Get size of cString (null character included)
    std::cout << "Array Size : " << sizeof(cString) << "\n\n";

    // C strings are troublesome because if you forget \0, or
    // add to much information it can lead your program to crash,
    // or for your system to crash
    

    // You can create a vector of strings
    std::vector<std::string> strVec(10);

    // C++ std::string can grow in size and is much safer
    std::string str("I'm a string");
    strVec[0] = str;

    // You can access characters with an index
    std::cout << str[0] << "\n";

    // You can also use at()
    std::cout << str.at(0) << "\n";

    // Front returns first char and back returns last
    std::cout << str.front() << " " << str.back() << "\n";

    // Get the string length
    std::cout << "Length : " << str.length() << "\n";

    // You can copy a string to another
    std::string str2(str);
    strVec[1] = str2;

    // You can copy after the first 4 characters
    std::string str3(str, 4);
    strVec[2] = str3;

    // Repeat a value to make a string
    std::string str4(5, 'x'); // Create a string of 5 x's
    strVec[3] = str4;

    // Combine strings with append or +
    strVec[4] = str.append(" and you're not");
    str += " and you're not";

    // append(str, start, len) ===> append part of a string
    // E.g. append from position 39 of str for a span of 37
    // characters OR until the end of the string
    str.append(str, 39, 37);
    strVec[5] = str;

    // erase(start, end) ===> erase characters from a string from a starting 
    // index to an ending index
    // E.g. erase from the 13th character to the last character
    str.erase(13, str.length() - 1);
    strVec[6] = str;

    /*
    for (auto y : strVec)
        std::cout << y << "\n";
    */

    // find() ===> searches the string for the first occurrence of 
    // the sequence specified by its arguments
	// string::npos ===> a static member constant value with the greatest possible 
	// value for an element of type size_t
	// This value, when used as the value for a len (or sublen) parameter in string's 
	// member functions, means "until the end of the string".
    if (str.find("string") != std::string::npos)
        std::cout << "1st index :  " << str.find("string") << "\n\n";
    
    // substr(x, y) ===> returns a substring starting at
    // index x with a length of y
    std::cout << "Substr " << str.substr(6, 6) << "\n";

    // Reverse a string by passing the beginning and end
    // of a string
    reverse(str.begin(), str.end());
    std::cout << "Reverse : " << str << "\n\n";

    // Case conversion
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    std::cout << "Upper : " << str2 << "\n";
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    std::cout << "Lower : " << str2 << "\n\n";

    // You can get the ascii code for a char by saving
    // the char as an int or with (int)
    // a - z : 97 - 122
    // A - Z : 65 - 90
    char aChar = 'Z';
    int aInt = aChar;
    std::cout << "\'a\' Code : " << (int)'a' << "\n"
        << "\'Z\' Code : " << aChar << "\n\n";

    // Convert int to string
    std::string strNum = std::to_string(1 + 2);
    std::cout << "String : " << strNum << "\n";

    
    return 0;
}