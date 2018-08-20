/*read 5 numbers and store them in an array
Display the following options 
1. Add numbers to array
2. Sort numbers using Bubblesort
3.Sort numbers using Selectionsort
4.Search for numbers using BinarySearch
5.Exit
*/
#include<stdio.h>
#include<stdlib.h>
#define size 5
int menu()
{
	int task;
	printf("1. Add numbers to the array\n");
	printf("2. Sort the numbers using a Bubble sort\n");
	printf("3. Sort the numbers using a Selection sort\n");
	printf("4. Search for a number using Binary Search\n");
	printf("5. Exit\n");
	
	scanf("%d",&task);	
	return task;
}
void bubbleSort(int array[],int num[])
{
	int i,temp,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j+1];
				num[j+1]=num[j];
				num[j]=temp;
			}
		}
	}
	
	printf("Initial array\n");
	for(j=0;j<size;j++)
	{
		printf("%d\t",array[j]);
	}
	printf("\n");
	
	printf("Sorted array\n");			
	for(j=0;j<size;j++)
	{
		printf("%d\t",num[j]);
	}
	printf("\n");
}
void selectionSort(int array[],int num[])
{
	int index,j,k,tempStore;
	
	for(j=0;j<size-1;j++)
	{
		index=j;
		
		for(k=(j+1);k<size;k++)
		{
			if(num[k]<num[index])
				index=k;
		}
		
		tempStore=num[index];
		num[index]=num[j];
		num[j]=tempStore;
	}
	
	printf("Initial array\n");
	for(j=0;j<size;j++)
	{
		printf("%d\t",array[j]);
	}
	printf("\n");
	
	printf("Sorted array\n");			
	for(j=0;j<size;j++)
	{
		printf("%d\t",num[j]);
	}
	printf("\n");
}
void binarySearch(int num[])
{
	int val,mid,upp,lwr,found;
	
	upp=size;
	lwr=0;
	found=0;
		
	printf("Enter the number you wish to search for\n");
	scanf("%d",&val);
	
	while((upp>=lwr)&&(found!=1))
	{
		mid=(lwr+upp)/2;
		
		if(num[mid]>val)
		{
			upp=mid-1;
		}
		if(num[mid]<val)
		{
			lwr=mid+1;
		}
		if(num[mid]==val)
		{
			printf("Search Successful.Found %d at position %d\n",num[mid],mid);
			found=1;
		}
	}
	if(found==0)
	{
		printf("%d was not found. Search unsuccessful\n",val);
	}
}
void addNum(int num[],int array[])
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("Enter a number\n");
		scanf("%d",&num[i]);
		array[i]=num[i];
	}
}
main()
{
	int j,num[size],task,array[size];
	
	addNum(num,array);
	printf("Initial array\n");
	for(j=0;j<size;j++)
	{
		printf("%d\t",array[j]);
	}
	printf("\n");
	
	task=menu();
	while(task!=5)
	{
		if(task==1)
		{
			addNum(num,array);
			printf("Initial array\n");
			for(j=0;j<size;j++)
			{
				printf("%d\t",array[j]);
			}
			printf("\n");
		}
		if(task==2)
		{
			bubbleSort(array,num);
		}
		if(task==3)
		{
			selectionSort(array,num);
		}
		if(task==4)
		{
			binarySearch(num);
		}
		if((task>5)||(task<1))
		{
			printf("That was not one of the options\n");
			printf("Please try again\n");
		}
		printf("\n\n");
		task=menu();
	}
}
