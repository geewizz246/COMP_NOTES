/*Write a program that reads 10 numbers into an array called num. Also accept an integer t from the user and search 
the array if this t is present. If found print the location of t, otherwise print t not found. Use function.*/
#include<stdio.h>
#include<stdlib.h>
#define size 10
void findNum(int array[],int num)
{	
	int found=0,i;
	
	if(array[0]==num)
	{
		found++;
		printf("The number was found in location 0");
	}
	for(i=1;i<size;i++)
	{
		if(array[i]==num)
		{
			found++;
			printf(", %d",i);
		}
	}
	
	if(found==0)
	{
		printf("The number entered was not found in the array.\n");
	}
}

main()
{
	int no[size],t,i;
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number:\t");
		scanf("%d",&no[i]);
	}
	
	printf("\nEnter a number to find in the array:\t");
	scanf("%d",&t);
	
	findNum(no,t);
}
