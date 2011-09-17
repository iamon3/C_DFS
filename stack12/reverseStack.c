
////////////////////////////

#include<stdio.h>

////////////////////////////

int stack_top = 0 ;
int stack_size;
int stack[50];

////////////////////////////


void push(int elm_to_be_pushed )
{
  if( stack_top == stack_size )
    {printf(" \nOoopppsssss ... Stack is full \n") ; return ; }
  else
    {stack[stack_top ++ ] = elm_to_be_pushed ; return ;}
}

////////////////////////////

int pop()
{
  if( stack_top == -1 )
    {printf("\n...Heyyy .... How can you pop when stack is Empty ...U Duffer ...\n") ; return -1;}
  else
    return stack[stack_top --];
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

void vacate_stack( )
{
  int poped_elm ;
  printf("Popping starts now \n ");
  while( ( poped_elm = pop() ) != -1 )
    {
      printf("%d ",poped_elm);
    }
  printf("\n");
}

/////////////////////////////////

void build_stack( )
{
  int elm_to_be_pushed ;
  while(stack_top != stack_size )
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

    if( stack_top < 0 )
    {
	printf("\nStack bcame empty\n");
	stack_top = 0 ;
	push( x );
	return ;
    }
    
    y = pop();
    printf("\nput_elment_at_top --- poped -->  %d",y);
    put_elment_at_top(x);
    push( y );
    printf("\nput_elment_at_top --- pushed -->  %d",y);
    return ;
}

void reverse_stack( )
{
  int x;

  if( stack_top < 0 )
  {
//      stack_top = 0 ;
      return ;
  }
      x = pop();
      printf("\nreverse stack --- poped -->  %d",x);
      reverse_stack();     

  printf("\n-----------------------reverse stack --- putting ------------->  %d\n",x);
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
  --stack_top;
  print_stack( );
  
  reverse_stack( );
 
  printf("\nAfter reversing Stack \n ");
  print_stack( );

//  vacate_stack( );

  return 0;
}

////////////////////////////
