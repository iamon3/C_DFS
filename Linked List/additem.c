#include<stdio.h>
#include<stdlib.h>

int num;
struct linked_list
{
  int item;
  struct linked_list *next;
};

typedef struct linked_list node;

void createList(node **start);
void insertitem(node **start,int num);
void appendList(node **start);
void prependList(node **start);
int searchItem(node **, int );
int delItem(node **start ,int no);
int reverseList(node **start);
void printLinkedList(node **start);

int main()
{
  int no,option ,searchValue;  
  node *head ;
  head = NULL;
  createList(& head);
  
  printf("current linked list : \n");
  printLinkedList(& head);
  
  //printf("\n Enter position after which you want to insert no. : ");
  //scanf("%d",&num);
  printf("Enter option u want :\n");
  scanf("%d",&option); 
  
  switch (option){
  
  case 1:
    insertitem(&head , num);
    //printf("modified linked list :\n");  
    printLinkedList(& head);
    break;
    
  case 2:
    appendList(&head);
    // printf("modified linked list :\n");  
    printLinkedList(& head);
    break;

  case 3:
    prependList(&head);
    printLinkedList(&head);
    break;

  case 4:
    
    printf("Enter no. u want to search :\n");
    scanf("%d",&searchValue);
    searchItem(&head,searchValue);
    //printLinkedList(&head);
    break;

  case 5:
    printf("Enter no. you want to delete :\n");
    scanf("%d",&no);
    delItem( &head , no );
    printLinkedList(&head);

  case 6:
    reverseList(**start);
  }
   return 0;
}

void insertitem(node **start, int num)
{
  node *temp,*new;
  int i;
  temp = *start;
  printf("\n Enter position after which you want to insert no. : ");
  scanf("%d",&num);
  for(i=1;i<num;i++)
    {
      temp = temp->next;
    }
  if(temp == NULL)
    {
      printf("ERROR: Number is not there\n");
      return;
    }
  new=(node *)malloc(sizeof(node));
  printf("Enter value to be inserted : \n");
  new->next = temp->next;
  scanf("%d",&(new->item));
  temp->next = new;
}


void createList(node **start)
{
  int sizeOfLinkedList,i=0 ;
   node *temp, *current;
  

  temp = (node *)malloc(sizeof(node));
  temp->next=NULL;

  printf("Enter size of linked list to be created :\n");
  scanf("%d",&sizeOfLinkedList);

  printf("Enter items  :\n");
  scanf("%d",&(temp->item));

  *start=current=temp;
  while(i<sizeOfLinkedList-1)
    {
      temp = (node *)malloc(sizeof(node)); 
      scanf("%d",&(temp->item));
      temp -> next=NULL;
      current->next=temp;
      current=current->next;
      i++;
    }
  current->next=NULL;
  
  //while(current!=NULL)
  //{
    // printf("%d",current->item);
    //current=current->next;
    //}
}


void appendList(node **start)
{
  node *temp,*end;
  temp = *start;
  end=(node *)malloc(sizeof(node));
  end -> next = NULL;
  printf("Enter Value:\n");
  scanf("%d",&(end->item));
  printf("Hi\n");
  while((temp->next)!=NULL)
    {
      temp = temp -> next;
    }
  temp -> next = end;
}

void prependList(node **start)
{
  node *begin;
  begin=(node *)malloc(sizeof(node));
  printf("Enter No :\n");
  scanf("%d",&(begin -> item));
  begin -> next = *start ;
  *start = begin ;
}

int searchItem(node **start , int no)
{
  node *temp ;
  int flag=0,count=1;
  temp = *start;
  while((temp->next)!=NULL)
    {
      if((temp->item)==no)
      {
	flag=1;
	break;
      }
      temp = temp -> next;
      count+=1;
    }
 if((temp -> next)==NULL && (temp->item)==no && flag==0)
      {
	flag=1;
	count+=1;
      }
 if(flag=1)
   {printf("Element present :\n");
   return count;}
 else
   {printf("Not present : \n");
   return flag;}
}

int delItem(node **start1 ,int no)
{
  node *temp,*prev;
  int position, i;
  temp=*start1;
  position = searchItem(start1,no);
  if(position!=0)
    {
      for(i=1;i<no;i++)
	{
	  prev=temp;
	  temp = temp -> next;
	}
      prev -> next = temp -> next;
      free(temp);
      // return 1;
    }
  return 1;
}
int reverseList(node **start)
{
  if(*start==NULL)
    {
      return NULL;
    }
}
void printLinkedList(node **start)
{
  node *temp ;
  temp=*start;
  printf("modified linked list :\n");  
  while(temp!=NULL)
    {
      printf("%d -> ",temp -> item);
      temp=temp->next;
    }
  printf("\n\n");
}
