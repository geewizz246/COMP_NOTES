#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char yourPassword[50];
	
	printf("Enter your password.\n");
	scanf("%s",&yourPassword);
	
	if(strcmp(yourPassword,"volcano")==0)
		printf("SUCCESS! Welcome to the darkside! >:3\n");
	else
		printf("REJECTED!! SHOO!!\n");
	
	system("Pause");

}
