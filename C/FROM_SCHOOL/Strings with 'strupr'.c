#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char sentence[50];
	
	printf("Enter a sentence.\n");
	gets(sentence);
	
	strupr(sentence); //strupr converts the string to UPPERCASE
	
	printf("Sentence in uppercase is: %s\n\n",sentence);
	
}
