#include<stdio.h>
#include<stdlib.h>

void main()
{
	int years,weeks,days;
	
	printf("Enter number of days: ");
	scanf("%d",&days);
	printf("\n");
	
	years=days/365;
	weeks=(days%365)/7;
	days=days-((years*365)+(weeks*7));
	
	printf("%d year/s, %d week/s, %d day/s.",years,weeks,days);
}
