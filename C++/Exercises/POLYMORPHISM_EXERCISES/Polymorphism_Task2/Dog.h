// Dog.h
#pragma once

#ifndef DOG_H
#define DOG_H

#include "Mammal.h"

class Dog : public Mammal {
public:
	void Move() const; // Simulates a dog's movement
	void Speak() const; // Simulates a dog's speach
};


#endif