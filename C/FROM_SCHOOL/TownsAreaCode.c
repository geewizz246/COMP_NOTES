/*
Write a program to input and store in an array 10 records that contain the names of towns and their corresponding telephone area codes for Scotland.
Include a function to search for the name of a town when given an area code. Display the result of the search. 
Exit the program on the input of an illegal area code. NB YOU HAVE TO PASS A STRUCTURE TO A FUNCTION
eg:
#include<stdio.h>
#include<stdlib.h>
struct results //so declare the struct before main
{
	char name1[25];
	char name2[25];
	char form[10];
	float math,english;
	float avg;		
};
void print(struct students stud[])
{
	int i;
*/
#include<stdio.h>
#include<stdlib.h>
#define size 2
struct Scotland
{
	char town[25];
	int code;
};

int findTown(int area, struct Scotland name[])
{
	int i,found;
	found=-1;
	
	for(i=0;i<size;i++)
	{
		if(area==name[i].code)
		{
			found=1;
			printf("The area code entered belongs to %s.\n",name[i].town);
		}
	}
	if(found==-1)
		printf("Nah nigga you stupid.\n");
		exit(0);
}

main()
{
	struct Scotland name[size];
	int i,code;
	
	for(i=0;i<size;i++)
	{
		printf("Enter name of town.\n");
		scanf("%[^\n]s",&name[i].town);
		
		printf("Enter corresponding telephone area code.\n");
		scanf("%d",&name[i].code);
	}
	
	printf("\nEnter area code of town you wish to locate.\n");
	scanf("%d",&code);
	
	findTown(code,name);	
}
