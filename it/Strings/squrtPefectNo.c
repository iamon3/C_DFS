#include<stdio.h>
/*Returns the square root of n. Note that the function
  will not work for numbers which are not perfect squares*/
unsigned int squareRoot(int n)
{
  int x = n;
  int y = 1;
  while(x > y)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}      
 
/* Driver program to test above function*/
int main()
{
  int n = 49;
  printf ("Square root of %d is %d", n, squareRoot(n));
  getchar();
}
