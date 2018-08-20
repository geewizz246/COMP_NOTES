#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
main()

{
	char word[size],wordRev[size];
	
	printf("Enter a word of your choice.\n");
	scanf("%s",&word);
	
	strcpy(wordRev,word); //copies word to wordRev
	strrev(wordRev); //reverses wordRev

	printf("The word reversed is: %s\n",wordRev);
	
	if(stricmp(wordRev,word)==0) //compares the contents of word & wordRev; 'stricmp' ignores the case
		printf("Entered string is a palindrome.\n");
	else
		printf("Entered string is not a palindrome.\n");
}
