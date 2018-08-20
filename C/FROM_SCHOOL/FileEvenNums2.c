/*Write C code to read the integers from "num.dat".
Add 5 to each integer and print the results to a screen*/

#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE*pointer;
	int num;
	
	pointer=fopen ("num.dat","r");
	
	if(pointer==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		fscanf(pointer,"%d",&num);
		while(!feof(pointer))
		{
			num=num+5;
			printf("%d\n",num);
			fscanf(pointer,"%d",&num);
		}
	}
	fclose(pointer);
}
