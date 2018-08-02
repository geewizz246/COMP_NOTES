// Main.cpp
// https://eecs.wsu.edu/~nroy/courses/cpts122/labs/Lab9_cpts122.htm
#include <iostream>
#include "Mammal.h"
#include "Dog.h"

using namespace std;

int main() {
	Mammal* pMammal = new Mammal();
	Mammal* pDog1 = new Dog();
	Dog* pDog2 = new Dog();

	pMammal->Move(); // Mammal::Move()
	pMammal->Speak(); // Mammal::Speak()

	pDog1->Move(); // Dog::Move()
	pDog1->Speak(); // Mammal::Speak()

	pDog2->Move(); // Dog::Move()
	pDog2->Speak(); // Dog::Speak()

	return 0;
}