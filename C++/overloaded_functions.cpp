//overloading functions
#include <iostream>
using namespace std;

int operate (int a, int b) {
	return (a*b);
}

double operate (double a, double b) {
	return (a/b);
}

int main() {
	int x = 5, y = 2;
	double m = 5.0, n = 2.0;
	cout << operate (x,y) << '\n';
	cout << operate (m,n) << '\n';
	return 0;
}

/*************************************************************************************************************
 ** In this example, there are two functions called operate, but one of them has two parameters of type int **
 ** , while the other has them of type double. The compiler knows which one to call in each case by			**
 ** examining the types passed as arguments when the function is called. If it is called with two int 		**
 ** arguments, it calls to the function that has two int parameters, and if it is called with two doubles, 	**
 ** it calls the one with two doubles.																		**
 *************************************************************************************************************/
 
//Note that a function cannot be overloaded only by its return type. 
//At least one of its parameters must have a different type.