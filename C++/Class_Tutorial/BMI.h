//Header File ==> Function Declarations
//BMI.h
#include <iostream>
#include <string>

//HEADER GUARDS
#ifndef BMI_H
#define BMI_H

class BMI {
public:
	//Default Constructor
	BMI();

	//Overload Constructor
	BMI(int, std::string, int, double);

	//Destructor ==> called when objects are destroyed (deallocated)
	//commonly used to "clean up" when an object is no longer necessary
	~BMI();

	//Mutator Functions
	//setID - takes in ID of patient
	void setID(int);

	//setName - takes in name of patient
	void setName(std::string);

	//setHeight - takes in height of patient
	void setHeight(int);

	//setWeight - takes in weight of patient
	void setWeight(double);

	//Access Functions
	//getID - returns ID of patient
	int getID() const;
	
	//getName - returns name of patient
	std::string getName() const;

	//getHeight - returns height of patient
	int getHeight() const;

	//getWeight - returns weight of patient
	double getWeight() const;

	//Other Functions
	//calculateBMI - calculates BMI of patient
	double calculateBMI() const;

	//printInfo - prints informations of patient
	void printInfo();
	
private:
	//Member Variables
	int ID;
	std::string name;
	int height;
	double weight;
};

//END OF HEADER GUARD
#endif