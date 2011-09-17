/* Just c how char pointer can point to float by type cast */

#include<stdio.h>
int main()
{
  char *ptr ;
  float arr[]={1.0,2.6,3.2};

  ptr = (char *)arr;
  printf("\n%f\n",*(ptr+1));

  return 0;
}
