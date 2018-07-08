//Program to play the child game "FizzBuzz"
#include <iostream>
#include <string>
#define LOG(x) cout << x << endl
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++)
    {
		string output = "";
		if (i % 3 == 0) { output += "Fizz"; }
		if (i % 5 == 0) { output += "Buzz"; }
		if (output == "") { output += to_string(i); }
        
        LOG(output);
    }

    return 0;
}