#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> /*allows for boolean logic functions, true and false*/
#define length 4 /*number of elements in queue*/

int top=-1; /*global variable*/

/*Push method - adds element to top of stack*/
void push(int stack[],int elem)
{
	if(top==(length-1))
	{
		printf("Stack Overflow\n");
		
	}
	else
	{
		top++; /*increment top*/
		stack[top]=elem;
	}//end else
}//end push


/*Pop method - deletes an element from the top of the stack*/
int pop(int stack[])
{
	int value;
	
	/*check for error situation*/
	if(top==-1)
	{
		printf("Stack already empty\n");
	}
	else /*stack can be popped*/
	{
		value=stack[top];
		top--; /*decrement top*/
	}//end else
	
	return value;
}//end pop


/*printAll() prints contents of stack*/
void printAll(int stack[])
{
	int i;
	
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("The elements are\n\n");
		for(i=0;i<=top;i++)
		{
			printf("%d\t%d\n\n",i,stack[i]);
		}//end for
	}//end else
}//end printAll


/*isEmpty() checks if stack is empty*/
bool isEmpty()
{
	if(top<0)
	{
		return true;
	}
	else
	{
		return false;
	}//end else
}//end isEmpty


/*size() returns number of elements in stack*/
int size()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return (top+1);
	}//end else
}//end size


int main()
{
	int stacks[length],numElements,elem1,elem2;
	
	push(stacks,20); /*adding an element*/
	push(stacks,90);
	push(stacks,100);
	push(stacks,166);
	
	printAll(stacks); /*prints contents of stack*/
	
	/*removing elements from stack*/
	elem1=pop(stacks);
	printf("Element popped is--->%d\n",elem1);
	elem2=pop(stacks);
	printf("Element popped is--->%d\n",elem2);
	printAll(stacks);
	
	numElements=size(); /*finds number or elements in stack*/
	printf("The number of elements in the stack are--->%d\t\n\n",numElements);
	
	system("pause");
}//end program
