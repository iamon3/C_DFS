
/////////////////////////////////////////////////

#include<stdio.h>

/////////////////////////////////////////////////

void printArray(int arr[] , int noOfElements)
{
  int i;

  for(i=0;i<= noOfElements ;i++)
    {
      printf("%d\t",arr[i]);
    }
}

/////////////////////////////////////////////////

void swap(int arr[], int a, int b )
{
  int temp;
  temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp ;
}

void  selectionSort(int arr[],int fst,int snd, int last ,int noOfElements)
{
  printf("\n");
  printArray(arr , noOfElements);

  if( last == 0)
    { return ;}

  if(snd>last)
    {
      swap(arr,fst,last);
      fst = 0 ; snd = 1 ; last -= 1;
      //selectionSort(arr ,0 ,1 ,last -1 ,noOfElements);
    }

  if( arr[fst] > arr[snd] )
    {
      selectionSort(arr,fst,snd+1,last,noOfElements);
    }
  else { selectionSort(arr ,snd ,snd +1 ,last,noOfElements); }
    
}

/////////////////////////////////////////////////
/*
for(i=0;i<n;i++)
{ flag=0;
   for(j=0;j<n;j++)
    {	if(a[j]>a[flag])
	    flag=j;
    }
     swap(a[flag],a[n-1]);
     n=n-1;
}
*/

int main()
{
  int arr[50],lengthOfArr ,i;

  printf("\nEnter length of arr :-");
  scanf("%d",&lengthOfArr);

  printf("\nEnter elements of array :");
  for(i=0;i<lengthOfArr;i++)
    {
      scanf("%d",&arr[i]);
    }

  selectionSort(arr,0,1,lengthOfArr-1 ,lengthOfArr-1);
  printf("\nAfter selection sort :-\n");
  printArray(arr , lengthOfArr-1);
  
  return 0;
}

/////////////////////////////////////////////////
