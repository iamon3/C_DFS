/////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

/////////////////////////////////////////////////////////////////////////////
/*
struct arrayBounds
{
  int low;
  int high;
};
*/
/////////////////////////////////////////////////////////////////////////////

void printArr(int arr[], int length)
{
  int i;
  for(i=0;i<length;i++)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
}

/////////////////////////////////////////////////////////////////////////////

void merge(int arr[],int low1,int low2,int high1,int high2)
{
  int dupLenth = (low1+high1+2);
  int arr2[dupLenth];
  int i,j;
  j=low1;

  for(i=0;i<dupLenth;i++,j++)
    {
      arr2[i]=arr[j];
    }

  i=0;

  while(low1<=high2)
    {
      /*
      if(i<=dupLenth)
	{
	  if(low2<=high2)
	    {
	      if(arr2[i]<arr[low2])
		{
		  arr[low1]=arr2[i];
		  i++;
		  low1++; 
		}  
	      else
		{
		  arr[low1]=arr[low2];
		  low2++;
		  low1++;
		}
	    }
	  else
	    {
	      arr[low1]=arr2[i];
	      i++;
	      low1++;
	    }
	}
      else
	{
	  arr[low1]=arr[low2];
	  low2++;
	  low1++;
	}
      */
      
      if( i<= dupLenth && low2 <= high2 && arr2[i]<arr[low2] )
	{
	  arr[low1]=arr2[i];
	  i++;
	  low1++;
	}

      else if(i>dupLenth)
	{
	  arr[low1]=arr[low2];
	  low2++;
	  low1++;
	}

      else if( low2> high2 )
	{
	  arr[low1]=arr2[i];
	  i++;
	  low1++;
	}

      else
	{
	  arr[low1]=arr[low2];
	  low2++;
	  low1++;

	}
      
    }
}

/////////////////////////////////////////////////////////////////////////////

void  mergeSort(int arr[],int low,int high)
{
  //struct arrayBounds arr1,arr2;
  int mid ;
  
  if(low<high)
    {
      /*
      arr1.low = low;
      arr1.high = mid;
      arr2.low = mid +1;
      arr2.high = high;
      */
      mid = (low+high)/2;
      mergeSort(arr,low,mid);
      mergeSort(arr,mid+1,high);  
      //      merge(arr,arr1.low,arr2.low,arr1.high,arr2.high);
       merge(arr,low,mid+1,mid,high);
    }
}

/////////////////////////////////////////////////////////////////////////////

int main()
{
  int length,i,arr[10];

  printf("\nEnter length of matrix :");
  scanf("%d",&length);

  printf("\nEnter elms in arr :\n");
  for(i=0;i<length;i++)
    {
      scanf("%d",&arr[i]);
    }

  printf("\nBefore Sorting :");
  printArr(arr,length);

  mergeSort(arr,0,length-1);

  printf("\nAfter Sorting :");
  printArr(arr,length);

  return 0;
}

/////////////////////////////////////////////////////////////////////////////
