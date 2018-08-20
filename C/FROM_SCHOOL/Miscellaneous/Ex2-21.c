#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, rectangle, circle, arrow, diamond;
	for(i=1; i<=9; i++)
	{
		//rectangle
		for(rectangle=1;rectangle<=9;rectangle++)
		{
			if((i==1)||(i==9)||(rectangle==1)||(rectangle==9))
				printf("*");
			else
				printf(" ");
		}
		printf("\t");
		
		//circle
		if((i==1)||(i==9))
			printf("   ***   ");
		if((i==2)||(i==8))
			printf(" *     * ");
		if((i>2)&&(i<8))
			printf("*       *");
		printf("\t");
		
		//arrow
		if((i==1)||(i>3))
			printf("    *    ");
		if(i==2)
			printf("   ***   ");
		if(i==3)
			printf("  *****  ");
		printf("\t");
		
		//diamond
		if((i==1)||(i==9))
			printf("    *    ");
		if((i==2)||(i==8))
			printf("   * *   ");
		if((i==3)||(i==7))
			printf("  *   *  ");
		if((i==4)||(i==6))
			printf(" *     * ");
		if(i==5)
			printf("*       *");
		printf("\n");
	}
}
