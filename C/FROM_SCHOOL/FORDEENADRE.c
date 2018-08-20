#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	FILE*p1;
	char str[60];
	
	p1=fopen("meh.txt","r");
	if(p1==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	
	if(fgets(str,60,p1)!=NULL)
		printf("File not empty\n");
	else
		printf("File empty\n");
	
	fclose(p1);
}
