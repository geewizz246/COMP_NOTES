#include<stdio.h>
#include<stdlib.h>

main()
{
	int i,j,num[5];
	
	for(i=0;i<5;i++){
		scanf("%d",&num[i]);
	}
	
	for(j=0;j<5;j++){
		printf("\n%d",num[j]);
	}
}
