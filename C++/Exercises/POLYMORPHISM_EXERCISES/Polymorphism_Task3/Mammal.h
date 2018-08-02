// Mammal.h
#pragma once // Preprocessor directive which causes the current source file
			 // to only be included once in a single compilation
#ifndef MAMMAL_H
#define MAMMAL_H

#include <iostream>

class Mammal {
public:
	Mammal(void); // Default constructor
	~Mammal(void); // Destructor

	virtual void Move() const; // Simulates generic mammal movement
	virtual void Speak() const; // Simulates generic mammal speach

protected:
	int age;
	int weight;
};

#endif