#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////

struct linkedList
{
  int data;
  struct linkedList *next;
};

typedef struct linkedList linkedList;


////////////////////////////////////////////////////////

void printList(linkedList* head)
{
  printf("\n");
  while(head)
    {
      printf("%d  ->",head -> data);
      head = head -> next;
    }
  printf("NULL\n");
}

////////////////////////////////////////////////////////

linkedList* iterativeReverseList( linkedList* head )
{
  if(!head)
    { return NULL ; }

  linkedList *prevHead = NULL,*nextHead = NULL;

  while( head )
    {
      nextHead = head -> next ;
      head -> next = prevHead;
      prevHead = head;
      head = nextHead;
    }  

  return prevHead;
}



linkedList*  recursivelyReverseList(linkedList* head)
{
  if(!head)
    { return NULL;}

  if(!head->next)
    {return head ;}

  recursivelyReverseList(head -> next) -> next = head ;
  head -> next = NULL;
  return head;
}

////////////////////////////////////////////////////////

void prependNode(linkedList** head,linkedList** tail)
{
  linkedList* new;
  new = (linkedList *)malloc(sizeof(linkedList));
  printf("\nEnter value in node :-");
  scanf("%d",&(new -> data));

  if(!*head)
    {
      (*head) = (*tail) = new ;
      (*tail) -> next = NULL;
    }
  else
    {
      new -> next = *head ;
      *head = new ;
    }
}


////////////////////////////////////////////////////////

void creatLinkedList(linkedList** head,linkedList** tail)
{
  char userSays;
  printf("\nDo you want insertion(y/n) :-");
  scanf(" %c",&userSays);

  if(userSays == 'y')
    {
      prependNode(&*head,&*tail);
      creatLinkedList(&*head,&*tail);
    }
  else if (userSays == 'n')
    {
      printf("\nThank you");
      return;
    }
  else 
    {
      printf("\nWrong input");
      creatLinkedList(&*head,&*tail);
    }
}


////////////////////////////////////////////////////////

int main()
{
  linkedList* head = NULL, *tail = NULL ;
  creatLinkedList(&head,&tail);
  printList(head);
  printf("\n\thead = %d\ttail = %d\n",head -> data , tail -> data);

  recursivelyReverseList(head);
  printList(tail);
  //  printf("\n\thead = %d\ttail = %d\n",head -> data , tail -> data);

  linkedList* temp;
  temp = head;
  head = tail;
  tail = temp;

  printf("\n\thead = %d\ttail = %d\n",head -> data , tail -> data);

  tail = head;
  head = iterativeReverseList( head );
  printList( head );
  printf("\n\thead = %d\ttail = %d\n",head -> data , tail -> data);
  return 0;
}

////////////////////////////////////////////////////////
