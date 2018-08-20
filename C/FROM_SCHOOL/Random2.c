#include<stdio.h>
#include<stdlib.h>

main()
{
	int i,j,final=1;
	
	for(j=6;j>0;j=j-2)
	{
		i=j/2;
		
		while(i<=j)
		{
			printf("i is %d j is %d\n",i,j);
			j--;
			final=final+i*j;
		}
		printf("New i = %d\n",i);
	}
	printf("\nFinal Output: %d\n",final);
}
