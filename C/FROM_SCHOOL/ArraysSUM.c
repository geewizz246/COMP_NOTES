#include<stdio.h>
#include<stdlib.h>
#define size 10
main()
{
	int num[size];
	int	i,sum;
	
	sum=0;
	
	for(i=0;i<size;i++)
	{
		printf("Enter a number: \t");
		scanf("%d",&num[i]);
		
		if(num[i]<=100)
			sum=sum+num[i];
	}
	
	printf("The sum of the numbers not greater than 100 is: %d\n",sum);
	
	system("Pause");
}
