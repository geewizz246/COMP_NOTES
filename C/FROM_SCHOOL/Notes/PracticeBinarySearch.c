#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
	int array[size]={3,9,15,21,47,62,66,78,80,95};
	int key,found,first,last,mid;
	
	printf("Enter the integer that you wish to find---->");
	scanf("%d",&key);
	
	found=0;
	first=0;
	last=size-1;
	
	mid=(first+last)/2;
	
	while((last>=first)&&(found!=1))
	{
		if(array[mid]>key)
			last=mid-1;
			
		if(array[mid]<key)
			first=mid+1;
		
		if(array[mid]==key)
			found=1;
			
		mid=(first+last)/2;
	}
	
	if(found==0)
		printf("\nSEARCH UNSUCCESSFUL\n\n");
	else
		printf("\nInteger, %d, found in position %d\n\n",key,mid);
}
