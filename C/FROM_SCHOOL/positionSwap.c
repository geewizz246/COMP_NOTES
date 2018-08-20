/*	Write a program that includes a function swap that accepts an integer array and two integers - pos1, and pos2 - representing 
	two locations in the array. The function should swap the contents of the two locations. Assume that pos1 and pos2 are valid. 
	Print the contents of the array before the swap with positions; then print the contents of the array after swap with positions*/
#include<stdio.h>
#include<stdlib.h>
#define size 8
void swap(int num[],int pos1,int pos2)
{
	int temp;
	
	temp=num[pos1];
	num[pos1]=num[pos2];
	num[pos2]=temp;
}

main()
{
	int i,no[size],p1,p2;
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number:\t");
		scanf("%d",&no[i]);
	}
	printf("Contents of the array before swap: ");
	for(i=0;i<size;i++)
	{
		printf("%d ",no[i]);
	}
	printf("\n\nEnter two positions of the array you want to switch. (from pos 0-7)\n");
	scanf("%d%d",&p1,&p2);
	
	swap(no,p1,p2);
	
	printf("\nContents of the after array swap: ");
	for(i=0;i<size;i++)
	{
		printf("%d ",no[i]);
	}
}
