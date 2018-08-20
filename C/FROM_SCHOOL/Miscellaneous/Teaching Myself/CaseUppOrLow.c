/*C program to check whether a character is Uppercase or Lowercase*/

#include<stdio.h>

void main()
{
	char ch;
	
	printf("Enter a character---->");
	scanf("%c",&ch);
	
	if(ch>='a'&&ch<='z')
		printf("\nCharacter is lowercase\n");
		
	if(ch>='A'&&ch<='Z')
		printf("\nCharacter is UPPERCASE\n");
		
	if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z'))
		printf("\nCharacter is not from the alphabet\n");
}
