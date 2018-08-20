#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char ch[1],phrase[30]="CAPECOMPUTERSCIENCE";
	int i,count;
	
	count=0;
	printf("Enter a letter:\t");
	scanf("%c",&ch);
	
	strupr(ch);	
	for(i=0;phrase[i]!=0;i++)
	{
		if(ch[0]==phrase[i])
			count++;
	}
	
	if(count>0)
		printf("The character occurs %d times in '%s'.\n",count,phrase);
	else
		printf("There are no occurrances of the letter in '%s'.\n",phrase);
}
