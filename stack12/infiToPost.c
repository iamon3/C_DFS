#include<stdio.h>
#include<string.h>
//#include<conio.h>
#include<ctype.h>

#define MAX 50 

/////////////////////////////////////////////////////////////////////////////////////////////////

struct infix
{
  int top ;
  char target[MAX];
  char stack[MAX];
  char *s;
  char *t;
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/* POPS OPERATOR FROM  THE STACK */

char pop(struct infix *p)
{
  if(( p->top) == -1 )
    {
      printf("\nStack is empty\n");
      return -1;
    }
  else
    {
      char item = p -> stack[p->top];
      p -> top --;
      return item;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*ADDS OPERATOR TO THE STACK */

void push(struct infix *p,char c)
{
  if (p -> top == MAX )
    {
      printf("\nStack is full\n");
    }    
  
  else
    {
      p -> top ++;
      p-> stack [p->top] = c;
    }
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int priority(char c)
{
  if(c=='$')
    {
      return 3;
    }
  if(c=='*' || c==' ' || c=='/' || c=='%')
    {
      return 2;
    }
  else
    {
      if(c=='+'||c=='-')
	{
	  return 1;
	}
      else
	{
	  return 0;
	}
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////

/*CONVERT THE GIVEN EXPRESSION FROM INFIX TO POSTFIX FORM */

void convert(struct infix* p)
{
  char opr;

  while(*(p -> s))
    {
      if(*(p -> s)==' ' || *(p -> s)=='\t')
	{
	  p -> s++;
	  continue;
	}

      if(isdigit(*(p -> s)) || isalpha(*(p -> s)))
	{
	  while( isdigit (*(p->s)) || isalpha(*(p -> s)))
	    {
	      *(p -> t)=*(p -> s);
	      p -> s++;
	      p->t++;
	    }
	}
      if(*(p -> s) == '(')
	{
	  push(p,*(p -> s));
	  p -> s++;
	}
      if(*(p -> s)=='*' || *(p -> s)=='+' || *(p -> s)=='/' || *(p -> s)=='%' || *(p -> s)=='-' || *(p -> s)=='$')
	{
	  if(p -> top != 1)
	    {
	      opr = pop(p);

	      while(priority(opr) >= priority(*(p -> s)))
		{
		  *(p -> t)= opr;
		  p->t++;
		  opr = pop(p);
		}
	      push(p,opr);
	      push(p,*(p -> s));
	      
	    }
	  else 
	    {
	      push(p,*(p -> s)); 
	    }
	  p -> s++;
	}
      if(*(p -> s)==')')
	{
	  opr= pop(p);
	  while((opr) !='(')
	    {
	      *(p -> t)=opr;
	      p->t++;
	      opr = pop(p);
	    }
	  p->s++;
	}
    }
  while(p->top != -1)
    {
      char opr = pop(p);
      *(p -> t)=opr;
      p->t++;
    }
  *(p ->t)='\0';

}
/////////////////////////////////////////////////////////////////////////////////////////////////

void setexpr(struct infix *p,char *str)
{
  p -> s = str;
}
/////////////////////////////////////////////////////////////////////////////////////////////////

void infix(struct infix *p)
{
  p -> top = -1 ;
  strcpy(p->target,"");
  strcpy(p->stack,"");
  p->t = p -> target ;
  p->s =" ";
}
/////////////////////////////////////////////////////////////////////////////////////////////////

void show(struct infix p)
{
  printf("%s\n",p.target);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  struct infix p;
  char expr[MAX];

  infix(&p);

  printf("\nEnter expression in infix form :");
  gets(expr);

  setexpr(&p,expr);
  convert(&p);

  printf("\nThe Postfix expression is :");
  show(p);
  //  printf("\n");
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
