#include<stdio.h>

///////////////////////

int maxNum(int a, int b)
{
  return a + ( ((a-b)>>31) * (a-b) );
}

////////////////////////

int minNum(int a, int b)
{
  return a + ( ((b-a) >> 31) * (a-b) );
}

////////////////////////

int main()
{
  int a , b;

  printf("\nEnter Numbers a and b : ");
  scanf("%d%d",&a,&b);

  printf("\nMax = %d , Min = %d\n",maxNum(a,b),minNum(a,b));
  return 0;
}

////////////////////////
