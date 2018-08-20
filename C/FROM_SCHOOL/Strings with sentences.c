#include<stdio.h>
#include<stdlib.h>
#include<string.h> //open a new library for strings functions
#define size 100 //so the string can hold up to 99 characters
main()

{
	char sentence[size];
	int numLetters,i;
	
	numLetters=0;
	printf("Enter a sentence.\n");
	gets(sentence);
	
	for(i=0;sentence[i]!=0;i++) //start with zero, keep adding 1 i WHILE 'sentence[i]!=0'; THEREFORE the for loop will stop when 'sentence[i]=0'.
	{
		if (sentence[i]!=' ') //if sentence[i] is NOT EQUAL to a space; when checking for something that only takes up one space use single quotes.
			numLetters=numLetters+1; //or numLetters++
	}
	
	printf("The number of letters in the sentence is: %d\n\n",numLetters);	
}
