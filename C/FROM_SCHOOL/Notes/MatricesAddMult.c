/*C program to add and multiply two matrices*/

#include<stdio.h>

void main()
{
	int A[3][3], B[3][3], C[3][3], D[3][3];
	int row, col, i;
	
	//Reads elements in Matrix A
	printf("Enter elements of 3x3 Matrix A: \n");
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			scanf("%d",&A[row][col]);
		}//endfor
	}//endfor
	
	//Reads elements in Matrix B
	printf("\nEnter elements of 3x3 Matrix B: \n");
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			scanf("%d",&B[row][col]);
		}//endfor
	}//endfor
	
	//Addition of Matrix A & Matrix B
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			C[row][col]=A[row][col]+B[row][col];
		}//endfor
	}//endfor
	
	printf("\nMatrix A + Matrix B: \n");
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			printf("%d ",C[row][col]);
		}//endfor
		printf("\n");
	}//endfor
	
	//Multiplication of Matrix A & B
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			int sum=0;
			
			//Multiplies row of A to column of B
			for(i=0;i<3;i++){
				sum+=A[i][col]*B[row][i];
			
			}//endfor
			D[row][col]=sum;
		}//endfor
	}//endfor
	
	printf("\nMatrix A * Matrix B: \n");
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			printf("%d ",D[row][col]);
		}//endfor
		printf("\n");
	}//endfor
}
