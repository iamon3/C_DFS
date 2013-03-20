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

/*
 * This function places the element located at low index to it's pivote position
 * and returns pivote position i.e. index in the array at which low index element is placed after executing pivote position logic.
 * e.g.
 * If arr = [2,1,6,5,4], then this function will place "2" at the 2nd position i.e. index 1 and will return the same.
 * So after execution of this function, arr may be reorganized as 
 * arr = [1,2,6,4,5]
 */
int partition1(int arr[],int low,int high){
	
	//Let's assume 1st element to be the pivote element
	int pivotePosition = low;
	int pivoteElm = arr[low];
	
	//So we have to find pivotePosition of the 1st element in the arr.
	int i = low + 1;
	
	// Find the position of the 1st element in the array as Pivote.
	while(i <= high){
		if(arr[i] < pivoteElm){
			pivotePosition += 1;
			swap(arr, i, pivotePosition);
		}
		i++;
	}
	
	// Finally we have found pivote position where the 1st element belongs to.
	// So place it to the proper found pivote position.
	swap(arr, low, pivotePosition);
	
	return pivotePosition;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void quickSort(int arr[],int low ,int high)
{
  int pivotepos;

  if(low < high)
    {
      pivotepos = partition1(arr,low,high);
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
