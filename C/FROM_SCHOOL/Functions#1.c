//Write a program that finds the sum of two numbers and print it. Include at least one function.
#include<stdio.h>
#include<stdlib.h>
	// functions are written first
	// function to find the sum of two numbers
	
int	findSum(int num1, int num2)
{
	int sum; //local variable
	sum=num1+num2;
	
	return sum;	//the sum is returned to main
}//end findSum

// function to print the sum of the two numbers
void printSum(int num1, int num2, int sum)//this function will NOT return a value
{
	printf("The sum of %d and %d is: %d.\n",num1,num2,sum);
	
}//end printSum
//main function begins
main()
{
	int no1,no2,sumOfNum;
	
	printf("Enter two numbers.\n");
	scanf("%d%d",&no1,&no2);
	
	sumOfNum=findSum(no1,no2); //call to function findSum
	printSum(no1,no2,sumOfNum); //call to function printSum
} //end program
