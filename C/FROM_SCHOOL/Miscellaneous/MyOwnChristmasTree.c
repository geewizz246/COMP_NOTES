#include<stdio.h>
#include<stdlib.h>

int main()
{
	int levelCount,level,layerCount,layer,length,spaceCount,space,star,starCount;
	printf("Enter the number of levels: ");
	scanf("%d",&levelCount);
	printf("Enter the number of layers: ");
	scanf("%d",&layerCount);
	
	printf("\n\n");
	
	length=levelCount*layerCount;
	spaceCount=length;
	starCount=1;
	
	//printing tree
	for(layer=1; layer<=layerCount; layer++)
	{
		for(level=1; level<=levelCount; level++)
		{
			for(space=1; space<=spaceCount; space++)
			{
				printf(" ");
			}
			for(star=1; star<=starCount; star++)
			{
				printf("*");
			}
			spaceCount--;
			starCount+=2;
			
			printf("\n");
		}
		
		if(levelCount<=3)
		{
			spaceCount+=2;
			starCount-=4;
		}
		if((levelCount>3)&&(levelCount<=8))
		{
			spaceCount+=3;
			starCount-=6;
		}
		if(levelCount>8)
		{
			spaceCount+=4;
			starCount-=8;
		}
	}
	
	//printing trunk
	spaceCount=length-1;
	for(layer=1; layer<=4; layer++)
	{
		for(space=1; space<=spaceCount; space++)
			printf(" ");
		for(star=1; star<=3; star++)
			printf("#");
		printf("\n");
	}	
}//end program
