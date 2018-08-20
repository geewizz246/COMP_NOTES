/*C program to create simple calculator using switch case*/

#include<stdio.h>

void main()
{
	char op;
	float n1, n2, result=0;
	
	printf("WELCOME TO SIMPLE CALCULATOR\n");
	printf("----------------------------\n");
	printf("Enter [number 1] [+ - * /] [number 2] ---->");
	scanf("%f %c %f",&n1,&op,&n2);
	
	switch(op)
	{
		case '+': result=n1+n2;
			break;
		case '-': result=n1-n2;
			break;
		case '*': result=n1*n2;
			break;
		case '/': result=n1/n2;
			break;
		default: printf("Invalid operator\n");
	}
	
	//print results
	printf("\n%.2f %c %.2f = %.2f\n\n",n1,op,n2,result);
}
