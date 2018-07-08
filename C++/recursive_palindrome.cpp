//Program with a recursive function for detecting if string input is a palindrome
#include <iostream>
#include <string>

using namespace std;

// Returns result from checking if string is a palindrome
bool isPalindrome(string s)
{
	// if size is 0 or 1, assume a palindrome
	if (s.size() == 0 || s.size() == 1)
		return true;
	// if size > 1
	else{
		int start = 0; //starting index
		int end = s.size()-1; //ending index
		int len = s.size()-2; //length of substring
		
		// ignore all spaces
		while (s[start] == ' '){
			start++; //go to the next character
			len--; //decrement substring length
		}
		while (s[end] == ' '){
			end--; 
			len--;
		}
		
        if (s[start] == s[end]) // if first and last character match
            // send the middle of the current substring to the function again
            return isPalindrome(s.substr(start + 1, len));
        else // otherwise not a palindrome; return false
            return false;
	}
}//end isPalindrome


int main()
{
	string str;
	
	cout << "Enter a word/phrase: ";
	getline(cin, str);
	
	if(isPalindrome(str))
		cout << endl << "String is a palindrome" << endl << endl;
	else
		cout << endl << "String is NOT a palindrome" << endl << endl;		
	
    system("Pause");
	return 0;
}