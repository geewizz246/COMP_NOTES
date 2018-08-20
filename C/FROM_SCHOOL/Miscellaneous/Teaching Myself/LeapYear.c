/* C program to check leap year*/

#include<stdio.h>

void main()
{
	int year;
	
	printf("Enter year: ");
	scanf("%d",&year);
	
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
		printf("\n%d is a leap year.\n",year);
	else
		printf("\n%d is not a leap year.\n",year);
}
