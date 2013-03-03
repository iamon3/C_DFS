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

linkedList* iterativePartByPartReverseList( linkedList* head, int n)
{
  linkedList *currentHead = head, *prevHead = NULL, *nextHead = NULL;
  linkedList *pStart = NULL, *sStart = currentHead;
  int cnt = n;
  while( sStart /*currentHead */)
    {
	  if(cnt > 0){
		if(currentHead){
		nextHead = currentHead -> next ;
		currentHead -> next = prevHead;
		prevHead = currentHead;
		currentHead = nextHead;				  
		}
		cnt--;
	  }
     else{
		 if(pStart){ pStart -> next = prevHead;}
		 else{ head = prevHead;}
		 pStart = sStart;
		 prevHead = NULL;
		 sStart = currentHead;
		 cnt = n;
      }
    }  
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
  printf("\n-----------------   After Linked List created   head = %d \t tail = %d-------- \n\n",head-> data ,tail -> data);
  printList(head);
 
  int n = 3;
  printf("Enter no of nodes, which constitues the part and needs to be reversed :- \n");
  scanf("%d",&n);
  head = iterativePartByPartReverseList( head , n);
  printf("-----------------   After part by part reverse   head = %d \n",head-> data);
  printList( head );

  return 0;
}
////////////////////////////////////////////////////////
