#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, space, rows, star, starCount;
	
	printf("Enter the number of rows to print\n");
	scanf("%d",&rows);
	
	/* printing one row in every iteration */
	for(i=1; i<=rows; i++)
	{
		/* Printing spaces */
		for(space=1; space<=rows-i; space++)
		{
			printf(" ");
		}
		
		/* Printing stars */
		starCount=(2*i)-1;
		for(star=1; star<=starCount; star++)
			printf("*");
		
		/* move to next row */
		printf("\n");
	}
	
	return 0;
}
