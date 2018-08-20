/*	
	Write a program that reads the name, age and amount of money. 
	Write this information to a file called student info.
	Edit the above program to allow 5 records to be entered. 
	Then edit it to print the values.
*/
#include<stdio.h>
#include<stdlib.h>
#define size 2
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
		for(i=0;i<size;i++)
		{
			printf("Enter a name\n");
			scanf("%s",&name);
		
			printf("Enter the age\n");
			scanf("%d",&age);
		
			printf("Enter the amount of money in the bank\n");
			scanf("%f",&money);
			printf("\n");
			fprintf(info,"%s\t%d\t%f\n",name,age,money);
		}
	}
	fclose(info);
	
	info=fopen("studentInfo.txt","r");
	
	if(info==NULL)
	{
		printf("ERROR OPENING FILE\n");
	}
	else
	{
		fscanf(info,"%s%d%f",&name,&age,&money);
		while(!feof(info))
		{
			printf("------------------------------------\n");
			printf("The name is %s\n",name);
			printf("The age is %d\n",age);
			printf("The balance is %f\n",money);
			fscanf(info,"%s%d%f",&name,&age,&money);
		}
	}
}
