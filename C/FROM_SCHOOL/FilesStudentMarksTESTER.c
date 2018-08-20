#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define num 2
int printName(char name1[],char name2[])
{
	FILE*marks;
	if(marks==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		fprintf(marks,"%s\t%s\n",name1,name2);
	}
}
main()
{
	FILE*marks;
	char fname[20],lname[20],subject[50],maxname1[20],maxname2[20],minname1[20],minname2[20];
	char search1[20],search2[20];
	int i,ans,found;
	float mark,avg,sum,max,min;
	
	max=0;
	min=100;
	found=0;
	
	marks=fopen("studentmarks.txt","a");
	
	if(marks==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		printf("Enter the student's first name:\n");
		scanf("%s",&fname);
		while(stricmp(fname,"End")!=0)
		{
			sum=0;
			printf("Enter the student's last name:\n");
			scanf("%s",&lname);
			printName(fname,lname);
			
			for(i=0;i<num;i++)
			{
				printf("Enter name of subject:\n");
				scanf("%s",&subject);
			
				printf("Enter mark earned in %s:\n",subject);
				scanf("%f",&mark);
				
				fprintf(marks,"%s\t%f\n",subject,mark);
				
				sum=sum+mark;
			}
			avg=sum/num;
			fprintf(marks,"%f\n",avg);
			
			fscanf(marks,"%f",&avg);
			
			printf("Enter the student's first name:\n");
			scanf("%s",&fname);
		}
	}
	fclose(marks);
	
	marks=fopen("studentmarks.txt","r");
	
	if(marks==NULL)
	{
		printf("ERROR OPENING FILE!\n");
	}
	else
	{
		fscanf(marks,"%s%s",&fname,&lname);
		while(!feof(marks))
		{
			printf("------------------------------------\n");
			printf("Name of student: %s %s\n",fname,lname);
			for(i=0;i<num;i++)
			{
				fscanf(marks,"%s%f",&subject,&mark);
				printf("%s: %.2f\n",subject,mark);	
			}
			fscanf(marks,"%f",&avg);
			if(avg>max)
			{
				max=avg;
				strcpy(maxname1,fname);
				strcpy(maxname2,lname);
			}
			else
			if(avg<min)
			{
				min=avg;
				strcpy(minname1,fname);
				strcpy(minname2,lname);
			}
			printf("Average of marks: %.2f",avg);
			fscanf(marks,"%s%s",&fname,&lname);
			printf("\n");
		}	
	}
	fclose(marks);
	printf("\n");
	printf("%.2f\t%s %s\n",max,maxname1,maxname2);
	printf("%.2f\t%s %s\n",min,minname1,minname2);
	
	printf("Would you like to search for a student's data?\n");
	printf("1)	Yes\n");
	printf("2)	No\n");
	scanf("%d",&ans);
	
	if(ans==1)
	{
		marks=fopen("studentmarks.txt","r");
		
		if(marks==NULL)
		{
			printf("Error opening file\n");
		}
		else
		{
			printf("Enter the name of the student you wish to search for\n");
			scanf("%s",&search1);
			scanf("%s",&search2);
			
			fscanf(marks,"%s%s",&fname,&lname);
			while(!feof(marks))
			{
				if((stricmp(search1,fname)==0)&&(stricmp(search2,lname)==0))
				{
					found=1;
					for(i=0;i<num;i++)
					{
						fscanf(marks,"%s%f",&subject,&mark);
						printf("%s: %.2f\n",subject,mark);
						printf("\nThe program will terminate now...\n");
					}
				}
				fscanf(marks,"%s%s",&fname,&lname);
			}
			if(found==0)
			{
				printf("The student was not found.\n");
				printf("\nThe program will terminate now...\n");
			}
		}
		fclose(marks);
	}
	else
	{
		printf("\nThe program will terminate now...\n");
	}	
}
