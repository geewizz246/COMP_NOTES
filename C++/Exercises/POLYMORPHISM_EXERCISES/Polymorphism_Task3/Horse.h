// Horse.h
#pragma once

#ifndef HORSE_H
#define HORSE_H

#include "Mammal.h"

class Horse : public Mammal {
public:
	void Move() const; // Simulates a horse's movement
	void Speak() const; // Simulates a horse's speach
};

#endif