/* First tell ans after that see what will be output */

#include<stdio.h>

int main()
{
  int i=5;
  printf("\n%d\t%d\t%d\t%d\n",i++,--i,i++,--i);
  i=5;
  printf("\n%d\t%d\t%d\t%d\n",i++,i--,i++,i--);
  return 0;
}
