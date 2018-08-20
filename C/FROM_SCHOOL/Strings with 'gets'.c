#include<stdio.h>
#include<stdlib.h>

main()

{
	char name[100];//so 99 spaces
	
	printf("Enter your full name\n");
	gets(name);//'gets' reads spaces in strings
	printf("The name of the student is %s\n\n",name);
	
	system("Pause");
}
