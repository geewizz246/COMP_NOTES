/*C program to print various star patterns*/

#include<stdio.h>

//Function to print filled square
void FSquare()
{
	int n, i, j;
	
	printf("Enter number of rows: ");
	scanf("%d",&n);
	
	//Iterate over rows
	for(i=0; i<n; i++)
	{
		//Iterate over columns
		for(j=0; j<n; j++)
			printf("* ");
		
		//Move to next row
		printf("\n");
	}//endfor	
}//end FSquare

//Function to print hollow square
void HSquare()
{
	int n, i, j;
	
	printf("Enter number of rows: ");
	scanf("%d",&n);
	
	//Iterate over rows
	for(i=0; i<n; i++)
	{
		//Iterate over columns
		for(j=0; j<n; j++)
		{
			if((i>0&&i<(n-1))&&(j>0&&j<(n-1)))
				printf("  ");
			else
				printf("* ");
		}//endfor
		
		//Move to next row
		printf("\n");
	}//endfor
}//end HSquare

//Function to print filled rhombus
void FRhombus()
{
	int n, i, j, spaces;
	
	printf("Enter number of rows: ");
	scanf("%d",&n);
	
	//Iterate over rows
	for(i=n-1; i>=0; i--)
	{
		//Print spaces
		for(spaces=i; spaces>=0; spaces--)
			printf(" ");
			
		//Iterate over columns
		for(j=0; j<n; j++)
			printf("* ");
		
		//Move to next row
		printf("\n");
	}//endfor
}//end FRhombus

//Function to print hollow rhombus
void HRhombus()
{
	int n, i, j, spaces;
	
	printf("Enter number of rows: ");
	scanf("%d",&n);
	
	//Iterate over rows
	for(i=n-1; i>=0; i--)
	{
		//Print spaces
		for(spaces=i; spaces>=0; spaces--)
			printf(" ");
			
		//Iterate over columns
		for(j=0; j<n; j++)
		{
			if((i>0&&i<(n-1))&&(j>0&&j<(n-1)))
				printf("  ");
			else
				printf("* ");
		}
		
		//Move to next row
		printf("\n");
	}//endfor
}

void main()
{
	int ans;
	
	printf("Which pattern would you like printed:\n");
	printf("1. Filled Square\n");
	printf("2. Hollow Square\n");
	printf("3. Filled Rhombus\n");
	printf("4. Hollow Rhombus\n");
	printf("\nAns---->");
	scanf("%d",&ans);
	
	printf("\n\n\n");
	
	switch(ans)
	{
		case 1: FSquare();
			break;
			
		case 2: HSquare();
			break;
		
		case 3: FRhombus();
			break;
			
		case 4: HRhombus();
			break;
	}//endswitch
}
