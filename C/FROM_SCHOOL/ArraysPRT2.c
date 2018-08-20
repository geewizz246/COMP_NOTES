//Write a program that reads 5 numbers into an array. Find the largest number in the array and print it.
#include<stdio.h>
#include<stdlib.h>
#define size 5

main()
{
	float num[size],max,min;
	int i;
	
	
	for(i=0;i<5;i++)
	{
		printf("Enter a number\t");
		scanf("%f",&num[i]);
	}
	
	max=num[0]; //make max 1st number in array
	min=num[0]; //make min 1st number in array

	for(i=1;i<5;i++) //don't make sense to compare 0 to itself
	{
		if(num[i]>max)
			max=num[i];
		if(num[i]<min)
			min=num[i];
	}
	
	printf("The largest number is: %.2f\n",max);
	printf("The smallest number is: %.2f\n",min);
}
