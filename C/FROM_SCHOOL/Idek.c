#include<stdio.h>
#include<stdlib.h>
main()
{
	int m,n,sum,num1=8,num2=11;
	
	sum=0;
	m=4;
	n=200;
	
	while((num1>=m)&&(num1<n))
	{
		sum=sum+num1;
		num1=num1+8;
	}
	printf("%d",sum);
	
	while((num2>=m)&&(num2<n))
	{
		sum=sum+num2;
		num2=num2+11;
	}
	
	printf("\nResult: %d",sum);
}
