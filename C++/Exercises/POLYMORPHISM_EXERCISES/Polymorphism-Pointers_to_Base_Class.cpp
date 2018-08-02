// Pointers to Base Class
// One of the key features of class inheritance is that a pointer to a derived class is
// compatible with a pointer to its base class.

#include <iostream>

class Polygon {
protected:
	int width, height;

public:
	void SetValues(int width, int height)
	{ this->width = width; this->height = height; }
};

class Rectangle : public Polygon {
public:
	int area()
	{ return width * height; }
};

class Triangle : public Polygon {
public:
	int area()
	{ return width * (height / 2); }
};



int main() {
	Rectangle rect;
	Triangle trgl;
	Polygon* ppoly1 = &rect; // Polygon pointer to an object of derived class Rectangle
	Polygon* ppoly2 = &trgl; // Polygon pointer to an object of derived class Triangle
	
	// Dereferencing Polygon pointers
	ppoly1->SetValues(36, 12);
	ppoly2->SetValues(10, 13);

	std::cout << rect.area() << '\n';
	std::cout << trgl.area() << '\n';

	return 0;
}