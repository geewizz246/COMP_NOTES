/*	A program is required to read five elements into an integer array called num. Create functions that:
	a) find the minimum number in the array 
    b) finds the maximum number in the array 
	c) Find the sum of the numbers in the array that are less than 50 */
#include<stdio.h>
#include<stdlib.h>
#define size 5

int findMin(int numArray[])
{
	int min,i;
	min=numArray[0];
	
	for(i=1;i<size;i++)
	{
		if(numArray[i]<min)
		{
			min=numArray[i];
		}
	}
	return min;
}

int findMax(int numArray[])
{
	int max,i;
	max=numArray[0];
	
	for(i=1;i<size;i++)
	{
		if(numArray[i]>max)
		{
			max=numArray[i];
		}
	}
	return max;
}

int findSum(int numArray[])
{
	int sum,i;
	sum=0;
	for(i=0;i<size;i++)
	{
		if(numArray[i]<50)
		{
			sum=sum+numArray[i];
		}
	}
	return sum;
}
void printResults(int min,int max,int sum)//this function will NOT return a value
{
	printf("Min is: %d.\n",min);
	printf("Max is: %d.\n",max);
	printf("Sum is: %d.\n",sum);
}

main()
{
	int i,num[size],maxNum,minNum,sumNum;
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number.\t");
		scanf("%d",&num[i]);
	}
	
	minNum=findMin(num);
	maxNum=findMax(num);
	sumNum=findSum(num);
	printResults(minNum,maxNum,sumNum);
}
