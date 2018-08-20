/*	
	Part 1
	A company employs 25 employees. Each record contains the employees' first name and last name (30 charachters in length), the hours worked, the employee type
	(permanent, temporary, intern), and his/her deductions. The hourly rate for the employment types are as follows:
	- Permanent:- $50 per hour
	- Temporary:- $30 per hour
	- Intern:- $15 per hour
	Write a program that reads the data for 25 employees and:
	• calculates and prints the gross salary for each employee (gross salary calculated: hours worked * hourly rate)
	• calculates and prints the net pay for each employee (gross pay - deductions)
	• calculates and prints the TOTAL OVERALL NET PAY (the sum of each employees' net pay)
	
	Part 2
	Make a function that will calculate the pay and search the records for person(name) and print their pay.
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
int pay(struct workplace worker[])
{
	int i;
	for(i=0;i<size;i++)
	{
		if(stricmp(worker[i].type,"permanent")==0)
		{
			worker[i].gross=50*worker[i].hours;
			worker[i].net=worker[i].gross-worker[i].deductions;
		}
		else
		if(stricmp(worker[i].type,"temporary")==0)
		{
			worker[i].gross=30*worker[i].hours;
			worker[i].net=worker[i].gross-worker[i].deductions;
		}
		else
		if(stricmp(worker[i].type,"intern")==0)
		{
			worker[i].gross=15*worker[i].hours;
			worker[i].net=worker[i].gross-worker[i].deductions;
		}
	}
}
int search(char name1[],char name2[],struct workplace worker[])
{
	int i,found=-1;
	for(i=0;i<size;i++)
	{
		if((stricmp(worker[i].fname,name1)==0)&&(stricmp(worker[i].lname,name2)==0))
		{
			found=1;
			printf("\n");
			printf("Gross salary for employee %d: $%.2f\n",i,worker[i].gross);
			printf("Net salary for employee %d: $%.2f\n",i,worker[i].net);
		}
	}
	return found;
}
main()
{
	struct workplace employee[size];
	int i,val;
	float total;
	char name1[30],name2[30];
	
	for(i=0;i<size;i++)
	{
		printf("Employee no. %d:\n",i);
		printf("Enter your first and last name.\n");
		scanf("%s%s",&employee[i].fname,&employee[i].lname);
		
		printf("What type of employee art thou?\n");
		printf("- Permanent\n- Temporary\n- Intern\n");
		scanf("%s",&employee[i].type);
		
		printf("Enter number of hours worked.\n");
		scanf("%f",&employee[i].hours);
		
		printf("Enter your deductions.\n");
		scanf("%f",&employee[i].deductions);
		printf("\n");
		pay(employee);
		
		total=total+employee[i].net;
	}
	
	printf("\nThe total overall net pay is: $%.2f\n\n",total);
	printf("To search for an emloyee, enter their first and last name:\n");
	scanf("%s%s",&name1,&name2);
	
	val=search(name1,name2,employee);
	while(val<=0)
	{
		printf("Error 403: Invalid name.\nPlease try again.\n");
		scanf("%s%s",&name1,&name2);
		val=search(name1,name2,employee);
	}
	
	system("Pause");
}
