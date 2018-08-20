/*C program to print ASCII values of all characters*/
#include<stdio.h>

void main()
{
	int i;
	
	/*Print all 255 ASCII values*/
	for(i=0;i<=255;i++)
	{
		printf("ASCII value of character %c = %d\n",i,i);
	}//endfor
}
