/*C program to find length of string*/

#include<stdio.h>
#include<string.h>

void main()
{
	int length;
	char string[50];
	
	printf("Enter a word---->");
	scanf("%s",&string);
	
	length=strlen(string);
	
	printf("\nString is %d characters long.\n",length);
}
