#include<stdio.h>

void main()
{
	char ch;
	
	printf("Enter a character---->");
	scanf("%c",&ch);
	
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		printf("\nCharacter is from ALPHABET.\n");
	else
		printf("\nCharacter is not from ALPHABET.\n");
}
