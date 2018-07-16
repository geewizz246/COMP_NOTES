// ************** TUTORIAL 10 **************
// In this tutorial we will be covering:
//  - Object Oriented Programming
//	- Classes
//  - Private & Public
//  - Constructors
//  - Inheritance
//
// ----- CLASS TUTORIAL -----


#include <iostream>
#include <string>


class Animal {
	// Private variables are only available to methods 
	// in the class
private:
	std::string name; // Name of animal
	double height; // Height of animal
	double weight; // Weight of animal

	// Static variables share the same value for all
	// objects of the Animal class
	static int numOfAnimals;

	// Public fields and methods can be accessed by
	// anything with access to the object
public:
	// Returns animal name
	std::string GetName() { return name; }

	// Sets animal name
	void SetName(std::string theName)
	{
		// Because we don't know what an objects name is 
		// (since the class is created before the object) 
		// we can refer to all objects using this.
		// The pointer operator is used to access an 
		// objects fields and methods.
		this->name = theName;
	}

	// Returns animal height
	double GetHeight() { return height; }

	// Sets animal height
	void SetHeight(double theHeight) { this->height = theHeight; }

	// Returns animal weight
	double GetWeight() { return weight; }

	// Sets animal witdh
	void SetWeight(double theWeight) { this->weight = theWeight; }

	// Sets all animal attributes
	void SetAll(std::string, double, double);

	// A constructor is called each time an object is created
	Animal(std::string, double, double);

	// Create an overloaded constructor for when no data is passed
	Animal();

	// A deconstructor is called automatically when an object
	// is deleted or is no longer used
	// The default is fine, but you should create custom ones
	// when you must release memory, or resources
	~Animal();

	// Static methods can only access static fields
	static int GetNumOfAnimals() { return numOfAnimals; }

	// Created to be overwritten
	void ToString();
};

// Refer to the class fields and methods with ::
int Animal::numOfAnimals = 0;

void Animal::SetAll(std::string name, double height, double weight)
{
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

Animal::Animal() 
{
	this->name = "";
	this->height = 0.0;
	this->weight = 0.0;
}

Animal::Animal(std::string name, double height, double weight)
{
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->name << " destroyed\n";
}

void Animal::ToString()
{
	std::cout << this->name << " is "
		<< this->height << "cms tall and "
		<< this->weight << "kgs in weight\n\n";
}


// Through inheritance a class inherits all fields and methods
// defined by the super, or inherited from class
class Dog : public Animal {
private:
	std::string sound = "Woof";

public: 
	// You can access to the private field name
	// by calling GetName()
	void MakeSound() {
		std::cout << "The dog "
			<< this->GetName() << " says "
			<< this->sound << "\n";
	}

	// The Dog's constructor
	Dog(std::string, double, double, std::string);

	// The default constructor calls Animals default
	// constructor
	Dog() : Animal() {};

	// Overwrite ToString
	void ToString();
};

// Calls the superclasses constructor to handle
// initalization
Dog::Dog(std::string name, double height, double weight, std::string sound) :
	Animal(name, height, weight)
{
	this->sound = sound;
}

void Dog::ToString()
{
	std::cout << this->GetName() << " is "
		<< this->GetHeight() << "cms tall and "
		<< this->GetWeight() << "kgs in weight and says "
		<< this->sound << ".\n\n";
}

int main() {
	// Create object without setting values in constructor
	Animal fred;
	fred.SetHeight(33);
	fred.SetWeight(10);
	fred.SetName("Fred");
	// Get the values for the Animal
	fred.ToString();

	fred.SetAll("Fred", 34, 12);

	fred.ToString();

	// Setting values with constructor
	Animal tom("Tom", 36, 15);
	tom.ToString();

	// Demonstrate inherited Dog class
	Dog spot("Spot", 38, 16, "Wooooof");

	// See different output from overwritten ToString()
	spot.ToString();

	// Call static methods by using the class name to
	// show the total Animals created
	std::cout << "Number of Animals " <<
		Animal::GetNumOfAnimals() << "\n";

	return 0;
}