/*	Write a program that includes a function swap that accepts an integer array and two integers - pos1, and pos2 - representing 
	two locations in the array. The function should swap the contents of the two locations. Assume that pos1 and pos2 are valid. 
	Print the contents of the array before the swap with positions; then print the contents of the array after swap with positions*/
#include<stdio.h>
#include<stdlib.h>
#define size 8

void swap(int num[])
{
	int temp;
	
	temp=num[1];
	num[1]=num[3];
	num[3]=temp;
}
main()
{
	int i,no[size];
	for(i=0;i<size;i++)
	{
		printf("Enter a number:\t");
		scanf("%d",&no[i]);
	}
	printf("Positions of %d and %d before swap: ",no[1],no[3]);
	for(i=0;i<size;i++)
	{
		printf("%d ",no[i]);
	}
	printf("\nPositions of %d and %d after swap: ",no[1],no[3]);
	swap(no);
	for(i=0;i<size;i++)
	{
		printf("%d ",no[i]);
	}
}
