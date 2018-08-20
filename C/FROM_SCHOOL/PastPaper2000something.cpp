#include<stdio.h>
#include<stdlib.h>
main()
{
	FILE*p1;
	FILE*p2;
	float aim,donation,total=0;
	int count=0;
	
	p1=fopen("donations.txt","r");
	if(p1==NULL)
		printf("ERROR OPENING FILE\n");
	else
	{
		printf("Checking the contents of donations.txt...\n");
		fscanf(p1,"%f\n",&aim);
		printf("The aim was $%.2f\n",aim);
		
		fscanf(p1,"%f\n",&donation);
		while(donation!=-1)
		{
			total=total+donation;
			count++;
			fscanf(p1,"%f\n",&donation);
		}
		
		p2=fopen("funds.txt","a");
		if(p2==NULL)
			printf("ERROR OPENING FILE\n");
		else
		{		
			fprintf(p2,"%f\n%d\n",total,count);
			printf("Total funds raised: $%.2f\n",total);
			printf("Number of donations: %d",count);			
		}
		fclose(p2);
	}
	fclose(p1);
}
