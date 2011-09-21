
/*
  This function returns max of two elements
  without comparision . It can also bbe used 
  for finding minimum elements with some modifications .
*/

//////////////////////////////////// 

#include<stdio.h>

/////////////////////////////

int max_elm(int a,int b)
{
  return a + (((a-b) >> 31 )*(a-b));
}

/////////////////////////////

int main()
{
  int a,b,max;

  printf("\nEnter elements :- ");
  scanf("%d%d",&a,&b);
  printf("\nU entered  a =%d b=%d\n",a,b);

  max = max_elm(a,b);

  printf("Maximum element is :- %d\n",max);
  return 0;
}
/////////////////////////////
