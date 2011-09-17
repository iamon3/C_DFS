
# include<stdio.h>

int main()
{
  int i,length,mid, elementToBeSearched, start,end, arr[25];
  
  printf("\nEnter Length Of Arr : ");
  scanf("%d",&length);

  printf("\nEnter elements in sorted order :- \n");
  for(i=0;i<length;i++)
    {
      scanf("%d",&arr[i]);
    }

  start =0;
  end = length -1;
  mid = ( start + end )/2;
  
  printf("\nEnter element you want to search : ");
  scanf("%d",&elementToBeSearched);

  while( start <= end )
    {
      if( arr[mid] > elementToBeSearched )
	{
	  end = mid-1;
	  mid = ( start + end )/2;
	}
      else if( arr[mid] < elementToBeSearched )
	{
	  start = mid+1;
	  mid = ( start + end )/2;
	}

      else 
	{
	  printf("Element Found At %d index \n",mid);
	  return 1;
	}
    }

  printf("\n Element not found \n");
  return 0;
}
