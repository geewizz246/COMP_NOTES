//Client File
//Main_BMI.cpp
#include <iostream>
#include <string>
#include<vector>
#include "BMI.h"

using namespace std;

int main() {
	vector<BMI> patients;
	BMI patient_1{ 0015, "George", 68, 150.4 }; //using overload constructor
	BMI patient_2; //using default constructor
	BMI patient_3{ 0264, "Conor", 65, 170.45 };

	patients.push_back(patient_1);
	patients.push_back(patient_3);

	int ID;
	string name;
	int height;
	double weight;

	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	patient_2.setID(ID);
	
	cout << "Enter your name: ";
	getline(cin,name);
	patient_2.setName(name);

	cout << "Enter your height (in inches): ";
	cin >> height;
	patient_2.setHeight(height);

	cout << "Enter your weight (in pounds): ";
	cin >> weight;
	patient_2.setWeight(weight);

	patients.push_back(patient_2);

	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//used to flush the newline character out of the buffer
	//useful when using cin or getline for strings when an input comes before

	for (int i = 0; i < patients.size(); i++)
		patients[i].printInfo();

	return 0;
}