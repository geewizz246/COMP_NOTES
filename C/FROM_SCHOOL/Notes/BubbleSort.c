#include<stdio.h>
#include<stdlib.h>
#define size 10

void main()
{
	/*for purposes of this program an array initialiser would be used to
	assign random values to the array numbers*/
	int numbers[size]={23,6,11,56,78,2,1,0,22,2};
	int pass, count, hold, i;
	
	//BUBBLE SORT BEGINS
	for(pass=0;pass<size-1;pass++)//this is how many times the program goes through the array
	{
		for(count=0;count<size-1;count++)/*loop uses count as an index to go through array*/
		{
			if(numbers[count]>numbers[count+1])
			{
				hold=numbers[count];
				numbers[count]=numbers[count+1];
				numbers[count+1]=hold;
			}//end if
		}//end for
	}//end for
	
	//PRINTING SORTED VALUES
	for(i=0;i<size;i++)
	{
		printf("number[%d] = %d\n",i,numbers[i]);
	}//end for
}//end program
