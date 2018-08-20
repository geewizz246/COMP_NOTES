#include<stdio.h>
#include<stdlib.h>
#include<string.h> //open a new library for strings functions
#define size 100 //so the string can hold up to 99 characters
main()

{
	char word[size];
	int length;
	
	printf("Enter a word of your choice.\n");
	scanf("%s",&word);
	
	length=strlen(word); //strlen will read & count the number of characters in the word
	
	printf("The length of the word is: %d\n",length);
	
	system("Pause"); //NB: A SYSTEM PAUSE IS NOT NECESSARY FOR THIS COMPILER
}

