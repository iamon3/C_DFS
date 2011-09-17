#include<stdio.h>
#include<stdlib.h>

int nodeNo=1;

struct polynomial
{
  int coefficient;
  int power;
  struct polynomial *next;
  struct polynomial *prev;
};

typedef struct polynomial polynomial;

void selectionSort(polynomial **head, polynomial *tail);
void printResult(polynomial *head);
void creatPolynomialList(polynomial** head, polynomial** tail);
void printMenu();
//void selection();

int main()
{
  polynomial *head=NULL, *tail=NULL;
  //selection(&head,&tail);
  //printMenu();
  creatPolynomialList(&head,&tail);
  printResult(head);
  selectionSort(&head,tail);
  return 0;
}

void printMenu()
{
  printf("\n\n########  MENU #########\n");
  printf("\n1) CREAT \n2) PRINT \n3) ADDITION \n4) SUBTRACTION \n5) DERIVATION \n6) MULTIPLICATION \n7) EXIT\n\n\tPRESS OPTION: ");
  //selection(&head,&tail);
}

/* void selection(polynomial *head,polynomial *tail)
{
  int optionNo;
  scanf("%d",&optionNo);
  switch(optionNo)
    {
    case 1:
      {
	creatPolynomialList(&head,&tail);
	break;
      }
    case 2:
      {
	void printResult(*head,*tail);
	break;
      }
    case 3:
      {
      }
    case 4:
      {
      }
    case 5:
      {
      }
    case 6:
      {
      }
    case 7:
      {
	break;
      }
    }
} */

void creatPolynomialList(polynomial** head, polynomial** tail)
{
  polynomial* new=NULL;
  char c;
  int coefficient,power;
  printf("Do you want insertion ? (Y/N) :");
  scanf(" %c",&c);
  //getchar();

  if(c=='Y')
    {
      printf("Enter coefficient and power\n");
      scanf("%d%d",&coefficient,&power);
      new=(polynomial *)realloc(new,sizeof(polynomial)*nodeNo);
      new -> coefficient = coefficient;
      new -> power = power;
      new -> next = NULL;
      
      if(*head==NULL)
      {
	printf("first node\n");
	new -> prev = NULL;
      	(*head)=(*tail) = new;
	nodeNo += 1;
	creatPolynomialList(&*head,&*tail);
      }
      else
	{
	  new -> prev = (*tail) ;
	  (*tail) -> next = new ;
	  (*tail) = (*tail) -> next ;
	  printf("Inserted\n");
	  nodeNo += 1;
	  creatPolynomialList(&*head,&*tail);
	}
    }

  else if(c=='N')
    {
      nodeNo = 0;
      printf("Thank You\n");
      //      printMenu();
    }

  else
    {
      printf("Wrong Input:: %c\n",c);
      creatPolynomialList( &*head, &*tail );
    }
}

void printResult(polynomial *head)
{
  if(head)
    {
      printf("(%d x^%d) + ",head->coefficient,head->power);
      printResult(head -> next);
    }
  else
    {
      printf("END\n");
      printMenu();
    }
}


void selectionSort(polynomial **head, polynomial *tail)
{
   if((*head)== tail)
     {
       printResult(*head);
     }
   else
     {
      polynomial *temp,*max;
      max = temp = *head;
      
      while( *head != (tail->next) )
	{
	  if(((*head)->power) > (max-> power))
	    {
	      max = *head;
	    }
	  //printf("11\n");
	  (*head) =(*head) -> next;
	}
      
      //printf("O\n");
      (*head) = tail;
      if( max == (*head) )                                           // If Max is at last
	{
	  *head = temp ;  
	  selectionSort(&*head,(tail->prev));
	  //printf("1\n");
	  printResult(*head);
	}
      
      else if( max == temp )                                        // If Max is at first
	{
	  (*head) -> next = max ;
	  max -> prev = (*head);
	  temp = temp -> next;
	  max -> next = NULL;
	  tail = max;
	  (*head) = temp ;
	  selectionSort(&*head,(tail->prev));
	  //printf("2\n");  
	  printResult(*head);
	} 
      
      else                                                           // If Max is in Between
	{
	  (max->prev)->next = (max -> next);
	  (max -> next) -> prev = max -> prev;
	  (*head)-> next = max;
	  max -> prev = (*head);
	  max -> next = NULL;
	  tail = max;
	  *head = temp ;  
	  selectionSort(&*head,(tail->prev));
	  //printf("3\n");
	  printResult(*head);
	}
      }
}
