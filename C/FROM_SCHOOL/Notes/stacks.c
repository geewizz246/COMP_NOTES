#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define length 4

int top=-1;

void push(int elem)
{
	if(top==(length-1))
	{
		printf("\nSTACK OVERFLOW\n");
	}
	else
	{
		top++;
		stack[top]=elem;
	}
}

int pop(int stack[])
{
	int elem;
	
	if(top==-1)
	{
		printf("\nSTACK EMPTY\n");
	}
	else
	{
		elem=stack[top];
		top--;
	}
	
	return elem;
}

bool isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int size()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return (top+1);
	}
}

void printAll(int stack[])
{
	int i;
	
	if(isEmpty())
	{
		printf("\nSTACK EMPTY\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("\n[%d] = %d\n",i,stack[i]);
		}
	}
}

int main()
{
	int stacks[length],element,count;
	
	push(20);
	push(90);
	push(100);
	push(166);
	
	printAll(stacks);
	
	printf("\n\n\nSize of stack ----> %d\n\n",count=size());
	
	element=pop(stacks);
	printf("\n\nPopped element ----> %d\n",element);
	element=pop(stacks);
	printf("Popped element ----> %d\n\n",element);
	
	printAll(stacks);
	
	printf("\n\n\nSize of stack ----> %d\n\n",count=size());
}

