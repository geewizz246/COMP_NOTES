/*C program to print Pascal triangle up to n rows*/
/*Note, to get any term in pascal triange use equation: n!/(k!(n-k)!)*/

#include<stdio.h>

//Function to calculate factorial
int factorial(int n)
{
	int fact=1;
	while(n>=1)
	{
		fact*=n;
		n--;
	}//endwhile
	
	return fact;
}//end factorial

void main()
{
	int n, k, num, i;
	long term;
	
	printf("Enter number of rows : ");
    scanf("%d", &num);
 
    for(n=0; n<num; n++)
    {
        //Prints 2 spaces
        for(i=n; i<=num; i++)
            printf("%2c",' ');
 
        for(k=0; k<=n; k++)
        {
            term = factorial(n)/( factorial(k) * factorial(n-k));
            printf("%4ld", term);
        }//endfor
 
        printf("\n");
    }//endfor
}
