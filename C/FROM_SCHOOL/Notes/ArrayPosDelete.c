#include<stdio.h>

void main()
{
	int i, n, pos;
	int arr[n];
	
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	printf("Enter elements into the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("Current elements in the array are as follows: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	printf("\nEnter element position to delete from array: ");
	scanf("%d",&pos);
	
	while((pos>=n)||(pos<0)){
		printf("\nInvalid position! Try again: ");
		scanf("%d",&pos);
	}
	
	for(i=pos;i<n-1;i++)
		arr[i]=arr[i+1];
		
	n=n-1;
	
	printf("\nArray: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
