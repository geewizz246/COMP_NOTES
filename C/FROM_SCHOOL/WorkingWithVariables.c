#include<stdio.h>
#include<stdlib.h>

main()

{
	//variable declaration
	char initial;
	float money;
	int age;
	
	printf("Enter middle initial\n");
	scanf("%c",&initial); // you NEVER put \n in scanf
	
	printf("Enter your age\n");
	scanf("%d",&age);
	
	printf("Enter account balance\n");
	scanf("%f",&money);
	
	printf("Your initial is: %c\n",initial);
	printf("Your age is: %d\n",age);
	printf("Your account balance is: %f\n",money);
	
	system("Pause"); //pauses the screen

}//end program

