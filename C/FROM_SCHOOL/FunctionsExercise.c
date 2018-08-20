/*Write a program that reads two numbers. It should:
	(a)calculate the sum, 
	(b)calculate the product, 
	(c)calculate the average,
	(d)print all of the above. */
#include<stdio.h>
#include<stdlib.h>
//function to add numbers
int	findSum(int a,int b)
{
	int sum;//local variable
	sum=a+b;
	return sum;
}
//function to multiply numbers
int findProd(int a,int b)
{
	int prod;
	prod=a*b;
	return prod;
}
//function to calculate average
float findAvg(float a,float b)
{
	float avg;
	avg=(a+b)/2;
	return avg;
}
//function to print sum
void printSum(int sum)//this function will NOT return a value
{
	printf("Sum is: %d.\n",sum);
}
//function to print product
void printProd(int prod)
{
	printf("Product is: %d.\n",prod);
}
//function to print average
void printAvg(float avg)
{
	printf("Average is: %.2f.\n",avg);
}
main()

{
	int num1,num2,sumNum,prodNum;
	float avgNum;
	printf("Enter two numbers.\n");
	scanf("%d%d",&num1,&num2);
	
	sumNum=findSum(num1,num2); 
	prodNum=findProd(num1,num2);
	avgNum=findAvg(num1,num2);
	
	printSum(sumNum);
	printProd(prodNum);
	printAvg(avgNum);
}
