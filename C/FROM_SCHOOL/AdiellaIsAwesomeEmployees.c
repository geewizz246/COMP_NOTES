/*	A company employs 25 employees. Each record contains the employees' first name and last name (30 charachters in length), the hours worked, the employee type
	(permanent, temporary, intern), and his/her deductions. The hourly rate for the employment types are as follows:
	- Permanent:- $50 per hour
	- Temporary:- $30 per hour
	- Intern:- $15 per hour
	Write a program that reads the data for 25 employees and:
	• calculates and prints the gross salary for each employee (gross salary calculated: hours worked * hourly rate)
	• calculates and prints the net pay for each employee (gross pay - deductions)
	• calculates and prints the TOTAL OVERALL NET PAY (the sum of each employees' net pay) 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 2
struct workplace
{
	char fname[30];
	char lname[30];
	char type[10];
	float hours,deductions,gross,net;
};
main()
{
	struct workplace employee[size];
	int i;
	float total;
	
	for(i=0;i<size;i++)
	{
		printf("Enter your first and last name.\n");
		scanf("%s%s",&employee[i].fname,&employee[i].lname);
		
		printf("What type of employee art thou?\n");
		scanf("%s",&employee[i].type);
		
		printf("Enter number of hours worked.\n");
		scanf("%f",&employee[i].hours);
		
		printf("Enter your deductions.\n");
		scanf("%f",&employee[i].deductions);
		
		if(stricmp(employee[i].type,"permanent")==0)
		{
			employee[i].gross=50*employee[i].hours;
			employee[i].net=employee[i].gross-employee[i].deductions;
		}
		else
		if(stricmp(employee[i].type,"temporary")==0)
		{
			employee[i].gross=30*employee[i].hours;
			employee[i].net=employee[i].gross-employee[i].deductions;
		}
		else
		if(stricmp(employee[i].type,"intern")==0)
		{
			employee[i].gross=15*employee[i].hours;
			employee[i].net=employee[i].gross-employee[i].deductions;
		}
		total=total+employee[i].net;
		
		printf("Gross salary for employee %d: $%.2f\n",i,employee[i].gross);
		printf("Net salary for employee %d: $%.2f\n",i,employee[i].net);
	}
	
	printf("The total overall net pay is: $%.2f\n\n",total);
	
	system("Pause");
}
	
	
