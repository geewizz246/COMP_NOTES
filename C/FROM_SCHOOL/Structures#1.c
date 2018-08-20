/* Write a program to store the names of foods and their prices as a record. Print the name of the food and its associative price. 
The following program will have one record. */
#include<stdio.h>
#include<stdlib.h>

main()
{
	struct supermarket
	{
		char name[25];
		float price;
	};
	
	struct supermarket item;
	
	printf("Enter the name of the item.\n");
	scanf("%s",&item.name); /*dot operator reads input into name[25] of struct supermarket*/
	printf("Enter the price of the item.\n");
	scanf("%f",&item.price); /*dot operator reads input into price of struct supermarket*/
	
	printf("%s is $%.2f.\n",item.name,item.price);
	
}
