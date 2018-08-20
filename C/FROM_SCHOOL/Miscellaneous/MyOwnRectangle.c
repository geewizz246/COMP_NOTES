#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i, height, width, star;
	printf("Enter height of rectangle: ");
	scanf("%d",&height);
	printf("Enter width of rectangle: ");
	scanf("%d",&width);
	
	if(height==width)
		printf("\n%d x %d square\n\n",height,width);
	else
		printf("\n%d x %d rectangle\n\n",height,width);
	
	for(i=1; i<=height; i++)
	{
		for(star=1; star<=width; star++)
		{
			if((i==1)||(i==height)||(star==1)||(star==width))
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
}
