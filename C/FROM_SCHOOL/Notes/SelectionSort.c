#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
	/*for purposes of this program an array initialiser would be used to
	assign random values to the array numbers*/
	int numbers[size]={123,6,11,56,78,2,1,0,22,2};
	int index, temp, i, j;
	
	//SELECTION SORT BEGINS
	for(i=0;i<size-1;i++)//this is how many times the program goes through the array
	{//the value of i tells you where the search area starts
		index=i;//index is the lower limit of the search
		
		for(j=(i+1);j<size;j++)/*loop goes through array to find smallest element in search area*/
		{
			if(numbers[j]<numbers[index])/*if an element in the array is less than an element
										 at the beginning of the search*/
				index=j;
		}
		
		//SWAP VALUES
		temp=numbers[index];
		numbers[index]=numbers[i];
		numbers[i]=temp;
	}//end for
	
	//PRINTING SORTED VALUES
	for(i=0;i<size;i++)
	{
		printf("number[%d] = %d\n",i,numbers[i]);
	}//end for
}//end program
