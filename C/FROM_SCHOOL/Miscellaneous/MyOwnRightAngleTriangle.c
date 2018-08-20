#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, levels, star, starCount;
	printf("Enter number of levels: ");
	scanf("%d",&levels);
	printf("\n");
	
	starCount=levels;
	
	for(i=1; i<=starCount; i++)
	{
		for(star=1; star<=i; star++)
		{
			if((i==1)||(i==starCount)||(star==1)||(star==i))
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
}
