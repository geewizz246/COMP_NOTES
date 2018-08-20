/*For any three integer values the following rules apply: 
	• The values cannot be the sides of a triangle if any value is 0 the values or negative and if any value is greater than the sum of the other two 
	• The values can represent the sides of an equilateral triangle if all the values are equal 
	• The values can represent the sides of an isosceles triangle if two values are equal 
	• The values can represent the sides of a scalene triangle if all the values are different 

Write a program that reads three integers and prints to the standard output what triangle is represented. If no triangle is represented print no triangle is represented 
*/
#include<stdio.h>
#include<stdlib.h>
main()
{
	int num[3],i,sum1,sum2,sum3;
	for(i=0;i<3;i++)
	{
		printf("Enter a number.\n");
		scanf("%d",&num[i]);
	}
	
	sum1=num[0]+num[1];
	sum2=num[1]+num[2];
	sum3=num[0]+num[2];
	
	if((num[0]<=0)||(num[1]<=0)||(num[2]<=0)||(num[0]>sum2)||(num[1]>sum3)||(num[2]>sum1))
		printf("No triangle is represented.\n");
	else
	if ((num[0]==num[1])&&(num[1]==num[2])&&(num[0]==num[2]))
		printf("The numbers entered represent an equilateral triangle.\n");
	else
	if ((num[0]==num[1])||(num[1]==num[2])||(num[0]==num[2]))
		printf("The numbers entered represent an isosceles triangle.\n");
	else
		printf("The numbers entered represent a scalene triangle.\n");
}
