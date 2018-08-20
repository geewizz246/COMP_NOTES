#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char sentence[50];
	
	printf("Enter a sentence.\n");
	gets(sentence);
	
	strlwr(sentence); //strlwr converts the string to lowercase
	
	printf("Sentence in uppercase is: %s\n\n",sentence);
	
}
