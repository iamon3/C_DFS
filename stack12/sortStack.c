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
	printf(" %d) %d \n",i,stack[i]);
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
	//stack_top = 0 ;
	push( elmentToBePut);
	printf("Element pushed :--  %d\n",elmentToBePut);
	return;
    }

    elm_poped = pop() ;
    printf("Element poped :--  %d\n",elm_poped);

    if( elmentToBePut >= elm_poped )
    {
	push( elm_poped );
	printf("Element pushed :--  %d\n",elm_poped);
	push( elmentToBePut );
	printf("Element pushed :--  %d\n",elmentToBePut);
	return ;
    }

    else
    {
	put_elment_in_sorted_stack( elmentToBePut );
	push( elm_poped );
	printf("Element pushed :--  %d\n",elm_poped);

	return ;
    }

}

/////////////////////////////////

void sortStack()
{
    int elm_poped ;

    if( stack_top == -1 )  // If stack is empty , then don do anything , simply return .
    {
	//stack_top = 0 ;
	return;
    }

    elm_poped = pop();

    sortStack();

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
//  --stack_top;
  print_stack( );
  
  sortStack();
  //stack_size += 1;
  //put_elment_in_sorted_stack( 15 );

  printf("\nAfter sorting Stack \n ");
  //printf("\nAfter puting 15 in sorted Stack \n ");
//  stack_top -= 1;

  print_stack( );

//  vacate_stack( );

  return 0;
}

////////////////////////////
