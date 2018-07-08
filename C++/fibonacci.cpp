//fibonacci.cpp
#include <iostream>
#include <string>

using namespace std;

int fib(int x)
{
    if(x == 0 || x == 1)
    {
        return x;
    }
    else
    {
        return fib(x-1) + fib(x-2);
    }
}

string rev(string s)
{
	string str = "";
	if (s.size() == 1)
		return s;
	else
		return rev(s.substr(1)) + s[0];
}

int main()
{
    int n = 16;
	string str = "drask";
    cout << fib(n) << endl;
	cout << rev(str) << endl;

    return 0;
}