#include<stdio.h>
#include<math.h>

main()
{
	int base,exponent,power;
	
	printf("Enter base: ");
	scanf("%d",&base);
	printf("Enter exponent: ");
	scanf("%d",&exponent);
	
	power=pow(base,exponent);
	
	printf("\nPower is---->%d\n",power);
}
