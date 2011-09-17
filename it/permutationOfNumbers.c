#include<stdio.h>

////////////////////////////

void scanArr(int arr[], int* length)
{
  int i;
  printf("\nEnter length of Arr :- ");
  scanf("%d",length);
  printf("\nEnter Elements :- \n");
  for(i=0;i<(*length);i++)
    {
      scanf("%d",&arr[i]);
    }
}

////////////////////////////

void printArr(int arr[],int length)
{
  int i;
  for(i=0;i<length;i++)
    {
      printf("%d ",arr[i]);
    }
  printf("\n");
}

////////////////////////////

void rotateArr(int arr[],int fst,int last)
{
  int start,i;
  start = arr[fst];
  for(i=fst ;i < last ;i++)
    {
      arr[i] = arr[i+1];
    }
  arr[last]=start;
}

////////////////////////////

void permute(int arr[],int fst,int last,int length)
{
  if( fst==last )
    {
      printArr(arr,length);
      return;
    }
  else
    {
      int i;
      for( i=0 ; i<=(last-fst) ; i++)
	{
	  permute(arr,fst+1,last,length);
	  rotateArr(arr,fst,last);
	}
    }
}

////////////////////////////

int main()
{
  int arr[10],length;
  scanArr(arr,&length);
  /*  printArr(arr,length);*/
  permute(arr,0,length-1,length);
  return 0;
}

////////////////////////////
