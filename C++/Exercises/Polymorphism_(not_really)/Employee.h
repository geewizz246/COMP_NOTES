// Employees.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Employee {
protected:
	std::string firstName; // Employee first name
	std::string lastName; // Employee last name
	double salary; // Employee salary
	std::string jobTitle; // Employee's job title (Manager, Engineer, Researcher)
	std::string employeeString; // Used to hold a string representation of an Employee

private:
	static int numOfEmployees; // Total number of Employee objects created

public:
	// Default constructor
	Employee();

	// Overloaded constructor
	Employee(std::string firstName, std::string lastName, 
		double salary, std::string jobTitle);

	// Return the number of Employee objects created
	static int GetNumOfEmployees() { return numOfEmployees; }

	virtual operator const char* ()
	{
		std::ostringstream employeeStream;
		employeeStream << "Name : " << firstName << " " << lastName << "\n"
			<< "Salary : " << salary << "\n"
			<< "Job Title : " << jobTitle << "\n";

		employeeString = employeeStream.str();

		return employeeString.c_str();
	}

	// Appends the employee information to a text file
	void Write();
};



class Manager : public Employee {
private:
	int m_numOfMeetingsWeekly = 0; // Number of meetings weekly for manager
	int m_numOfVacationsYearly = 0; // Number of vacations yearly for manager

public:
	// Default constructor
	Manager() : Employee() {};

	// Overloaded constructor
	Manager(std::string, std::string, double, std::string, int, int);

	operator const char* () override
	{
		std::ostringstream employeeStream;
		employeeStream << "Name : " << firstName << " " << lastName << "\n"
			<< "Salary : " << salary << "\n"
			<< "Job Title : " << jobTitle << "\n"
			<< "Number of Meetings Weekly : " << m_numOfMeetingsWeekly << "\n"
			<< "Number of Vacations Yearly : " << m_numOfVacationsYearly << "\n";

		employeeString = employeeStream.str();

		return employeeString.c_str();
	}
};



class Engineer : public Employee {
private:
	std::string e_type = "N/A"; // Engineer type (i.e "mechanical", "electric", "software")
	int e_yearsExperience = 0; // Engineer experience in years
	bool e_knowsCpp = false; // Engineer proficiency in C++

public:
	// Default constructor
	Engineer() : Employee() {};

	// Overloaded constructor
	Engineer(std::string, std::string, double, std::string, std::string, int, bool);

	operator const char* () override
	{
		std::ostringstream employeeStream;
		employeeStream << std::boolalpha;
		employeeStream << "Name : " << firstName << " " << lastName << "\n"
			<< "Salary : " << salary << "\n"
			<< "Job Title : " << jobTitle << "\n"
			<< "Engineer Type : " << e_type << "\n"
			<< "Years Experience : " << e_yearsExperience << "\n"
			<< "Knows C++ : " << e_knowsCpp << "\n";

		employeeString = employeeStream.str();

		return employeeString.c_str();
	}
};



class Researcher : public Employee {
private:
	std::string r_schoolPhD = "N/A"; // School which awarded researcher's PhD
	std::string r_thesisTopic = "N/A"; // Researcher PhD thesis topic

public:
	// Default constructor
	Researcher() : Employee() {};

	// Overloaded constructor
	Researcher(std::string, std::string, double, std::string, std::string, std::string);

	operator const char* () override
	{
		std::ostringstream employeeStream;
		employeeStream << "Name : " << firstName << " " << lastName << "\n"
			<< "Salary : " << salary << "\n"
			<< "Job Title : " << jobTitle << "\n"
			<< "School of PhD award : " << r_schoolPhD << "\n"
			<< "Thesis Topic : " << r_thesisTopic << "\n";

		employeeString = employeeStream.str();

		return employeeString.c_str();
	}
};

#endif