
////////////////////////////
/*
  This function reverses stack 
  without using extra memory .
  But system memory i.e. system stack
  can be used . Only push , pop operations allowed
*/
////////////////////////////

#include<stdio.h>

////////////////////////////

int stack_top = -1 ;
int stack_size;
int stack[50];

////////////////////////////


void push(int elm_to_be_pushed )
{
  if( stack_top == stack_size - 1)
    {printf(" \nOoopppsssss ... Stack is full \n") ; return ; }
  else
    {stack[ ++stack_top ] = elm_to_be_pushed ; return ;}
}

////////////////////////////

int pop()
{
  if( stack_top == -1 )
    {printf("\n...Heyyy .... How can you pop when stack is Empty ...U Duffer ...\n") ; return -1;}
  else
    return stack[ stack_top --];
}

//////////////////////////////////

void print_stack( )
{
  int i ;
  for( i = 0 ; i <= stack_top ; i++ )
    {
      printf("%d ",stack[i]);
    }
  printf("\n");
}

//////////////////////////////////

void build_stack( )
{
  int elm_to_be_pushed ;

  while(stack_top != stack_size - 1 )
    {
      printf("\nEnter element to be pushed : ");
      scanf("%d",&elm_to_be_pushed);
      push(elm_to_be_pushed);
    }
}

/////////////////////////////////

void put_elment_at_top(int x)
{
    int y;

    if( stack_top == -1 )
    {
	push( x );
	return ;
    }
    
    y = pop();

    put_elment_at_top(x);
    push( y );

    return ;
}

/////////////////////////////////

void reverse_stack( )
{
  int x;

  if( stack_top == -1 )
  {
      return ;
  }
  
  x = pop();
  
  reverse_stack();     

  put_elment_at_top(x);

  return ;
}

/////////////////////////////////

int main()
{
  printf("\nEnter size of stack : ");
  scanf("%d",&stack_size);
  
  build_stack( );
  
  printf("After Stack created \n ");
  print_stack( );
  
  reverse_stack( );
 
  printf("\nAfter reversing Stack \n ");
  print_stack( );

  return 0;
}

////////////////////////////
