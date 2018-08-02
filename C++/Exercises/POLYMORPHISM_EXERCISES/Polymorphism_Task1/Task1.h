// Task1.h
#include <iostream>

class Base {
public:
	virtual void testFunction();
};

class Derived : public Base {
public:
	void testFunction();
};