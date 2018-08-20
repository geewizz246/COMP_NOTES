/*C program to find all roots of quadratic equation using switch case*/

#include<stdio.h>
#include<math.h>

void main()
{
	float a, b, c;
	float root1, root2, imaginary;
	float discriminant;
	
	printf("Enter values of a, b, c of quadratic equation (ax^2 + bx +c): ");
	scanf("%f%f%f",&a,&b,&c);
	
	discriminant = (b*b)-4*(a*c);
	
	//compute roots of equation based on nature of discriminant
	
	switch(discriminant>0)
	{
		//If discriminant is positive
		case 1:
			root1 = (-b + sqrt(discriminant)) / (2*a);
			root2 = (-b - sqrt(discriminant)) / (2*a);
			
			printf("\nTwo distinct and real roots exist: %.2f and %.2f\n",root1,root2);
			break;
		
		//If discriminant is not positive
		case 0:
			switch(discriminant<0)
			{
				//If discriminant is negative
				case 1:
					root1 = root2 = -b/(2*a);
					imaginary = sqrt(-discriminant) / (2*a);
					
					printf("\nTwo distinct and complex roots exist: %.2f + i%.2f and %.2f - i%.2f\n",root1,imaginary,root2,imaginary);
					break;
				
				//If discriminant is zero
				case 0:
					root1 = root2 = -b/(2*a);
					
					printf("\nTwo equal and real roots exist: %.2f and %.2f\n",root1,root2);
					break;
			}//end switch
		break;
		
	}//end switch
}
