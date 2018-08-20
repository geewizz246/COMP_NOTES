#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char name[50]="Johnny Appleseed"; //Intialising a string with a word.
	puts(name); //Prints out "Johnny Appleseed"
	
	strcpy(name,"Raymond"); //Copies "Raymond" to name. "Raymond" counts as a string.
	puts(name); //Prints out "Raymond"
	
	system("Pause");
}
