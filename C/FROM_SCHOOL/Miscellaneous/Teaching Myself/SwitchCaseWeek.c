/*C program to print day of week name using switch case*/

#include<stdio.h>

void main()
{
	int week;
	
	printf("Enter week number (1-7): ");
	scanf("%d",&week);
	
	switch(week)
	{
		case 1: printf("MONDAY\n");
			break;
		case 2: printf("TUESDAY\n");
			break;
		case 3: printf("WENDESDAY\n");
			break;
		case 4: printf("THURSDAY\n");
			break;
		case 5: printf("FRIDAY\n");
			break;
		case 6: printf("SATURDAY\n");
			break;
		case 7: printf("SUNDAY\n");
			break;
		default: printf("Invalid input! Please eneter week number between 1-7.\n");
	}
}
