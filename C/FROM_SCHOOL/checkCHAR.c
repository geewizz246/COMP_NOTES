#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char ch,phrase[30]="CAPECOMPUTERSCIENCE";
	int i,count;
	
	count=0;
	printf("Enter a letter:\t");
	scanf("%c",&ch);
	
	for(i=0;phrase[i]!=0;i++)
	{
		strlwr(phrase);
		if(ch==phrase[i])
			count++;
	}
	
	strupr(phrase);
	for(i=0;phrase[i]!=0;i++)
	{
		if(ch==phrase[i])
			count++;
	}
	
	if(count>0)
		printf("The character occurs %d times in '%s'.\n",count,phrase);
	else
		printf("There are no occurrances of the letter in '%s'.\n",phrase);
}
