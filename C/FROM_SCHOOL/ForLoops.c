#include<stdio.h>
#include<stdlib.h>

#define size 10 //constant
main()

{
	int num,i,count;
	
	count=0;
	
	for(i=0;i<10;i++) //i++ means i=i + 1. NB:- FOR LOOPS START AT ZERO (0), 0 to 9 equals 10 values
	{
		printf("Enter a number\n");
		scanf("%d",&num);
		
		if((num>=1)&&(num<=50)) //&& is AND in C
		{
			count=count+1; //OR count++
		}//EndIf
	}//EndFor
	
	printf("\n\n");
	printf("There are %d numbers between 1 and 50 inclusive.\n",count);
	
	system("Pause");
}
