/*Given an array of n numbers, find the maximum AND minimum values in the array 
  with the minimum number of comparisons. [hint - can be done in 1.5n]*/

////////////////////////////////////

#include<stdio.h>

////////////////////////////////////

void findMinMax(int * A, int n, int min, int max)
{
  max = min = A[0];
  
  int i = 0;
  
  /*Start at 1 if n is odd. This allows us to avoid extra checks about falling off the end*/
  i = n & 1;
  
  for(; i < n; i+=2)
    {
      if (A[i] > A[i+1])
	{
	  if (A[i] > max)
	    {max = A[i];}
	  if (A[i+1] < min)
	    {min = A[i+1];}
}
      else
	{
	  if (A[i+1] > max)
	    {max = A[i+1];}
	  if (A[i] < min)
	    {min = A[i];}
	}
    }
  printf("Min = %d \t Max = %d \n",min,max);
}

////////////////////////////////////

void scanArr(int arr[],int *len)
{
  int i;
  printf("Enter length of arr :- \n");
  scanf("%d",len);
  printf("Enter elments . \n");
  for(i=0;i<(*len);i++)
    {
      scanf("%d",&arr[i]);
    }
}

////////////////////////////////////

int main()
{
  int arr[10],len=0 ,min=0 , max=0 ;
  scanArr(arr,&len);
  findMinMax(arr,len,min,max);
  return 0;
}

////////////////////////////////////
