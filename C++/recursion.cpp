//recursion.cpp
#include <iostream>

using namespace std;

int fun(int n)
{
    if (n==1 || n==0)
        return n+1;
    else
        return fun(n/2) * fun((n+1)/2);
}

int main() {
    cout << fun(5) << endl;
    return 0;
}