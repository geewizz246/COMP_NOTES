#include<stdio.h>
#include<stdlib.h>

main()

{
	int count=0,pass=0,fail=0; //declaring and initialising variables
	float score,total,avg;
	
	printf("Enter the test score of student (out of 25). TO END TYPE -1.\n");
	scanf("%f",&score);
	
	while(score>=0) //While score is more or equal to 0 do
	{
		if(score>25) //If score is more than 25
		{
			while(score>25) //While score is more than 25 do
			{
				printf("Error 003: Score is too big. Please re-enter score (out of 25)\n");
				scanf("%f",&score);
			} //ENDWHILE
		} //ENDIF
		
		if(score>12.5)
		{
			pass=pass+1;
		} 
		else
		{
			fail=fail+1;
		} //ENDIF
		
		total= total+score;
		count=count+1;
		
		printf("Enter the test score of another student (out of 25). TO END TYPE -1.\n");
		scanf("%f",&score);
	} //ENDWHILE
	
	avg=(total/(count*25))*100;
	
	printf("\n\n"); //to create a space: \n x how many spaces desired
	printf("Total number of students: %d\n",count);
	printf("Average score percentage: %f\n",avg);
	printf("Total number of passes: %d\n",pass);
	printf("Total number of fails: %d\n\n",fail);
	
	system("Pause"); //pauses the screen
} //end program
