/*C program to sort n words in alphabetical order*/

#include<stdio.h>
#include<string.h>
#define size 5

void main()
{
	char word[size][50];
	char temp[50];
	int i, j, k, index;
	
	printf("Enter %d words: ",size);
	
	for(i=0;i<size;i++)
		scanf("%s",&word[i]);
	
	//Begin selection sort
	for(j=0;j<size-1;j++)
	{
		index=j;
		
		for(k=(j+1);k<size;k++)
		{
			int ch=0;
			while(word[index][ch]==word[k][ch])
				ch++;
				
			if(word[index][ch]>word[k][ch])
				index=k;
		}//endfor
		
		//SWAP WORDS
		strcpy(temp,word[index]);
		strcpy(word[index],word[j]);
		strcpy(word[j],temp);
	}//endfor
	
	
	for(i=0;i<size;i++)
		printf("\n%s\n",word[i]);
}
