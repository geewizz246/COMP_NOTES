//Write a program that reads five numbers into a function. 
//It should then calculate the minimum value stored in the array (using a function).
// It should also print this value.
#include<stdio.h>
#include<stdlib.h>
#define size 5 //size of the array

//function to find minimum value
int findMin(int num[]) //notice that the function takes in the array.
                       //notice that the size of the array is not written in the square brackets.
{
	int i,min; //local variables
	
	min=9999;
	for(i=0;i<size;i++)
	{
		if(num[i]<min)
			min=num[i];
	} //end for

	return min; /*the min value in the array is returned to the part of the
				program tha called findMin*/
} //end findMin

main()
{
	int result,i,nums[size];
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number ---> ");
		scanf("%d",&nums[i]);
	} //end for
	
	result=findMin(nums);  /*call to function findMin that returns the min value which is stored in the variable result.
							Notice that ONLY THE NAME OF THE ARRAY is passed to the function*/
	
	printf("Minimum value is: %d",result);
	
}
