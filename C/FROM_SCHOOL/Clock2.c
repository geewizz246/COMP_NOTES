/*b)Write and test a function to input two clock times in a 24-hour clock format and return the difference between the times. 
    Cater for the fact that it does not matter the order in which the two times appear as parameters in the formal parameter list.
*/

#include<stdio.h>
#include<stdlib.h>

int timeDiff(float time1,float time2,float diff)
{
	if(time1>time2)
	{
		diff=time1-time2;
		if(diff<10)
		{
			printf("The difference between the two times is 0%.2f",diff);
		}
		else
		printf("The difference between the two times is %.2f",diff);
		
	}
	else
	{
		diff=time2-time1;
		if(diff<10)
		{
			printf("The difference between the two times is 0%.2f",diff);
		}
		else
		printf("The difference between the two times is 0%.2f",diff);
	}
}
main()
{
	float time1,time2,diff;
	
	printf("Enter two clock times in the 24-hour clock format\n");
	scanf("%f %f",&time1,&time2);
	
	timeDiff(time1,time2,diff);
}
