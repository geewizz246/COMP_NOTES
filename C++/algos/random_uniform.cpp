#include <iostream>
#include <random>

using namespace std;

int main()
{
	int min = 1;
	int max = 6;
	random_device rd;
	
	mt19937 eng1(rd());
	mt19937 eng2(100);
	
	uniform_int_distribution <> u(min, max);
	
	cout << "Eng1:" << endl;
	for(int i = 0; i < 10; i++)
		cout << u(eng1) << endl;
		
	cout << "Eng2:" << endl;
	for (int i = 0; i < 10; i++)
		cout << u(eng2) << endl;
}