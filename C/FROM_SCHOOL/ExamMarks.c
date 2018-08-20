#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char name[25];
	float mark;
	int i,pass=0,fail=0;
	FILE*p1;
	
	p1=fopen ("exam.txt","a");
	if(p1==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	
	for(i=0;i<10;i++)
	{
		printf("Enter the student's name and mark:\n");
		scanf("%s%f",&name,&mark);
		fprintf(p1,"%s\t%f\n",name,mark);
	}
	fclose(p1);
	
	p1=fopen ("exam.txt","r");
	if(p1==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	
	fscanf(p1,"%s%f",&name,&mark);
	while(!feof(p1))
	{
		if(mark>=50)
		{
			pass++;
		}
		else
		{
			fail++;
		}
		fscanf(p1,"%s%f",&name,&mark);
	}
	fclose(p1);
	
	printf("Number of students who passed: %d\n",pass);
	printf("Number of students who failed: %d\n",fail);
}
