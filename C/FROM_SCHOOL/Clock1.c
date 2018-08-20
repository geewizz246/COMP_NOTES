/*a)Write and test a function to input the time of day in 12-hour clock format, and whether it is am or pm, and return 
    the time in a 24-hour clock format
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convertTime(float time,char timeDay[])
{
	if(stricmp(timeDay,"am")==0)
	{
		if(time<10)
		{
			printf("Time in 24-hour format: 0%.2f",time);
		}
		else
		printf("Time in 24-hour format: %.2f",time);
	}
	else
	if(stricmp(timeDay,"pm")==0)
	{
		time=time+12;
		printf("Time in 24-hour format: %.2f",time);
	}	
	return time;
}
main()
{
	float time;
	char timeDay[2];
	
	printf("Enter the time of day in the 12-hour clock format\n");
	scanf("%f",&time);
	
	printf("Enter if the time entered is am or pm\n");
	scanf("%s",&timeDay);
	
	convertTime(time,timeDay);
}
