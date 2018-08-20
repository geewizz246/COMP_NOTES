/* Write a program to store the names of foods and their prices as a record. Print the name of the food and its associative price. 
Consider how this program will be modified to allow multiple records to be stored.*/
#include<stdio.h>
#include<stdlib.h>
#define size 5

main()
{
	struct supermarket
	{
		char name[25];
		float price;
	};
	
	struct supermarket item[size]; /*an array of records*/
	int i;
	
	for(i=0;i<size;i++)
	{
		printf("Enter the name of the item.\n");
		scanf("%s",&item[i].name); /*dot operator reads input into name[25] of struct supermarket*/
		printf("Enter the price of the item.\n");
		scanf("%f",&item[i].price); /*dot operator reads input into price of struct supermarket*/
	}
	
	printf("\n");
	for(i=0;i<size;i++)
	{	
		printf("%s is $%.2f.\n",item[i].name,item[i].price);
	}
	
	printf("\n--------------------***********---------------------");
}
