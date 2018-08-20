
#include<stdio.h>
#include<stdlib.h>
#define size 30

main()
{
	char alphabet[size]="abcdefghijklmnopqrstuvwxyz";
	int i;
	
	printf("The entire alphabet:\t");
	puts(alphabet);
	
	printf("The first six letters of the alphabet:\t");
	for(i=0;i<6;i++)
	{	
		printf("%c",alphabet[i]);
	}
	
	printf("\n");
	printf("The last ten letters of the alphabet:\t");
	for(i=16;alphabet[i]!=0;i++)
	{
		printf("%c",alphabet[i]);
	}
	printf("\n");
	printf("The tenth character of the alphabet: \t%c",alphabet[9]);
}
