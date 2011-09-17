#include<stdio.h>
int main()
{
  int num ,result;

  printf("\nEnter Number :- ");
  scanf("%d",&num);

  result = !(num & (num-1)) && num ;

  printf("\nIs Power Of Two :- %d\n",result);
  return 0;
}
