////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

int length;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void swap(int arr[],int i,int j)
{
  printf("Hi3\n");
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int partition(int arr[],int low,int high)

{
  int pivote,i,j,pivotepos, lastSmallElement;
  pivotepos = low;
  low += 1;

  while(1)
    {
      for(i=low;i<high;i++)
	{
	  if(arr[i] >= arr[pivotepos])
	    {
	      lastSmallElement = i-1;
	
	      break;
	    }
	}
      low = i;
      for( j = high;j > low;j-- )
	{
	  if( arr[j] < arr[pivotepos] )
	    {
	      
	      break ;
	    }
	}
      high = j;
      printf("%d\n",low);
      swap(arr,low,high);
      if(low>=high)
	{
	  break;
	}
    }

  //  swap(arr,pivotepos,lastSmallElement);
  swap(arr,pivotepos,high-1);
  printf("Hi2\n");
  return lastSmallElement;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void quickSort(int arr[],int low ,int high)
{
  int pivotepos;

  if(low < high)
    {
      printf("Hi1\n");
      pivotepos = partition(arr,low,high);
      quickSort(arr,low,pivotepos-1);
      quickSort(arr,pivotepos+1,high);
    }
  return ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printArr(int arr[])
{
  int i;
  printf("Elemetns you entered are \n");

  for(i=0;i<length;i++)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  int arr[25],i,value;

  printf("\nEnter length of array : ");
  scanf("%d",&length);

  printf("\nEntre elemnets :- \n");

  for(i=0;i<length;i++)
    {
      scanf("%d",&arr[i]);
    }

  printArr(arr);
  swap(arr,2,5);
  //  value = partition(arr,0,length-1);
  quickSort(arr,0,length-1);
  printArr(arr);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
