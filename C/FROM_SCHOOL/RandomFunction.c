#include<stdio.h>
#include<stdlib.h>
#include<time.h> //necessary for random function to work

main()
{
	srand(time(NULL)); //call this function so number generated always changes
	int r = rand()%20; //generates a random number between 0 and 19

	printf("%d",r);
}
