// ----- ABSTRACT CLASS / OVERRIDE TUTORIAL -----

#include <iostream>

// Shape here has no purpose except for being able to group 
// similar objects so it should be instead an Abstract Class
class Shape {
public:
	virtual double Area() = 0;
};

class Circle : public Shape {
protected:
	double width;

public:
	Circle(double w)
	{
		width = w;
	}

	// Override Area()
	// You should use override to force the compiler to check 
	// if the base class virtual fucntion is the same as
	// the subclass
	double Area() override
	{
		return 3.14159 * std::pow((width / 2), 2);
	}
};

class Rectangle : public Shape {
protected:
	double height;
	double width;

public:
	Rectangle(double h, double w)
	{
		height = h;
		width = w;
	}

	// Override Area()
	// Marking a method as final maens that subclasses
	// that inherit from rectangle can't override Area()
	double Area() override final
	{
		return height * width;
	}
};

class Square : public Rectangle {
public:
	Square(double h, double w) :
		Rectangle(h, w)
		{

		}

	/* 
	This would trigger an error
	double Area() override
	{
		return height * 2;
	}
	*/
};

void ShowArea(Shape& shape)
{
	std::cout << "Area : " << shape.Area() << "\n";
}


int main()
{
	Rectangle rectangle(15, 6);
	Circle circle(10);
	Square square(10, 10);

	ShowArea(square);
	ShowArea(rectangle);
	ShowArea(circle);

	return 0;
}

// ----- END ABSTRACT CLASS / OVERRIDE TUTORIAL -----