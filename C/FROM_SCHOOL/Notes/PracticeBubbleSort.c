#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
	int array[size]={74,52,9,0,21,66,83,38,47,5};
	int pass,i,j,hold;
	
	for(pass=0;pass<size-1;pass++)
	{
		for(i=0;i<size-1;i++)
		{
			if(array[i]>array[i+1])
			{
				hold=array[i];
				array[i]=array[i+1];
				array[i+1]=hold;
			}
		}
		
		if(pass==0)
		{
			for(j=0;j<size;j++)
			{
				printf("pos. [%d] = %d\n",j,array[j]);
			}
		}
	}
	
	for(j=0;j<size;j++)
	{
		printf("pos. [%d] = %d\n",j,array[j]);
	}
}
