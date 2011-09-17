#include<stdio.h>

////////////////////////////

void scanArr(int arr[],int arr1[], int* length,int *combinationOf)
{
  int i;
  printf("\nEnter length of Arr :- ");
  scanf("%d",length);

  printf("\nEnter Elements :- \n");

  for(i=0;i<(*length);i++)
    {
      scanf("%d",&arr[i]);
    }
  printf("\nEnter combination of lenght : ");
  scanf("%d",combinationOf);
}

////////////////////////////

void printCombination( int arr1[], int  arr1Last )
{
  int i;

  for( i=0 ; i<= arr1Last ; i++ )
    {
      printf("%d ",arr1[i]);
    }
  printf("\n");
}

////////////////////////////

void combination(int arr[], int arrFst, int arrLast, int arr1[], int arr1Curr,int arr1Last, int combinationOf)
{
  int i;

  for( i = arrFst; i <= (arrLast - combinationOf + 1 ) ; i++ )
    {
      
      arr1[arr1Curr] = arr[i] ;

      if(combinationOf == 1 )
	{
	  printCombination( arr1, arr1Last );
	}

      else
	{
	  combination( arr, i+1, arrLast, arr1, arr1Curr+1, arr1Last, combinationOf-1  );
	}
    }
}

////////////////////////////

int main()
{
  int arr[20], arr1[10], arr1Curr =0 , length, combinationOf;

  scanArr(arr,arr1,&length,&combinationOf);

  printf("Possible Combinations :--- \n");

  combination( arr, 0, length-1, arr1, arr1Curr, combinationOf-1, combinationOf );

  return 0;
}

////////////////////////////
