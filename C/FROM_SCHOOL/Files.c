#include<stdio.h>
#include<stdlib.h>
main()
{
	FILE*fptr;
	char name[25];
	
	fptr=fopen("nameFile","w");
	
	if(fptr==NULL)
	{
		printf("ERROR OPENING FILE\n");
	}
	else
	{
		printf("Enter a name\n");
		scanf("%s",&name);
		fprintf(fptr,"%s\n",name);
	}
	fclose(fptr);
}
