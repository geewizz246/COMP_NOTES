/*C program to find length of string*/

#include<stdio.h>

void main()
{
	int i=0;
	char string[50];
	
	printf("Enter a word---->");
	scanf("%s",&string);
	
	while(string[i]!='\0')
	{
		i++;
	}
	
	printf("\nString is %d characters long.\n",i);
}
