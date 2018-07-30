//Implementation File ==> Function Definitions
//BMI.cpp
#include "BMI.h"

//Default Constructor
BMI::BMI() {
	ID = -1;
	name = "";
	height = 0;
	weight = 0;
}

//Overload Constructor
BMI::BMI(int newID, std::string newName, int newHeight, double newWeight) {
	ID = newID;
	name = newName;
	height = newHeight;
	weight = newWeight;
}

//Destructor
BMI::~BMI() {

}

//Mutator Functions
void BMI::setID(int newID) {
	ID = newID;
}

void BMI::setName(std::string newName) {
	name = newName;
}

void BMI::setHeight(int newHeight) {
	height = newHeight;
}

void BMI::setWeight(double newWeight) {
	weight = newWeight;
}

//Access Functions
int BMI::getID() const {
	return ID;
}

std::string BMI::getName() const {
	return name;
}

int BMI::getHeight() const {
	return height;
}

double BMI::getWeight() const {
	return weight;
}

//Other Functions
double BMI::calculateBMI() const {
	return ((weight * 703) / (height * height));
}

void BMI::printInfo() {
	std::cout << std::endl << "***Patient " << ID << "***"
		<< std::endl << "Patient Name: " << name
		<< std::endl << "Patient Height: " << height << " in."
		<< std::endl << "Patient Weight: " << weight << " lbs."
		<< std::endl << "BMI: " << calculateBMI() << std::endl;
}