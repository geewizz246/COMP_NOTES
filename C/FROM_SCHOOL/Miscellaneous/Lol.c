#include<stdio.h>
#include<math.h>

void main()
{
	float a,b,c,d,root1,root2;
	
	printf("Enter the coefficients a, b and c of the quadratic equation:\n");
	scanf("%f%f%f",&a,&b,&c);
	
	d=b*b-4*a*c;
	if(d<0)
	{
		printf("\nNO REAL SOLUTION\n");
	}
	if(d==0)
	{
		printf("Only one real solution.\n");
		root1=(-b+sqrt(d))/(2*a);
		printf("\nRoot of quadratic equation is: %.2f\n",root1);		
	}
	if(d>0)
	{
		printf("Equations has real roots.\n");
		root1=(-b+sqrt(d))/(2*a);
		root2=(-b-sqrt(d))/(2*a);
		printf("\nRoots of quadratic equation are: %.2f, %.2f\n",root1,root2);
	}
}
