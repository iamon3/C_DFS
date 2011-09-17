/* This non-returning recursive function used to creat double linked list , realloc function is used here to create doubly liked list  */

#include<stdio.h>
#include<stdlib.h>

int count =1;


struct node
{
  int value;
  struct node *next;
  struct node *prev;
};

typedef struct node node;

void printDoublyLinkedList(node* head);
void printDoublyReverseLinkedList(node* tail);
void creatDoublyLinkedList(node** head,node** tail);

int main()
{
  node *head=NULL,*tail=NULL;
  creatDoublyLinkedList(&head, &tail);
  printDoublyLinkedList(head);
  printDoublyReverseLinkedList(tail);
  return 0;
}

void creatDoublyLinkedList(node **head,node **tail)
{   char c;
  printf("Do you want to insert element \n");
  c=getchar();
  if(c=='Y')
    {
      node* new=NULL;                                                       // Here NULL is imp else it gives error //
      int data;
      printf("Enter no :\n");
      scanf("%d",&data);
      new=(node *)realloc(new,(sizeof(node))*count);
      count +=1;
      new->value=data;
      //  printf("%d\n",new->value);
      new -> next = NULL;
      if(*head == NULL)
	{
	  new -> prev =NULL;
	  *head=*tail=new;
	  creatDoublyLinkedList(&*head,&*tail);
	}
      else
	{
	  new -> prev  = *tail;
	  (*tail) -> next = new;
	  (*tail) = (*tail) -> next;
	  creatDoublyLinkedList(&*head,&*tail);
	}
    }
  else if(c=='N')
    {
      printf("Thank you \n");
    }
  else
    {
      printf("Wrong Input . You inputted = %c \n",c);
      creatDoublyLinkedList(&*head,&*tail);
    }
}

void printDoublyLinkedList(node* head)
{
  if(head)
    {
      printf("%d -> ",head->value);
      printDoublyLinkedList(head -> next);
    }
  else
    {
      printf("End\n");
    }
}


void printDoublyReverseLinkedList(node* tail)
{
  if(tail)
    {
      printf("%d <- ",tail->value);
      printDoublyReverseLinkedList(tail -> prev);
    }
  else
    {
      printf("Start\n");
    }
}
