/////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<ctype.h>

# define MAX 50

/////////////////////////////////////////////////////////////////////////

int stacktop;

int priority(char operator)
{
  if(operator == '+' || operator== '-' )
    {
      return 1;
    }
  else if(operator == '*' || operator== '/'|| operator== '$')
    {
      return 2;
    }
  else 
    {
      return 0;
    }
}

/////////////////////////////////////////////////////////////////////////

void push(char stack[],char operator)
{
  if(stacktop == MAX)
    {
      printf("Stack is full \n");
    }
  else
    {
      stack[stacktop++]=operator;
    }
  return;
}


char pop(char stack[])
{
  if( stacktop <= -1 )
    {
      //      printf("Stack is empty :");
      return '0';
    }
  else
    {
      printf("stacktop=%d\n",stacktop);
      return stack[stacktop--];
    }
}

/////////////////////////////////////////////////////////////////////////

void convert(char infixExpr[])
{
  int i=0,j=0;
  int len=strlen(infixExpr);
  char c,popedElm,stack[MAX],postfix[50];

  //  while((c=infixExpr[i]) != '\0')
  while(i <= len)
    {
      c=infixExpr[i];
      //      printf("%c",stack[stacktop]);
      if(c==' ' || c=='\t')
	{
	  i++;
	  continue;
	}
      
      else if(c=='(')
	{
	  push(stack,c);
	  //stacktop++;
	}
      
      else if(c==')')
	{
	  popedElm = pop(stack);
	  
	  while(popedElm != '(')
	    {
	      printf("%c",popedElm);
	      postfix[j++]=popedElm;
	      popedElm = pop(stack);
	      //  stacktop--;
            }
        }

      else if(isdigit(c) || isalpha(c))
	{
	  postfix[j++] = c;
	}
      
      /* If it is operator */
      else
	{
	  popedElm =pop(stack);
	  
	  while( priority(popedElm) >= priority(c) || popedElm != '(' )
	    {
	      postfix[j++]=popedElm;
	      popedElm = pop(stack);
	      //  stacktop--;
            }

	  push(stack,popedElm);
	  //stacktop++;
	  push(stack,c);
	  //stacktop++;
	}
      printf("i=%d",i);
      i++;

    }
  
  postfix[j]='\0';
  printf("\nPostfix Conversion is :%s\n",postfix);

}


////////////////////////////////////////////////////////////////////////////

int main()
{
  char infixExpr[50];

  printf("\nEnter expression :");
  gets(infixExpr);

  printf("\nLength : %d\n",strlen(infixExpr));
  convert(infixExpr);
  return 0;
}

///////////////////////////////////////////////////////////////////////////
