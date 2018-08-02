// Cat.h
#pragma once

#ifndef CAT_H
#define CAT_H

#include "Mammal.h"

class Cat : public Mammal {
public:
	void Move() const; // Simulates a cat's movement
	void Speak() const; // Simulates a cat's speach
};

#endif