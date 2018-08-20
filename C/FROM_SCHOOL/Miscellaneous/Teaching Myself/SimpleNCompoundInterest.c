#include<stdio.h>
#include<math.h>

void main()
{
	float principle, rate, SI, CI;
	int time, i;
	
	printf("Enter principle: ");
	scanf("%f",&principle);
	
	printf("Enter time: ");
	scanf("%d",&time);
	
	printf("Enter rate: ");
	scanf("%f",&rate);
	
	//calculate simple interest
	SI=(principle*rate*time)/100;
	
	//calculate compound interest
	CI=principle*(pow((1+rate/100),time)-1);
	
	printf("\nSimple Interest = $%.2f\n",SI);
	printf("\nCompound Interest = $%.2f\n",CI);
}
