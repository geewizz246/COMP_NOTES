#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()

{
	char yourPassword[50];
	int ans;
	
	printf("Enter your password.\n");
	scanf("%s",&yourPassword);
	
	ans=strcmp(yourPassword,"volcano");
	if(ans==0)
		printf("SUCCESS!!!\n");
	else
		printf("REJECTED!! SHOO!!\n");
	
	system("Pause");
}
