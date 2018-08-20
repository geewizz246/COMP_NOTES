#include <stdio.h>
#include <stdlib.h>


main()
{
 int i,a;
 int num1[10];
 int num2[10];


  for(i=0;i<10;i++) //stops when you get a zero

   { 
    printf("Enter a number\n");
    scanf("%d",&num1[i]);
   

		for(a=9;a<1;a--) //stops when you get a zero
		{ 
    		num2[a]=num1[i];

  		}

   }

  for (i=0;i<10;i++)
  {
   printf("%d\t",num2[a]);
  }

}
