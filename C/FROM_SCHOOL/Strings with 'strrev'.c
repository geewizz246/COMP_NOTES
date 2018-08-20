#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
main()

{
	char word[size];
	
	printf("Enter a word of your choice.\n");
	scanf("%s",&word);
	strrev(word); //reverses a word
		
	printf("The word reversed is: %s\n\n",word);
	
	system("Pause"); //NB: A SYSTEM PAUSE IS NOT NECESSARY FOR THIS COMPILER
}

