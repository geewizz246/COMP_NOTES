#include<stdio.h>
#include<stdlib.h>

main()
{
	float price,tax,newPrice;
	
	printf("Enter the price and tax on item\n");
	scanf("%f%f",&price,&tax);
	
	newPrice=price+(price*(tax/100));
	
	printf("\nOld Price: $%.2f\n",price);
	printf("New Price: $%.2f\n",newPrice);
}
