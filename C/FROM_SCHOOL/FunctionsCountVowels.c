/*	Read a string entered by the user at the keyboard and store it in an array. 
	Determine the number of vowels in the sentence. 
	If no vowels are present print "No vowels". 
	Assume that the string is entered in uppercase letters and that the string is exactly 7 characters in length. 
	Also count and print the number of occurances of the letter 'a' in the string.	*/
#include<stdio.h>
#include<stdlib.h>
#define size 8
int findVowel(char str[])
{
	int i,vowels;
	
	strupr(str);
	vowels=0;
	for(i=0;i<size;i++)
	{
		if((str[i]=='A')||(str[i]=='E')||(str[i]=='I')||(str[i]=='O')||(str[i]=='U'))
		{
			vowels+=1;
		}
	}
	return vowels;
}
int findA(char str[])
{
	int i,count;
	
	strupr(str);
	count=0;
	for(i=0;i<size;i++)
	{
		if(str[i]=='A')
		{
			count+=1;
		}
	}
	return count;
}

main()
{
	char string[size];
	int num1,num2;
	
	
	printf("Enter a string.\n");
	scanf("%s",&string);	
	
	num1=findVowel(string);
	num2=findA(string);
		
	printf("The number of vowels in this string is %d.\n",num1);
	printf("The number of As in this string is %d.\n",num2);
}
