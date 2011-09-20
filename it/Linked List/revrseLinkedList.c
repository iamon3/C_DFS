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

/**********************/

linkedList* recursivelyReverseList2( linkedList* head )
{
  if(!head || !(head -> next))
    { return head;}

  recursivelyReverseList2(head -> next) -> next = head ;
  head -> next = NULL;

  return head;
}

/**********************/

linkedList* recursivelyReverseList1(linkedList* head)
{
  if (!head || !(head -> next))
    return head;
  linkedList *temp = NULL;

  temp = recursivelyReverseList1(head -> next);
  head -> next -> next = head ;
  head -> next = NULL;
  return temp;  
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
  printf("\n-----------------   After Linked List created   head = %d \t tail = %d-------- \n\n",head-> data ,tail -> data);
  printList(head);


  tail = head ;
  head = recursivelyReverseList1(head);
  printf("-----------------   After Recursive reverse1   head = %d \t tail = %d-------- \n\n",head-> data ,tail -> data);
  printList( head );
  

  tail =head;
  recursivelyReverseList2(head);
  printf("-----------------   After Recursive reverse2   head = %d \t tail = %d-------- \n\n",head-> data ,tail -> data);
  printList(tail);

  tail = head;
  head = iterativeReverseList( head );
  printf("-----------------   After Iterative reverse   head = %d \t tail = %d-------- \n\n",head-> data ,tail -> data);
  printList( head );

  return 0;
}

////////////////////////////////////////////////////////
