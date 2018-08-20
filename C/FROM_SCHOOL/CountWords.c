#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
main()

{
	char sentence[size];
	int numSpaces,numWords,i;
	
	numSpaces=0;
	numWords=0;
	
	printf("Enter a sentence.\n\n");
	gets(sentence);
	
	for(i=0;sentence[i]!=0;i++)
	{
		if(sentence[i]==' ')
			numSpaces++;
		if(sentence[i]=='.')
			numWords++;
		if(sentence[i]==',')
			numWords++;
		if(sentence[i]=='?')
			numWords++;
		if(sentence[i]=='!')
			numWords++;
		if(sentence[i]==';')
			numWords++;
	}
	numWords=numWords+numSpaces;
	
	printf("The number of words in  your sentence is: %d\n",numWords);
	
}
