/*	
	Write a program that reads the name, age and amount of money. 
	Write this information to a file called student info.
	Edit the above program to allow 5 records to be entered. 
*/
#include<stdio.h>
#include<stdlib.h>
main()
{
	FILE*info;
	char name[20];
	int age;
	float money;
	
	int i;
	
	info=fopen("studentInfo.txt","a");
	
	if(info==NULL)
	{
		printf("ERROR OPENING FILE\n");
	}
	else
	{
		for(i=0;i<5;i++)
		{
			printf("Enter a name\n");
			scanf("%s",&name);
		
			printf("Enter the age\n");
			scanf("%d",&age);
		
			printf("Enter the amount of money in the bank\n");
			scanf("%f",&money);
			fprintf(info,"%s%d%f\n",name,age,money);
		}
	}
	fclose(info);
}
