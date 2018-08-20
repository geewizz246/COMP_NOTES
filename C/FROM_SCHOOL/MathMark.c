#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	FILE*p1;
	char name[10],gender[8],highMale[10];
	int mark,count,sum,high;
	float avg;
	
	count=0;
	sum=0;
	high=-1;
	
	p1 = fopen("info.txt","r");
	if(p1==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	
	fscanf(p1,"%s%s%d",&name,&gender,&mark);
	while(!feof(p1))
	{
		count++;
		
		sum=sum+mark;
		if((stricmp(gender,"male")==0)&&(mark>high))
		{
			strcpy(highMale,name);
			high=mark;
		}
		
		fscanf(p1,"%s%s%d",&name,&gender,&mark);
	}
	fclose(p1);
	
	avg=sum/count;
	printf("No. of students who took math exam: %d\n",count);
	printf("Student with highest math mark: %s - %d\n",highMale,high);
	printf("Average exam mark: %.2f\n",avg);
}
