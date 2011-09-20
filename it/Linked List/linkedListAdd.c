#include<stdio.h>
#include<stdlib.h>

///////////////////////////////

/* This code adds two (long numbers given as) linked lists */
/* and return result linked list */

/* This code is not giving required output. */
/* Problem might be in other function like add, newNode  */
/* Logically main linked list addition functions are correct. */
/* So Debug and fix the bug. */

///////////////////////////////

struct list{
  int data;
  struct list* next;
};

typedef struct list list;
 
//////////// other functions ///////////////////

void printList(list* head)
{
  printf("\n");
  while(head)
    {
      printf("%d  ->",head -> data);
      head = head -> next;
    }
  printf("NULL\n");
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

//////////// helper functions ///////////////////

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

void copy(list** r, list* l){
  list *prev = NULL, *new = NULL;
  while(l){
    new = newNode(l -> data);
    if(!(*r)){
      *r = new;
    }
    else{
      prev -> next = new;
    }
    prev = new;
    new = NULL;
    l = l -> next;
  }
}

void appendNode(list** result, list* new){
  new -> next = *result;
  *result = new;
}

/////////////// Main Functions ///////////////////

int addLists(list* h1, list* h2,list** r){
  int carry=0;
  
  if(!h1 && !h2)return 0;
  if(!h1 && h2) {copy(r,h2);return 0;}
  if(h1 && !h2) {copy(r,h1);return 0;}

  if(!h1->next && !h2->next){
    carry = add(h1->data, h2->data,r);
   } 
  else if(h1->next && !h2->next){
    carry = addLists(h1->next,h2,r);
    carry = add(carry, h1->data,r);
   }
  else if(!h1->next && h2->next){
    carry = addLists(h1,h2->next,r);
    carry = add(carry, h2->data,r);
   } 
  else{carry = addLists(h1->next,h2->next,r);} 

  return carry;
}

list* addLinkedList(list * head1,list* head2){
  list* result=NULL;
  int carry=0;

  if( (carry = addLists(head1, head2,&result)) > 0){
    appendNode(&result, newNode(carry));
  }
  return result;  
}

///////////////////////////////

int main(){
  list *head1=NULL, *head2= NULL, *head3 = NULL;
  list *tail1, *tail2; 

  printf("creat 1st linked list\n");
  creatLinkedList(&head1,&tail1);
  printf("creat 2nd linked list\n");
  creatLinkedList(&head2,&tail2);

  printf("Linked Lists you created are as \n");
  printList(head1);
  printf("\n");
  printList(head2);
   
  head3 = addLinkedList(head1, head2);
  printf("After addition result linked lists => \n ");
  printList(head3);

  return 0;
}
///////////////////////////////
