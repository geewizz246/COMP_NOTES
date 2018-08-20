#include<stdlib.h>
#include<stdio.h>

void main()
{
	int num, sum_of_factors=0;
	printf("Enter an integer: ");
	scanf("%d",&num);
	
	int i;
	for (i=1; i<=num; i++) {
		if (num % i == 0) {
			printf("\n%d is a factor.", i);
			sum_of_factors = sum_of_factors + i;
		}//endif
	}//endfor
	
	printf("\n\nSum of factors is: %d.\n\n", sum_of_factors);
}
