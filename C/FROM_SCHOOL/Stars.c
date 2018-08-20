#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char stars[20]="**********";
	int i,length;
	
	length=strlen(stars);
	
	for(i=0;i<10;i++)
	{
		puts(stars);
		length=length-1;
		stars[length]=' ';
	}
}
