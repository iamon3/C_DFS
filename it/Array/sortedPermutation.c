#include<stdio.h>
////////////////////////////
/*
  Basic idea is , first input should be in sorted order.
  So sorting will be one time activity. (nlogn).
  After that recursive procedure will do the job for us
  sortedPermute( n ) = fstElm + sortedPermute(n-1)
  now sortedPermute(n-1) ie sub array starting from index startIndex+1
  will give reverse sorted sub-array.
  eg  1,2,3,4
  1 + sortedPermute(2,3,4)
  here 2nd part will produce 4,3,2...... why ? think.... Its simple
  So now task is to swap 1 with exact no which will be next no in ascending sorted array.
  so it will be 2.... so swap 1 with 2
  and now array is 2 , 4 , 3, 1
  So now again we will have to sort sub-array. to proceed. But if u c structure of sub-array
  Its not actually required. All we need is swap palindrome position elements.
  Thus swap 4 and 1
  So now array is 2 ,1 , 3, 4
  Thus sub-array is sorted in ascending order.
*/ 

////////////////////////////
void printArr(int arr[],int lastElmIndex)
{
    static int cnt = 0;
  int i;
  for(i=0;i<=lastElmIndex;i++)
    {
      printf("%d ",arr[i]);
    }
  printf("    count = %d",++cnt);
  printf("\n");
}

/////////////////////////////////////////////

void swap(int arr[], int fst, int snd){
  int temp;
  temp = arr[fst];
  arr[fst]=arr[snd];
  arr[snd]=temp;
}

void palindromSwap(int arr[],int startIndex,int lastIndex){
  while(startIndex < lastIndex){
    swap(arr, startIndex, lastIndex);
    startIndex += 1;
    lastIndex -= 1;
  }
}

void sortedPermute(int arr[],int startIndex,int lastElmIndex)
{
  if( startIndex == lastElmIndex)
    {
      printArr(arr,lastElmIndex);
      return;
    }
  else
    {
      int permutNo;
      for( permutNo=1 ; permutNo<=(lastElmIndex-startIndex + 1) ; permutNo++)
	{
          sortedPermute(arr, startIndex+1, lastElmIndex);
	  if(startIndex < lastElmIndex-permutNo+1){
            swap(arr, startIndex, lastElmIndex-permutNo+1);
            palindromSwap(arr, startIndex+1, lastElmIndex);
	  }
	}
    }
}

////////////////////////////

int main()
{
  int arr2[] = {1,2,3,4,5};
  sortedPermute(arr2, 0, 4);
  return 0;
}

////////////////////////////
