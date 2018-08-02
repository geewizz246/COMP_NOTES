// Mammal.cpp

#include "Mammal.h"

Mammal::Mammal(void) : age(1), weight(50)
{
	std::cout << "Called Mammal constructor\n";
}

Mammal::~Mammal(void)
{
	std::cout << "Called Mammal destructor\n";
}

void Mammal::Move() const
{
	std::cout << "Mammal moves a step!\n";
}

void Mammal::Speak() const
{
	std::cout << "What does a mammal speak? Mammilian!\n";
}