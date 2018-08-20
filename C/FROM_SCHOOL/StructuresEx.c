/*A program is required to store as records the following information on twenty students:
 -their name(first name and last name), 
 -their form and 
 -their marks in 5 subjects. 
 Calculate and print for each student their average. Also calculate for the class the highest and lowest average gained. */
 
#include<stdio.h>
#include<stdlib.h>
#define size 20

main()
{
	struct results
	{
		char name1[25];
		char name2[25];
		char form[10];
		float math,english,geo,phys,it;
		float avg;		
	};
	
	struct results exam[size];
	int i;
	float sum[size],max,min;
	
	for(i=0;i<size;i++)
	{
		sum[i]=0;
		printf("Enter first name and then last name:\n");
		scanf("%s%s",&exam[i].name1,&exam[i].name2);
		
		printf("Enter form of student:\n");
		scanf("%s",&exam[i].form);
		
		printf("Enter your marks for 5 subjects...\n");
		printf("Math: ");
		scanf("%f",&exam[i].math);
		printf("English: ");
		scanf("%f",&exam[i].english);
		printf("Geography: ");
		scanf("%f",&exam[i].geo);
		printf("Physics: ");
		scanf("%f",&exam[i].phys);
		printf("Information Technology: ");
		scanf("%f",&exam[i].it);
		
		sum[i]=exam[i].math+exam[i].english+exam[i].geo+exam[i].phys+exam[i].it;
		exam[i].avg=sum[i]/5;
		
		printf("\nThe average mark for student is: %.2f.\n\n",exam[i].avg);
	}
	
	max=exam[0].avg;
	min=exam[0].avg;
	
	for(i=1;i<size;i++)
	{
		if(exam[i].avg>max)
		{
			max=exam[i].avg;
		}
		else
		if(exam[i].avg<min)
		{
			min=exam[i].avg;
		}
	}
	
	printf("The highest average mark for class is: %.2f%.\n",max);
	printf("The lowest average mark for class is: %.2f%.",min);
}

