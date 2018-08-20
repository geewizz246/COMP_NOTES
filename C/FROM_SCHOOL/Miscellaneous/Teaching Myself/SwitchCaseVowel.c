/*C program to check vowel or consonant using switch case*/

#include<stdio.h>

void main()
{
	char ch;
	
	printf("Enter any alphabet character: ");
	scanf("%c",&ch);
	
	switch(ch)
	{
		case 'a': printf("VOWEL\n");
			break;
		case 'e': printf("VOWEL\n");
			break;
		case 'i': printf("VOWEL\n");
			break;
		case 'o': printf("VOWEL\n");
			break;
		case 'u': printf("VOWEL\n");
			break;
		case 'A': printf("VOWEL\n");
			break;
		case 'E': printf("VOWEL\n");
			break;
		case 'I': printf("VOWEL\n");
			break;
		case 'O': printf("VOWEL\n");
			break;
		case 'U': printf("VOWEL\n");
			break;
		default: printf("CONSONANT\n");	
	}
}
