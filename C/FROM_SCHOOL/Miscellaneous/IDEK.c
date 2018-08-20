#include<stdio.h>
#include<stdlib.h>

#define size 5

int a[size],aSort[size];

int menu()
{
	int ans;
	
	printf("===================================================\n\n");
	printf(" OPTION                 DESCRIPTION                \n\n");
	printf("===================================================\n\n\n");
	printf("    1.        Add nos. to array\n");
	printf("    2.        Sort nos. using Bubble Sort\n");
	printf("    3.        Sort nos. using Selection Sort\n");
	printf("    4.        Search for no. using Binary Search\n");
	printf("    5.        Exit\n\n");
	
	/''printf("Task---->")	scanf("%d",&ans);
	
	printf("\n\n\n\n");
	
	return ans;
}

void addNum(int a[size])
{
	int i;
	printf("Enter %d numbers:\n",size);
	for(i=0;i<size;i++)
	{
		printf("num[%d]---->",i);
		scanf("%d",&a[i]);
		aSort[i]=a[i];
	}
	printf("\n\n\n\n");
}

void bubbleSort(int a[size], int aSort[size])
{
	int i,pass,count,temp;
	
	printf("ORIGINAL ARRAY:\n");
	for(i=0;i<size;i++)
	{
		printf("num[%d] = %d\n",i,a[i]);
	}
	
	printf("\n\nSorting...\n\n\n");
	for(pass=0;pass<size-1;pass++)
	{
		for(count=0;count<size-1;count++)
		{
			if(aSort[count]>aSort[count+1])
			{
				temp=aSort[count];
				aSort[count]=aSort[count+1];
				aSort[count+1]=temp;
			}
		}
	}
	
	printf("SORTED ARRAY:\n");
	for(i=0;i<size;i++)
	{
		printf("num[%d] = %d\n",i,aSort[i]);
	}
	printf("\n\n\n\n");
}

void selectionSort(int a[size], int aSort[size])
{
	int i,k,j,index,hold;
	
	printf("ORIGINAL ARRAY:\n");
	for(i=0;i<size;i++)
	{
		printf("num[%d] = %d\n",i,a[i]);
	}
	
	printf("\n\nSorting...\n\n\n");
	for(k=0;k<size-1;k++)
	{
		index=k;
		
		for(j=(k+1);j<size;j++)
		{
			if(aSort[j]<aSort[index])
				index=j;
		}
		
		/*swap*/
		
		hold=aSort[index];
		aSort[index]=aSort[k];
		aSort[k]=hold;
	}
	
	printf("SORTED ARRAY:\n");
	for(i=0;i<size;i++)
	{
		printf("num[%d] = %d\n",i,aSort[i]);
	}
	printf("\n\n\n\n");
}

void binarySearch(int aSort[size])
{
	int upp,lwr,val,mid,found;
	upp=size-1;
	lwr=0;
	found=0;
	
	printf("Enter the number you wish to search for--->");
	scanf("%d",&val);
	
	while((upp>=lwr)&&(found!=1))
	{
		mid=(lwr+upp)/2;
		
		if(aSort[mid]>val)
		{
			upp=mid-1;
		}
		if(aSort[mid]<val)
		{
			lwr=mid+1;
		}
		if(aSort[mid]==val)
		{
			printf("\n\nSearch successful. num[%d] = %d\n\n",mid,val);
			found=1;
		}
	}
	if(found==0)
	{
		printf("\n\n%d was not found. Search unsuccessful\n",val);
	}
	printf("\n\n\n\n");
}

int main()
{
	int task;
	
	task=menu();
	
	while(task!=5)
	{
		if(task==1)
		{
			addNum(a);
		}
		
		if(task==2)
		{
			bubbleSort(a,aSort);
		}
	
		if(task==3)
		{
			selectionSort(a,aSort);
		}
		
		if(task==4)
		{	
			binarySearch(aSort);
		}
		
		task=menu();
	}
	
	if(task==5)
	{
		printf("\n\nProgram end\n\n");		
	}
}
