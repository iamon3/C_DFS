#include<stdio.h>

////////////////////////////

int stack_top = 0 ;
int stack_size;
int stack[50];

////////////////////////////


int push(int elm_to_be_pushed )
{
  if( stack_top == stack_size )
    {printf(" \nOoopppsssss ... Stack is full \n") ; return -1;}
  else
    {stack[stack_top ++ ] = elm_to_be_pushed ;return 1 ;}
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
  for( i = 0 ; i < stack_top ; i++ )
    {
      printf("%d ",stack[i]);
    }
  printf("\n");
}

//////////////////////////////////

void vacate_stack( int stack[] )
{
  int poped_elm ;
  printf("Popping starts now \n ");
  while( ( poped_elm = pop(stack) ) != -1 )
    {
      printf("%d ",poped_elm);
    }
  printf("\n");
}

/////////////////////////////////

void build_stack( int stack_size ,int stack[] )
{
  int elm_to_be_pushed , flag = 1;
  while(flag != -1 )
    {
      printf("\nEnter element to be pushed : ");
      scanf("%d",&elm_to_be_pushed);
      flag = push(elm_to_be_pushed);
    }
}

/////////////////////////////////

int main()
{
  printf("\nEnter size of stack : ");
  scanf("%d",&stack_size);
  
  build_stack( stack_size , stack );
  print_stack( stack );
  vacate_stack( stack );

  return 0;
}

////////////////////////////
