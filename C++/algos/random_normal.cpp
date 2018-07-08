#include <iostream>
#include <random>

using namespace std;

int main()
{
	float mean = 26.75;
	float sd = 7.98;
	random_device rd;
	
	mt19937 my_eng(rd());
	
	normal_distribution <> nd(mean, sd);
	
	for(int i = 0; i < 100; i++)
		cout << nd(my_eng) << endl;
}
	