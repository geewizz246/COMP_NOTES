/*Write C code to store the even numbers from 2 inclusive to 40 
inclusive to a file called "num.dat".*/

#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE*pointer;
	int num=2;
	
	pointer=fopen ("num.dat","a");
	
	if(pointer==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		printf("%d\n",num);
		fprintf(pointer,"%d\n",num);
		while(num<=40)
		{
			num=num+2;
			printf("%d\n",num);
			fprintf(pointer,"%d\n",num);
		}
	}
	
	fclose(pointer);
	
}
