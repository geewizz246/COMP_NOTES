/*C program to check even or odd number using switch case*/

#include<stdio.h>

void main()
{
	int num;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	switch(num%2)
	{
		//if num%2==0
		case 0: printf("EVEN\n");
			break;
		//if num%2==1
		case 1: printf("ODD\n");
			break;
	}
}
