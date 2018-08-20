#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int menu(char choice[20])
{
	int game,stage;
	char restart[20];
	
	printf("Do you want to restart?\n");
	scanf("%s",restart);
	
	if(stricmp(restart,"yes")==0)
	{
		printf("Restarting the game\n");
		printf("----------------------------------------------------------------------------------------\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("----------------------------------------------------------------------------------------\n");
		game=0;
	}
	else
	if(stricmp(restart,"no")==0)
	{
		printf("Would you like to continue the game?\n");
		scanf("%s",choice);
		
		if(stricmp(choice,"no")==0)
		{
			printf("Would you like to go back to the start of this stage[Yes or No]?\n");
			scanf("%s",choice);
			
			if(stricmp(choice,"yes")==0)
			{
				stage=stage-1;
			}
			if(stricmp(choice,"no")==0)
			{
				printf("Would you like to end the game?\n");
				scanf("%s",choice);
				
				if(stricmp(choice,"yes")==0)
				{
					exit(0);
				}
			}
		}
	}
	if(stricmp(restart,"menu")==0)
	{
		printf("Exiting menu\n");
	}
}
int gameCont(char choice[20])
{
	int game;
	
	if(stricmp(choice,"no")==0)
	{
		while(stricmp(choice,"no")==0)
		{
			printf("Are you sure you dont want to start playing?\n");
			scanf("%s",choice);
				
			if(stricmp(choice,"yes")==0)
			{
				exit(0);
			}
			else
			{
				choice="yes";
			}
		}
	}
}
int none(char choice[20])
{
	if((stricmp(choice,"no")!=0)&&(stricmp(choice,"menu")!=0)&&(stricmp(choice,"yes")!=0))
	{
		printf("I must have misunderstood\n");
		printf("Please try again\n");
	}
}
main()
{
	char choice[20];
	int game;
	game=1;
	
	do
	{
		printf("At anytime during the game you can type menu to open the menu, unless you are already in the menu\n");
		printf("Would you like to begin playing?\n");
		scanf("%s",choice);
		
		if(stricmp(choice,"menu")==0)
		{
			menu(choice);
		}
		if(stricmp(choice,"no")==0)
		{
			gameCont(choice);
		}
		if((stricmp(choice,"no")!=0)&&(stricmp(choice,"menu")!=0)&&(stricmp(choice,"yes")!=0))
		{
			none(choice);
		}
		if(stricmp(choice,"yes")==0)
		{
			printf("lol\n");
			printf("d\n");
			printf("d\n");
			printf("d\n");
			scanf("%s",choice);
			if(stricmp(choice,"menu")==0)
			{
				menu(choice);
			}
			printf("d\n");
			printf("d\n");
			printf("d\n");
			
		}
		
		
		game=2;	
	}while(game==1);
}
