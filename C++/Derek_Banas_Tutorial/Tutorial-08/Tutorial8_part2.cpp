// ----- OVERLOADED FUNCTIONS TUTORIAL -----

#include <iostream>
#define PI 3.14159

/***********FUNCTION PROTOTYPES***********/

// Returns the area of a circle
double Area(double radius);

// Returns the area of a rectangle
double Area(double width, double height);

/***********END FUNCTION PROTOTYPES***********/


int main() {
	char areaType; // Determines what type of area is to be calculated

	std::cout << "Area of Circle (c) or Rectangle (r) : ";
	std::cin >> areaType;

	switch (areaType)
	{
		case 'c' :
			double radius; // Radius of circle
			std::cout << "Enter radius : ";
			std::cin >> radius;
			std::cout << "Area of Circle = " 
				<< Area(radius) << "\n";
			break;

		case 'r' :
			double width, // Width of rectangle
				height; // Height of rectangle
			std::cout << "Enter width : ";
			std::cin >> width;
			std::cout << "Enter height : ";
			std::cin >> height;
			std::cout << "Area of Rectangle = "
				<< Area(width, height) << "\n";
			break;

		default: std::cout << "Please enter \'c\' or \'r\'\n";
	}

	system("Pause");
	return 0;
}


/***********FUNCTION IMPLEMENTATIONS***********/

double Area(double radius)
{
	return PI * std::pow(radius, 2);
}

double Area(double width, double height)
{
	return width * height;
}

/***********END FUNCTION IMPLEMENTATIONS***********/