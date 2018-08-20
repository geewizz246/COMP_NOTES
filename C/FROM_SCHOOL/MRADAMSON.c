#include<stdio.h>
#include<stdlib.h>
#define size 100

int primeFunc(int num)
{
	int div=1,val,count=0;
	
	
	while(div<=num)
	{
		val=num%div;
		
		if(val==0)
		{
			count++;
		}
		div=div+1;
	}
	
	return count;
}
main()
{
	int num=1,i,factors,sum=0;
		
	for(i=0;i<size;i++)
	{
		factors=primeFunc(num);
		
		if(factors==2)
		{
			sum=sum+num;
			printf("The number, %d, is prime.\n",num);
		}
		else
		{
			printf("The number, %d, is not prime.\n",num);
		}
		num++;
	}
	printf("\n********************************************\n");
	printf("\n       Sum of Prime Numbers====>%d          \n",sum);
	printf("\n********************************************\n");
}
