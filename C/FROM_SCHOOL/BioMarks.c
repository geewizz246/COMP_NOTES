#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE*p1;
	char ID[6];
	float mark,max=-1;
	int A=0,B=0,C=0,F=0;
	
	p1 = fopen ("testgrades.txt","r");
	if(p1==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	
	fscanf(p1,"%s%f",&ID,&mark);
	
	while(!feof(p1))
	{
		if(mark>max)
		{
			max=mark;
		}
		if(mark>=80)
		{
			A++;
		}
		if((mark>=70)&&(mark<=79))
		{
			B++;
		}
		if((mark>=60)&&(mark<=69))
		{
			C++;
		}
		if(mark<=59)
		{
			F++;
		}
		
		fscanf(p1,"%s%f",&ID,&mark);
	}
	fclose(p1);
	
	printf("Number of students getting As: %d\n",A);
	printf("Number of students getting Bs: %d\n",B);
	printf("Number of students getting Cs: %d\n",C);
	printf("Number of students getting Fs: %d\n",F);
	
	printf("Highest mark gained: %.2f\n",max);
}
