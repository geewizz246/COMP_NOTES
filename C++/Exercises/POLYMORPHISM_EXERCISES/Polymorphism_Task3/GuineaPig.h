// GuineaPig.h
#pragma once

#ifndef GUINEAPIG_H
#define GUINEAPIG_H

#include "Mammal.h"

class GuineaPig : public Mammal {
public:
	void Move() const; // Simulates a guinea pig's movement
	void Speak() const; // Simulates a guinea pig's speach
};

#endif