/*	The exercise involves making a database of employees, using a single vector, and saving the database on a file.
All employees have a first and last name, and a salary.
There are three kinds of employees, each with some distinct attributes:

	1) Manager
		- number of meetings per week
		- number of vacations per year
	
	2) Engineer
		- a value specifying whether they know C++
		- years of experience
		- string denoting their type (i.e "mechanical", "electric", "software")
	
	3) Researcher
		- string specifying the school they got their PhD from
		- string specifying topic of PhD Thesis
*/

#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"

int main() {
	std::vector<Employee> employees;
	Manager Tom{ "Tom", "Bradey", 109800, "Manager", 2, 3 };
	Researcher George{ "George", "Clooney", 95300, "Researcher",
		"McMooney University", "Processes of Fluid Dynamics" };
	Engineer Brandon{ "Brandon", "Holden", 101300, "Engineer", "Software" , 5, true };

	employees.push_back(Tom);
	employees.push_back(George);
	employees.push_back(Brandon);
	
	std::cout << Brandon << "\n"
		<< Tom << "\n"
		<< George << "\n";
	std::cout << Employee::GetNumOfEmployees() << "\n";

	for (int i = 0; i < employees.size(); i++)
		employees[i].Write();

	return 0;
}