#include<stdio.h>
#include<math.h>
int main()
{
  int number;
  int mask,mask2;
  unsigned int abs;

  printf("\nEnter No :- ");
  scanf("%d",&number);

  mask = (-1 >> 31) ^ ( 1 << 31 );
  mask2 = ~(1<<31);
  abs = (unsigned int)number & mask ;

  printf("\nMAsk = %d , Mask2 = %d , Sum = %ld\n",mask,mask2,(long int)(pow(2,31)-1));
  printf("\nAbsolute Value = %d\n",abs);

  return 0;
}
