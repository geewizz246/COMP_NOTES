#include<stdio.h>
#include<stdlib.h>
main()
{
	int prod,multiple,n;
	prod=1;
	n=2;
	multiple=0;
	
	while(multiple<12)
	{
		multiple=6*n;
		prod=prod*multiple;
		n=n+1;
	}
	
	printf("%d\n",prod);
}
