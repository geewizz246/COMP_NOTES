#include<stdio.h>
#include<stdlib.h>
#define size 10
main()

{
	int num,i;
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number\n");
		scanf("%d",&num);
		
		if((num==4)||(num==6)) //'=' ASSIGNS A NUMBER WHILE '==' ASKS ABOUT EQUALITY; '||' IS THE OPERATOR FOR OR
			printf("*\n"); // '{}' are only necessary when having an 'else' involved
				
	}//EndFor
	system("Pause");

}
