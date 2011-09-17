
#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////////////

struct doublyLinkedListNode
{
  int data;
  struct doublyLinkedListNode* next;
  struct doublyLinkedListNode* prev;
};

typedef struct doublyLinkedListNode doublyLinkedListNode;

///////////////////////////////////////////////////////

void printList(doublyLinkedListNode* head)
{
  printf("\tNULL  <=>  ");

  while(head)
    {
      printf("%d  <=>  ",head -> data);
      head = head -> next;
    }
  printf("NULL\n");
}

///////////////////////////////////////////////////////


doublyLinkedListNode* reverseListRecursively(doublyLinkedListNode* head)
{
  if( !head )
    { return NULL; }

  if( !head -> next && !head -> prev )
    { return head; }

  if( !head -> next && head -> prev )
    { return head; }
  
  doublyLinkedListNode* temp = NULL;
  temp = reverseListRecursively(head -> next);
  
  temp -> next = head ;
  temp -> prev  = NULL;
  head -> next = NULL;
  head -> prev = temp;
  
  return head;
}


doublyLinkedListNode* reverseListIteratively( doublyLinkedListNode* head )
{
  if(!head)
    { return NULL ;}

  doublyLinkedListNode *nextOfHead , *currentHead ;

  while( head )
    {
      currentHead = head ;
      nextOfHead = head -> next ;
      head -> next = head -> prev ;
      head -> prev = nextOfHead;
      head = head -> prev;
    }
  return currentHead;
}

///////////////////////////////////////////////////////

void appendNode(doublyLinkedListNode** head,doublyLinkedListNode** tail)
{
  doublyLinkedListNode* new;

  new = ( doublyLinkedListNode * )malloc(sizeof(doublyLinkedListNode));
  new -> next = NULL;  
  new -> prev = NULL ;

  printf("\nEnter value :- ");
  scanf("%d",&(new ->data ));
  
  if(!*head)
    {
      (*head) = (*tail) = new ;
      return;
    }
  else
    {
      (*tail) -> next = new ;
      new -> prev = (*tail) ;
      (*tail) = new;
    }
  return;
}


void creatDoublyLinkedList(doublyLinkedListNode** head,doublyLinkedListNode** tail)
{
  char userSays;

  printf("\nDo you want insertion (y/n):-");
  scanf(" %c",&userSays);

  if(userSays == 'y')
    {
      appendNode(&*head,&*tail);
      creatDoublyLinkedList(&*head,&*tail);
      return;
    }
  else if(userSays == 'n')
    {
      printf("\nDoubly linked list created as follows\n");
      return ;
    }
  else
    {
      printf("\nWrong input:");
      creatDoublyLinkedList(&*head,&*tail);
      return ;
    }
}

///////////////////////////////////////////////////////

void swapHeadAndTail( doublyLinkedListNode** head ,doublyLinkedListNode** tail)
{
  doublyLinkedListNode* temp;
  temp = (*head);
  (*head) = (*tail);
  (*tail) = temp ;
}

///////////////////////////////////////////////////////

int main()
{
  doublyLinkedListNode *head=NULL ,*tail=NULL;

  creatDoublyLinkedList( &head , &tail );
  printList( head );

  printf("head = %d\ttail=%d\n\n",head->data,tail->data);  

  tail = head ;     /* Since after Iterative Reverse Head reaches to tail node one by one , head need to be saved otherwise it will b lost  & no need to save tail as head 
		       reaches tail....Hence tail = head done ..*/
 
  printf("--------------------------------------------------------------------");
  printf("\n\nNow Iterative reversing\n");  
  head = reverseListIteratively( head );
  printList( head );
  printf("Iterative reversuing changes head to tail node i.e. head  poins to tail  after reversing \n head = %d\ttail=%d\n\n",head->data,tail->data);  

  printf("--------------------------------------------------------------------");
  printf("\n\nBefore swapping Head And Tail\nhead = %d\ttail=%d\n",head->data,tail->data);  

  swapHeadAndTail(&head , &tail);
  
  printf("after swapping Head And Tail\nhead = %d\ttail=%d\n",head->data,tail->data);  
  printf("--------------------------------------------------------------------");
  
  printf("\n\nNow Recursive reversing\n");  
  tail = reverseListRecursively( tail );
  printList( head );
  printf("Recursive reversuing keeps head and tail unchanged i.e. head still poins to same node after reversing as it was before reversing \n head = %d\ttail=%d\n\n",head->data,tail->data);  

  return 0;
}

///////////////////////////////////////////////////////
