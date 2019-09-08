// Linked_list.h source file

#ifndef linked_list_h
#include<stdio.h>
#include<stdlib.h>
#define _linked_list_h
#endif


//Created by Debagnik Kar on 20/08/2019(ddmmyyyy)
//last edited on 07/09/2019 (ddmmyyyy)

struct node   //structure allocation
{
   int data;
   struct node *next;
};

typedef struct node node;

int count;

node *start=NULL;

void insertBegin(int n);
void insertEnd(int n);
void display();
void deleteList(int position);

void insertBegin(int x)
{
	node *t;
   
	t = (node*)malloc(sizeof(node));
   	count++;
     
   	if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   t->data = x;
   t->next = start;
   start = t;
}
 
void insertEnd(int x)
{
   struct node *t, *temp;
   
   t = (struct node*)malloc(sizeof(struct node));
   count++;
   
   if (start == NULL)
   {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   temp = start;
   
   while (temp->next != NULL)
      temp = temp->next;  
   
   temp->next=t;
   t->data=x;
   t->next=NULL;
}

void display()
{
	struct node *t;
   
   t = start;
   
   if (t == NULL) {
      printf("Linked list is empty.\n");
      return;
   }
   
   printf("There are %d elements in linked list.\n", count);
   int i=0;
   while (t->next != NULL) 
   {
   		i++;
    	printf("%d\n", t->data);
    	t=t->next;
   }
   printf("%d\n",t->data);
}

void deleteList(int position)
{
	int i;
    struct node *toDelete, *prevNode;

    if(start == NULL)
    {
        printf("List is already empty.\n\n\n");
    }
    else
    {
        toDelete = start;
        prevNode = start;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == start)
                start = start->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;


            free(toDelete);
			count--;
            printf("Element Deleted\n\n\n");
        }
        else
        {
            printf("Invalid position unable to delete.\n\n\n");
        }
    }

}
