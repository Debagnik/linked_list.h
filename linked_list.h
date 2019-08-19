// Linked_list.h file

//#ifndef _linked_list_h
#include<stdio.h>
#include<stdlib.h>
#define _linked_list_h

//Created by Debagnik Kar on aug 20th 2019

struct node {
   int data;
   struct node *next;
};

int count;
struct node *start=NULL;

void insertBegin(int n);
void insertEnd(int n);
void display();
void deleteList(int );

void insertBegin(int x)
{
	struct node *t;
   
	t = (struct node*)malloc(sizeof(struct node));
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
 
void insertEnd(int x) {
   struct node *t, *temp;
   
   t = (struct node*)malloc(sizeof(struct node));
   count++;
   
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   temp = start;
   
   while (temp->next != NULL)
      temp = temp->next;  
   
   temp->next = t;
   t->data    = x;
   t->next    = NULL;
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
   
   while (t->next != NULL) {
      printf("%d\n", t->data);
      t = t->next;
   }
   printf("%d\n", t->data);
}

void deleteList(int position)
{
	int i;
    struct node *toDelete, *prevNode;

    if(start == NULL)
    {
        printf("List is already empty.");
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

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }

}
