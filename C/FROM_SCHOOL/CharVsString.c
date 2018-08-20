#include<stdio.h>
#include<stdlib.h>

main()
{
	char firstname[16]; //declaring an array that holds 15 characters; 16 because an extra space is needed.
	char initial;
	
	printf("Enter yout first name and middle initial\n");
	scanf("%s %c",&firstname,&initial); //%s is used for strings; leave a space between %s and %c.
	
	printf("Your first name is %s and your middle initial is %c.\n\n",firstname,initial); //printing two variables at once
	
	system("Pause");
	
}
