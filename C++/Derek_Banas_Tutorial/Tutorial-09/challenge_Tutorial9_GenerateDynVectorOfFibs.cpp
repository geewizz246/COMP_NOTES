// ----- PROBLEM : GENERATE DYNAMIC VECTOR OF FIBS -----

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>

/***********FUNCTION PROTOTYPES***********/

std::vector<int> GenerateFibList(int maxNums);

/***********END FUNCTION PROTOTYPES***********/


int main() {
	int maxNum;
	std::cout << "Enter max number of Fibonacci numbers : ";
	std::cin >> maxNum;

	std::vector<int> fibVals = GenerateFibList(maxNum);
	
	std::cout << "\n\nFibonacci Numbers : \n";
	for (auto x : fibVals)
		std::cout << x << "\n";

	
	return 0;
}


/***********FUNCTION IMPLEMENTATIONS***********/

std::vector<int> GenerateFibList(int maxNums) {
	std::vector<int> listOfFibs;
	int i = 0;
	std::function<int(int)> Fib =
		[&Fib](int n) {return n < 2 ? n : Fib(n - 1) + Fib(n - 2); };
	while (i < maxNums) {
		listOfFibs.push_back(Fib(i));
		i++;
	}
	return listOfFibs;
}

/***********END FUNCTION IMPLEMENTATIONS***********/

// ----- END PROBLEM : GENERATE DYNAMIC VECTOR OF FIBS -----
