#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define length 4

int indexs=-1;

void enqueue(int queue[], int elem)
{
	if(indexs==(length-1))
	{
		printf("\nQueue full\n");
	}
	else
	{
		indexs++;
		queue[indexs]=elem;
	}
}

int dequeue(int queue[])
{
	int elem,i;
	if(indexs==-1)
	{
		printf("\nQueue empty\n");
	}
	else
	{
		elem=queue[0];
		for(i=0;i<indexs;i++)
		{
			queue[i]=queue[i+1];
		}
		indexs--;
	}
	
	return elem;
}

bool isEmpty()
{
	if(indexs==-1)
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
		return (indexs+1);
	}
}

void printAll(int queue[])
{
	int i;
	
	if(isEmpty())
	{
		printf("\nQueue is empty\n");
	}
	else
	{
		for(i=0;i<=indexs;i++)
		{
			printf("\n%d = %d\n",(i+1),queue[i]);
		}
	}
}

int main()
{
	int line[length],count;
	
	enqueue(line,120);
	enqueue(line,190);
	enqueue(line,1001);
	enqueue(line,166);
	
	printAll(line);
	
	dequeue(line);
	dequeue(line);
	
	printAll(line);
}
