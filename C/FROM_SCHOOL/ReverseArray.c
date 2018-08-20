#include<stdio.h>
#include<stdlib.h>

main()

{
	int num1[10],num2[10];
	int i,j;
	
	j=9;
	
	for(i=0;i<10;i++)
	{
		printf("Enter a number.\n");
		scanf("%d",&num1[i]);
		
		num2[j]=num1[i];
		j--;
	}
	
	printf("Numbers entered: \t");
	for(i=0;i<10;i++)
	{
		printf("%d ",num1[i]);
	}
	
	printf("\nNumbers reversed: \t");
	for(i=0;i<10;i++)
	{
		printf("%d ",num2[i]);
	}
}
