#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
  arr[i] = arr[i]^arr[j];
  arr[j] = arr[i]^arr[j];
  arr[i] = arr[i]^arr[j];
  return;
}

void print_array(int *arr,int len)
{
  int i;
  for(i=0; i<len; i++)
    {
      printf("%d\t", arr[i]);
    }
  return;
}

void heapify(int *arr,int len)
{
  int i, n, index;
  n=len/2;
  if( (len & 1) == 0)
    {
      n=n-1;
      if(arr[n] < arr[2*n+1])
	{
	  swap(arr, n, 2*n+1);
	}
    }
  n--;
  for(i=n; i>=0; i--)
    {
      if(arr[2*i+1] < arr[2*i+2])
	{
	  index = 2*i+2;
	}
      else
	{
	  index = 2*i+1;
	}
      if(arr[i] < arr[index])
	{
	  swap(arr, i, index);
	}
    }
  return;
}

void heap_sort(int *arr,int len)
{
  int i;
  for(i=len; i>1; i--)
    {
      heapify(arr,i);
      swap(arr,0, i-1);
    }
  return;
}

int main()
{
  int *arr, len, i;
  printf("\nEnter The Length Of Array:=> ");
  scanf("%d", &len);
  if(len <= 0)
    {
      printf("\nInvalid Length Of array\n\n");
      return 0;
    }
  arr = (int*)malloc(sizeof(int)*len);
  printf("\nEnter The Elements Of Array:=> ");
  for(i=0; i<len; i++)
    {
      scanf("%d", &arr[i]);
    }
  printf("\nYour Array Is:=> ");
  print_array(arr, len);
  printf("\n\n");
  printf("Your Sorted Array Is:=> ");
  heap_sort(arr,len);
  print_array(arr, len);
  printf("\n\n");
  return 0;
}
