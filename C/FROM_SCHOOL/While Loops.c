#include<stdio.h>
#include<stdlib.h>
#define size 10
main()

{
	int num,sum,count;
	float avg;
	
	sum=0;
	count=0;
	
	printf("Enter a number, terminate by -1.\n");
	scanf("%d",&num);
		
	while(num!=-1)//'!=' means not equal to
	{
		sum=sum+num;
		count++;//or count=count+1
			
		printf("Enter a number, terminate by -1.\n");
		scanf("%d",&num);	
	}//EndWhile
	
	avg=sum/count;

	printf("\n"); //extra spaces
	printf("The average of the entered numbers is: %.2f\n\n",avg);//'%.2f' means to two decimal places
	
	system("Pause");

}
