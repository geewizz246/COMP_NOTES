// ----- RECURSIVE LAMBDA FUNCTIONS -----

#include <iostream>
#include <vector>
#include <functional> // std::function

int main() {
	// Recursive Lambda to calculate Fibonacci Numbers
	// std::function<result_type(arg_types)> f_name
	std::function<int(int)> Fib =
		[&Fib](int n) // [&Fib] ===> call the function on itself
		{ return n < 2 ? n : Fib(n - 1) + Fib(n - 2); };

	std::cout << "Fib 4 : " << Fib(4) << "\n";

	
	return 0;
}

// ----- END RECURSIVE LAMBDA FUNCTIONS -----