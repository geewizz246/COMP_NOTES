#include<stdio.h>
#include<stdlib.h>
#define size 10
main()
{
	int a[size],i,j,temp;
	
	for(i=0;i<size;i++)
	{
		printf("Enter an integer\n");
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}
	
	int val,mid,upp,lwr,found;
	upp=size-1;
	lwr=0;
	found=0;
		
	printf("Enter the number you wish to search for\n");
	scanf("%d",&val);
	
	while((upp>=lwr)&&(found!=1))
	{
		mid=(lwr+upp)/2;
		printf("The middle of the search area is %d\n",mid);
		printf("Val at position %d is %d\n",mid,a[mid]);
		
		if(a[mid]>val)
		{
			upp=mid-1;
			printf("%d is greater than %d\n",a[mid],val);
			printf("Go left\n");
		}
		if(a[mid]<val)
		{
			lwr=mid+1;
			printf("%d is less than %d\n",a[mid],val);
			printf("Go right\n");
		}
		if(a[mid]==val)
		{
			printf("Search Successful\n");
			found=1;
		}
	}
	if(found==0)
	{
		printf("We have examined ALL portions of the area and %d was not found. Search unsuccessful\n",val);
	}
}
