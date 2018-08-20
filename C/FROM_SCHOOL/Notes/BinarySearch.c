#include<stdio.h>
#include<stdlib.h>
#define length 10

void main()
{
	int last, mid, found, key, first;
	int num[length]={3,7,8,9,12,21,23,56,78,99};//array already sorted
	
	printf("Enter the number you would like to search for: ");
	scanf("%d",&key);
	
	//BINARY SEARCH CODE BEGINS
	first=0;//first is initially assigned the first index in the array
	last=(length-1);//last is initially assigned the last index in the array
	found=0;//initially element is tagged as not found
	
	mid=(first+last)/2;//necesary to find the middle element
	
	while((last>=first)&&(found!=1))
	{
		if(key==num[mid])//if middle element of the array matches key
			found=1;//the number is tagged as found
			
		if(key<num[mid])//if key is less than the middle element of the array
			last=mid-1;//move the search area left
			
		if(key>num[mid])//if key is greater than middle element of the array
			first=mid+1;//move the search area right
			
		mid=(first+last)/2;
	}//endwhile
	
	if(found==1)//if number is found at position mid
		printf("Your number, %d, was found in position %d\n\n",key,mid);
	else
		printf("YOUR NUMBER IS NOT IN THE ARRAY\n\n");
	
}//end program
