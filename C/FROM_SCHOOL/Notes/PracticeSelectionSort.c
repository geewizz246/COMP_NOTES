#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
	int array[size]={74,52,9,0,21,66,83,38,47,5};
	int temp,i,j,index;
	
	for(i=0;i<size-1;i++)
	{
		index=i;
		
		for(j=(i+1);j<size;j++)
		{
			if(array[j]<array[index])
				index=j;
		}
		
		temp=array[index];
		array[index]=array[i];
		array[i]=temp;
	}
	
	for(i=0;i<size;i++)
	{
		printf("pos. [%d] = %d\n",i,array[i]);
	}
}
