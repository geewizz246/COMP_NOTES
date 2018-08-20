/* 	A gym is having a contest. Members are asked to guess the number of jelly beans in a jar. 
	The winner is the member who accurately guesses the number of jelly beans or whose guess is closest to this value without going over. 
	All the information related to contest is stored in a file "contest.txt". The first line of the file gives the number of jelly beans in the jar. 
	Each line thereafter contains the guess of a member followed by his 4-digit integer ID. Data is terminated by -1 which appears on a line by itself. 
	Write a C program that determines and outputs to a file "winner.txt" the winning guess and the winner's ID code. 
	Assume all guesses are unique and a winner exists. You may not use a arrays in your solution. */

#include<stdio.h>
#include<stdlib.h>
main()
{
	FILE*contest;
	FILE*winner;
	int beans,guess,ID,accurate,winID;
	
	accurate=0;
	winID=0;
	
	contest=fopen("contest.txt","r");
	
	if(contest==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		printf("Checking the contents of contest.txt...\n");
		fscanf(contest,"%d",&beans);
		printf("No. of beans: %d\n",beans);
		fscanf(contest,"%d%d",&guess,&ID);
		while(guess!=-1)
		{
			if(guess<beans)
			{
				if(accurate<guess)
				{
					accurate=guess;
					winID=ID;
				}
			}
			fscanf(contest,"%d%d",&guess,&ID);
		}
	}
	fclose(contest);
	
	winner=fopen("winner.txt","a");
	
	if(winner==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		fprintf(winner,"%d\t%d\n",accurate,winID);
	}	
	fclose(winner);
	
	winner=fopen("winner.txt","r");
	
	if(winner==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		fscanf(winner,"%d%d",&accurate,&winID);
		
		printf("\nThe winning member is ID no. %d with a guess of %d. Congratulations! ^_^\n",accurate,winID);
	}
	fclose(winner);
	
}
