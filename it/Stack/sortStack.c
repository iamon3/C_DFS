
////////////////////////////

/*
  This is recursive function of sorting stack
  without using extra memory , but system memory 
  can be used . Only push , pop operation allowed
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
  if( stack_top == stack_size-1 )
    {printf(" \nOoopppsssss ... Stack is full \n") ; return ; }
  else
    {stack[ ++ stack_top ] = elm_to_be_pushed ; return ;}
}

////////////////////////////

int pop()
{
  if( stack_top == -1 )
    {printf("\n...Heyyy .... How can you pop when stack is Empty ...U Duffer ...\n") ; return -1;}
  else
    return stack[stack_top--];
}

//////////////////////////////////

void print_stack( )
{
  int i ;
  for( i = 0 ; i <= stack_top ; i++ )
    {
      printf("%d) %d \n",i,stack[i]);
    }
  printf("\n");
}

//////////////////////////////////

void build_stack( )
{
  int elm_to_be_pushed ;
  while(stack_top < stack_size-1 )
    {
      printf("\nEnter element to be pushed : ");
      scanf("%d",&elm_to_be_pushed);
      push(elm_to_be_pushed);
    }
}

/////////////////////////////////

void put_elment_in_sorted_stack( int elmentToBePut )
{
    int elm_poped ;

    if( stack_top == -1 )  // If stack is empty , then push element in stack . Now this is sorted stack . Hence Return .
    {
	push( elmentToBePut);
	return;
    }

    elm_poped = pop() ;

    if( elmentToBePut >= elm_poped )
    {
	push( elm_poped );
	push( elmentToBePut );
	return ;
    }

    else
    {
	put_elment_in_sorted_stack( elmentToBePut );
	push( elm_poped );
	return ;
    }

}

/////////////////////////////////

void sortStack()
{
    int elm_poped ;

    if( stack_top == -1 )  // If stack is empty , then don do anything , simply return .
    {
	return;
    }

    elm_poped = pop();

    sortStack();     // This will give sorted stack , so only remaining part is to put poped element in sorted stack .

    put_elment_in_sorted_stack( elm_poped );

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
  
  sortStack();

  printf("\nAfter sorting Stack \n ");
  print_stack( );

  return 0;
}

////////////////////////////
