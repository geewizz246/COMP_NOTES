#include<stdio.h>
#include<stdlib.h>

# define pi 3.142
main()

{
	float radius,diameter,area;
	
	printf("Enter the radius of the circle.\n\n");
	scanf("%f",&radius);
	
	diameter= radius*2;
	area= (radius*radius)*pi;
	
	printf("The diameter of the circle is: %f\n",diameter);
	printf("The area of the circle is: %f\n",area);
	
	system("Pause");

}
