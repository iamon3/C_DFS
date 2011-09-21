/*.Write a function that counts the number of binary ones in a four byte number. 
  Your solution should require only one iteration for each one in the number.*/

#include<stdio.h>

int count(int I)
{
  int tot = 0;
  while (I) {tot++; I &= (I-1);}
  return tot;
}

int main()
{
  int number ;

  printf("\nEnter number :");
  scanf("%d",&number);
  printf("\nAns = %d\n",count(number));
  return 0;
}
