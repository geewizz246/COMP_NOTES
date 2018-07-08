//Testing code from December 2016 Final Question 1
#include <iostream>
using namespace std;

int fun(int a, int b)
{
	if(a == b)
		return a + 1;
		else
		{
			int c = ((2*a)+ b) / 3;
			
			return fun(a, c) + fun(c+1, b);
		}
}//end fun

int main()
{
	cout << fun(3, 8) << endl;
	return 0;
}