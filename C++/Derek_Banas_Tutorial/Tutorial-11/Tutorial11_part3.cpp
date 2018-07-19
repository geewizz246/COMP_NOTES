// ----- POLYMORPHISM TUTORIAL -----
// Polymorphism is a feature in which similar 
// objects can be treated the same, but also
// utilize their differences automatically
// for any methods marked as virtual

#include <iostream>

class Shape {
// The sublclasses that inherit from the current
// class are going to be able to access any protected
// data members and methods
protected: 
	double height;
	double width;

public:
	Shape(double length)
	{
		height = length;
		width = length;
	}

	Shape(double h, double w)
	{
		height = h;
		width = w;
	}

	virtual double Area()
	{
		return height * width;
	}
};

class Circle : public Shape {
public:
	Circle(double w) :
		Shape(w) {

	}

	// Override Area()
	double Area()
	{
		return 3.14159 * std::pow((width / 2), 2);
	}
};

// This function receives Shapes but uses the correct Area()
// method automatically
void ShowArea(Shape& shape)
{
	std::cout << "Area : " << shape.Area() << "\n";
}


int main()
{
	Shape square(10);
	Shape rectangle(15, 6);
	Circle circle(12);
	ShowArea(square);
	ShowArea(rectangle);
	ShowArea(circle);

	return 0;
}

// ----- END POLYMORPHISM TUTORIAL -----