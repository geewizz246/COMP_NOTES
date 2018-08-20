#include<stdio.h>

void main()
{
	int num,days,month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	printf("Enter month number---->");
	scanf("%d",&num);
	
	days=month[num-1];
	
	printf("\nNumber of days = %d.",days);
}
