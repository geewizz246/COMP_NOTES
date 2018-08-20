#include <stdio.h>
#include <stdlib.h>

int main()
{
    int level;
    int levelcount;
    int layercount;
    int layer;
    int star;
    int starcount;
    int spacecount;
    int space;
    int length;

    printf("How many layers: ");
    scanf("%d", &layercount);
    printf("How many levels: ");
    scanf("%d", &levelcount);

    printf("\n Chrismas Tree \n");

    length = (layercount*levelcount);
    starcount = 1;
    spacecount = length;
    for (layer = 1 ; layer <= layercount ; layer++)
	{
        for (level = 1 ; level <= levelcount ; level++)
		{
            for (space = 1 ; space <= spacecount ; space++)
                printf(" ");
            for (star = 1 ; star <= starcount ; star++)
                printf("*");
            printf("\n");
            starcount += 2;
            spacecount--;
        }
        // since starcount and spacecount are incremented
        // just before level loop exit
        starcount -= 2;
        spacecount++;
        if(levelcount <= 3)
		{
        	starcount -= 2;
            spacecount += 1;
        }
        else
		{
            starcount -= 4;
            spacecount += 2;
        }
    }
    spacecount = length;
    for (layer = 1 ; layer <= 4; layer++)
	{
        for (space = 1 ; space <= spacecount-1 ; space++)
            printf(" ");
        for (star = 1 ; star <= 3 ; star++)
            printf("#");
        printf("\n");
    }
    return 0;
}

