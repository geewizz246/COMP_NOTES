/*C program to calculate factorial of a number*/

#include<stdio.h>

//Function to calculate factorial
int factorial(int n)
{
	int fact=1;
	while(n>=1)
	{
		fact*=n;
		n--;
	}//endwhile
	
	return fact;
}//end factorial

void main()
{
	int num;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	printf("\nFactorial = %d\n",factorial(num));	
}
