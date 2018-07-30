// Employee.cpp ===> Implementation file

#include "Employee.h"

/***********************************************************
 ==================> EMPLOYEE FUNCTIONS <===================
 ***********************************************************/
int Employee::numOfEmployees = 0;

Employee::Employee()
{
	firstName = "";
	lastName = "";
	salary = 0.0;
	jobTitle = "N/A";
	Employee::numOfEmployees++;
}

Employee::Employee(std::string firstName, std::string lastName, double salary, std::string jobTitle)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->salary = salary;
	this->jobTitle = jobTitle;
	Employee::numOfEmployees++;
}

void Employee::Write() {
	std::fstream emp_file{ "employee.txt", std::ios_base::app };

	if (!emp_file)
		std::cout << "Error opening employee.txt file\n";
	else
	{
		emp_file << employeeString;
	}
}




/***********************************************************
 ===================> MANAGER FUNCTIONS <===================
 ***********************************************************/

Manager::Manager(std::string firstName, std::string lastName, double salary, std::string jobTitle, 
	int m_numOfMeetingsWeekly, int m_numOfVacationsYearly) :
	Employee(firstName, lastName, salary, jobTitle)
{
	this->m_numOfMeetingsWeekly = m_numOfMeetingsWeekly;
	this->m_numOfVacationsYearly = m_numOfVacationsYearly;

	std::ostringstream employeeStream;
	employeeStream << "Name : " << firstName << " " << lastName << "\n"
		<< "Salary : " << salary << "\n"
		<< "Job Title : " << jobTitle << "\n"
		<< "Number of Meetings Weekly : " << m_numOfMeetingsWeekly << "\n"
		<< "Number of Vacations Yearly : " << m_numOfVacationsYearly << "\n\n\n";
	employeeString = employeeStream.str();
}




/***********************************************************
 ===================> ENGINEER FUNCTIONS <==================
 ***********************************************************/

Engineer::Engineer(std::string firstName, std::string lastName, double salary, std::string jobTitle,
	std::string e_type, int e_yearsExperience, bool knowsCpp) :
	Employee(firstName, lastName, salary, jobTitle)
{
	this->e_type = e_type;
	this->e_yearsExperience = e_yearsExperience;
	this->e_knowsCpp = e_knowsCpp;

	std::ostringstream employeeStream;
	employeeStream << std::boolalpha;
	employeeStream << "Name : " << firstName << " " << lastName << "\n"
		<< "Salary : " << salary << "\n"
		<< "Job Title : " << jobTitle << "\n"
		<< "Engineer Type : " << e_type << "\n"
		<< "Years Experience : " << e_yearsExperience << "\n"
		<< "Knows C++ : " << e_knowsCpp << "\n\n\n";
	employeeString = employeeStream.str();
}




/***********************************************************
 ==================> RESEARCHER FUNCTIONS <=================
 ***********************************************************/

Researcher::Researcher(std::string firstName, std::string lastName, double salary, std::string jobTitle,
	std::string r_schoolPhD, std::string r_thesisTopic) :
	Employee(firstName, lastName, salary, jobTitle)
{
	this->r_schoolPhD = r_schoolPhD;
	this->r_thesisTopic = r_thesisTopic;

	std::ostringstream employeeStream;
	employeeStream << "Name : " << firstName << " " << lastName << "\n"
		<< "Salary : " << salary << "\n"
		<< "Job Title : " << jobTitle << "\n"
		<< "School of PhD award : " << r_schoolPhD << "\n"
		<< "Thesis Topic : " << r_thesisTopic << "\n\n\n";
	employeeString = employeeStream.str();
}