/*	Read a string entered by the user at the keyboard and store it in an array. 
	Determine the number of vowels in the sentence. 
	If no vowels are present print "No vowels". 
	Assume that the string is entered in uppercase letters and that the string is exactly 7 characters in length. 
	Also count and print the number of occurances of the letter 'a' in the string.	*/
#include<stdio.h>
#include<stdlib.h>
#define size 8
main()
{
	char string[size];
	int i,vowels,count;
	
	vowels=0;
	count=0;
	
	printf("Enter a string.\n");
	scanf("%s",&string);
	strupr(string);
	
	for(i=0;i<size;i++)
	{
		if((string[i]=='A')||(string[i]=='E')||(string[i]=='I')||(string[i]=='O')||(string[i]=='U'))
		{
			vowels+=1;
		}
		if(string[i]=='A')
		{
			count+=1;
		}
	}
	
	printf("The number of vowels in this string is %d.\n",vowels);
	printf("The number of As in this string is %d.\n",count);
}
