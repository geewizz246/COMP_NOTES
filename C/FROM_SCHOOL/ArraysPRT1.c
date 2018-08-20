#include<stdio.h>
#include<stdlib.h>
#define size 10  //array is numbered 0-9 but still holds 10 nos.

main()
{
	float nums[size];
	int i;
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number\t"); //'\t' puts a tab instead of going to a new line
		scanf("%f",&nums[i]); //reads float no. into array
	}

}
