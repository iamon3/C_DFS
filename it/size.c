#include<stdio.h>
int main()
{
  int x;
  printf("int = %d , float = %d , char = %d\n",sizeof(int),sizeof(float),sizeof(char));
  *((char *)(&x)) = 5;
  *((char *)(&x)+1) = 10;
  printf("x1=%d, x2=%d\xn",*((char *)(&x)),*((char *)(&x)+1));
  printf("x =%d \n",*((char *)(&x)));
  return 0;
}
