#include<stdio.h>
#include<stdlib.h>

main() /*main function*/
{	//notice only integer values can be assigned
	enum quantites {chocolate=15,perfume=49,roses};
	int reply,quantity,numChocolate,numPerfume,numRoses;
	
	
	printf("Number of boxes of chocolate on hand: %d\n\n",chocolate); //15 is printed
	printf("Number of perfumes on hand: %d\n\n",perfume); //49 is printed
	printf("Number of roses on hand: %d\n\n",roses); //50 is printed
	
	printf("Enter what you wish to purchase\n\n");
	printf("1 for chocolates\n\n");
	printf("2 for perfume\n\n");
	printf("3 for roses\n\n\n\n");
	
	scanf("%d",&reply);
	
	printf("Enter how many of the item you want\n\n");
	scanf("%d",&quantity);
	
	if(reply==1)
	{
		numChocolate=chocolate-quantity; //the new quantity of chocolate is determined
		printf("\nNumber of chocolates now on hand is: %d\n\n",numChocolate);
	}//endif
	
	if(reply==2)
	{
		numPerfume=perfume-quantity; //the new quantity of perfume is determined
		printf("\nNumber of perfumes now on hand is: %d\n\n",numPerfume);
	}//endif
	
	if(reply==3)
	{
		numRoses=roses-quantity; //the new quantity of roses is determined
		printf("\nNumber of roses now on hand is: %d\n\n",numRoses);
	}//endif
	
}//endprogram
