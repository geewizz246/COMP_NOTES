#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> /*allows for boolean logic functions, true and false*/
#define length 4 /*number of elements in queue*/

int indexs =-1; /*initialising indexs*/
/*global variable, can be used anywhere in the program*/
/*keeps track of the POSITION of the tail of the queue*/

void enqueue(int queue[],int elem) /*adds elements to the tail of the queue*/
{
	/*if queue is full something must prevent entering more elements into queue*/
	if(indexs==(length-1)) /*last position in the queue i.e. the tail*/
	{
		printf("\nQueue full\n");
	}
	else
	{
		indexs=indexs+1;
		queue[indexs]=elem;
	}
}//end enqueue

int dequeue(int queue[]) /*removes elements from the head of the queue*/
{
	int x,elem;
	/*if queue is empty something must prevent removing more elements from queue*/
	if(indexs==-1)
	{
		printf("\nQueue empty\n");
	}
	else
	{
		elem=queue[0]; /*allows the other elements to shift upwards in queue*/
		for(x=0;x<indexs;x++)
		{
			queue[x]=queue[x+1];
		}
		indexs--; /*moves the position of index (i.e. the tail) up by 1 (eg: if index was 3 it becomes 2)*/
		/*when function enqueue is executed again, what is in the last position in the queue is overwritten (eg: what was in position 3 would be overwritten)*/
	}
}//end dequeue

bool isEmpty() /*checks if the queue is empty*/
{
	if(indexs==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}//end isEmpty

int size() /*determines the number of elements in the queue*/
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return (indexs+1);
	}
}//end size

void printAll(int queue[]) /*prints the element in the queue*/
{
	int i;
	if(isEmpty())
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("The elements are:\n\n");
		for(i=0;i<=indexs;i++)
		{
			printf("%d\t%d\n\n",i,queue[i]);
		}
	}
}//end printAll

int main()
{
	int queues[length];
	
	enqueue(queues,120); /*adding an element*/
	enqueue(queues,190);
	enqueue(queues,1001);
	enqueue(queues,166);
	
	printAll(queues); /*prints contents of queue*/
	
	dequeue(queues); /*removing an element*/
	dequeue(queues);
	
	int num=size(); /*call to size which returns number of elements in the queue*/
	
	printf("The number of elements in the queue are---->%d\t\n\n",num);
	
	printAll(queues);
	
	system("pause");
}//end program
