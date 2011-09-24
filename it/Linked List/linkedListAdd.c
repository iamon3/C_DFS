#include<stdio.h>
#include<stdlib.h>
#include<math.h>

///////////////////////////////

/* Works Perfectly. Only trick here in recursion is to check current head, */
/* lengths of two linked list. */
/* There can be more efficient solution of without calculating length. */
/* Will try some time.  */

///////////////////////////////

struct list{
  int data;
  struct list* next;
};

typedef struct list list;
 
///////////////////////////////

int printList(list* head)
{
  int count = 0;
  printf("\n");
  while(head)
    {
      count += 1;
      printf("%d  ->",head -> data);
      head = head -> next;
    }
  printf("NULL\n");
  return count;
}

void prependNode(list** head,list** tail)
{
  list* new;
  new = (list *)malloc(sizeof(list));
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

void creatLinkedList(list** head,list** tail)
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

///////////////////////////////

list* newNode(int data){
  list* new=NULL;
  new = (list*)malloc(sizeof(list));
  new -> next = NULL;
  new -> data = data;
  return new;
}

int add(int a, int b, list** r){
  int q =0, rm =0;  //quotient, remainder
  list* new = NULL;
 
   q = ( a +b ) / 10;
  rm = (  a +b ) % 10;
 
 if(!(*r)){
   new = newNode(0);
    *r = new;
    (*r) -> data = rm;
  }
 else{
   new = newNode(rm);
   new  -> next = *r;
  *r = new;
 }
  return q;
}

void appendNode(list** result, list* new){
  new -> next = *result;
  *result = new;
}

///////////////////////////////

int addLists(list* h1, list* h2,list** r, int diff){
  int carry=0;
  
  if(!h1 && !h2)return 0;
  
  if(diff >0){
    carry = addLists(h1->next,h2,r,diff - 1);
    carry = add(carry, h1 -> data, r);
    return carry;
  }

  if(!h1->next && !h2->next){
    carry = add(h1->data, h2->data,r);
   } 
  else{
    carry = addLists(h1->next,h2->next,r,diff);
    carry = add(carry + h1->data, h2->data,r);
   } 

  return carry;
}

void swap(list** h1, list** h2){
  list* temp;
  temp = (*h1);
  *h1 = *h2;
  *h2 = temp;
}

list* addLinkedList(list * head1,list* head2, int l1, int l2){
  list* result=NULL;
  int carry=0;

  if(l2 > l1){swap(&head1,&head2);}

  if( (carry = addLists(head1, head2,&result, abs(l1-l2))) > 0){
    appendNode(&result, newNode(carry));
  }
  return result;  
}

///////////////////////////////

int main(){
  list *head1=NULL, *head2= NULL, *head3 = NULL;
  list *tail1, *tail2; 
  int length1 = 0 , length2 = 0;
  printf("creat 1st linked list\n");
  creatLinkedList(&head1,&tail1);
  printf("creat 2nd linked list\n");
  creatLinkedList(&head2,&tail2);

  printf("Linked Lists you created are as \n");
  length1 = printList(head1);
  printf("\n");
  length2 = printList(head2);
   
  head3 = addLinkedList(head1, head2, length1, length2);
  printf("After addition result linked lists => \n ");
  printList(head3);

  return 0;
}
///////////////////////////////
