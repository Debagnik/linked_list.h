//queue.h source file

#ifndef linked_list_h
#include<stdio.h>
#include<linked_list.h>
#define _queue_h
#endif

//created by Debagnik Kar on 07/09/2019 (ddmmyyyy)
//last edited on (not edited yet) (ddmmyyyy)

int rear,front;
void enqueue();
void dequeue();


void enqueue()
{
	int n;
	rear=0;
	front=0;
	//implimenting Linked list
	printf("Enter number of elements to be entered");
	scanf("%d",&n);
	int i=0,element;
	while(i<n)
	{
		printf("Enter Element[%d]",i);
		scanf("%d",&element);
		
		insertEnd(element);
		rear++;
		i++;
	}
}

void dequeue()
{
	deleteList(front);
	front++;
}

