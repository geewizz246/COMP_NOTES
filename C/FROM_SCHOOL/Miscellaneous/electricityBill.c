/*Write a C program to input electricity unit charge and calculate 
the total electricity bill according to the given conditions: 
For first 50 units Rs. 0.50/unit
For next 100 units Rs. 0.75/unit
For next 100 units Rs. 1.20/unit
For unit above 250 Rs. 1.50/unit
An additional surcharge of 20% is added to the bill.*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
	float unit,amt;
	
	printf("Enter total units consumed: ");
	scanf("%f",&unit);
	
	if(unit<=50)
		amt=unit*0.50;
	if(unit>50 && unit<=150)
		amt=((unit-50)*0.75)+(50*0.50);
	if(unit>150 && unit<=250)
		amt=((unit-150)*1.20)+(100*0.75)+(50*0.50);
	if(unit>250)
		amt=((unit-250)*1.50)+(100*1.20)+(100*0.75)+(50*0.50);
		
	amt=amt*1.2;
	
	printf("Total electricity bill = Rs. %.2f",amt);
}
