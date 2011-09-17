#include<stdio.h>
#include<string.h>

int main()
{
  char infixExpr[50];

  printf("\nEnter expression :");
  gets(infixExpr);

  printf("\nLength : %d\n",strlen(infixExpr));
  return 0;
}
