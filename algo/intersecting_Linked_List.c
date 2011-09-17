#include<stdio.h>
#include<stdlib.h>

struct linkedListNode
{
  int data;
  struct linkedListNode *next;
};
typedef struct linkedListNode linkedListNode;

int count =1;

void checkTwoLinkedListIntersect(linkedListNode* head1,linkedListNode* head2);
void printLinkedList(linkedListNode* head);
void intersect (linkedListNode** head1,linkedListNode** tail1,linkedListNode** tail2,int count);
void createLinkedList(linkedListNode** head, linkedListNode** tail);

int main()
{
  char c;
  linkedListNode *head1=NULL,*head2=NULL, *tail1=NULL, *tail2=NULL;

  printf("\nCreat first linked list ");
  createLinkedList(&head1,&tail1);

  printf("\nCreat second linked list ");
  createLinkedList(&head2,&tail2);

  printf("\n");
  printLinkedList(head1);
  printLinkedList(head2);

  printf("\nDo you want to intersect 2nd list to 1st (Y/N):");
  scanf(" %c",&c);

  if(c=='Y')
    {
      int pointOfIntersection;
      
      printf("\nEnter no of node where you want to intersect :");
      scanf("%d",&pointOfIntersection);
      //printf("hello\n");
      intersect (&head1,&tail1,&tail2,pointOfIntersection);
      printf("\n");
      printLinkedList(head1);
      printLinkedList(head2);
    }
  else if(c=='N')
    {
      printf("\n");
      printLinkedList(head1);
      printLinkedList(head2);
    }
  else
    {
      printf("Wrong Input\n");
    }
  checkTwoLinkedListIntersect(head1,head2);
  
  return 0;
}

void createLinkedList(linkedListNode** head,linkedListNode** tail)
{
  char c;
  printf("\nDo you want insertion (Y/N):");
  scanf(" %c",&c);

  if(c=='Y')
    {
      linkedListNode* new=NULL;
      int data;

      printf("\nEnter value :");
      scanf("%d",&data);
      new=(linkedListNode*)realloc(new,sizeof(linkedListNode)*count);
      count += 1;
      new -> data = data;
      new -> next = NULL;

      if(*head==NULL)
	{
	  (*head) = (*tail) = new;
	}

      else
	{
	  (*tail) -> next = new;
	  (*tail) = (*tail) -> next ;
	}
      
      createLinkedList(&*head,&*tail);
      return ;
    }

  else if(c=='N')
    {
      printf("\nThank You .");
      count =1;
      return ;
    }

  else
    {
      printf("Wrong input.");
      createLinkedList(&*head,&*tail);
      return ;
    }
  return ;
}


void printLinkedList(linkedListNode* head)
{
  if(head)
    {
      printf("%d -> ",head->data);
      printLinkedList(head->next);
      return;
    }

  else
    {
      printf("END\n");
    }

  return ;
}


void intersect (linkedListNode** head1,linkedListNode** tail1,linkedListNode** tail2,int count)
{
  linkedListNode* temp;
  temp = (*head1);
  printf("HI\n");

  while ((count-1)!=0)
    {
      temp = temp -> next ;
      count -= 1 ;
    }

  (*tail2) -> next = temp ;
  (*tail2) = (*tail1);
}


void checkTwoLinkedListIntersect(linkedListNode* head1,linkedListNode* head2)
{
  while((head1->next) != NULL)
    {
      head1 = head1 -> next;
    }
  while((head2->next) != NULL)
   {
     head2 = head2 -> next;
   }

  if(head1==head2)
    {
      printf("\nTwo list are intersecting.\n");
    }
  else
    {
      printf("\nTwo list are not intersecting.\n");
    }

}
