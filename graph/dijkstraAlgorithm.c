#include<stdio.h>
#define INF 9999

int main()
{
  int arr[50][50];
  int cost[50][50];
  int row,col,i,j,k;

  printf("\nEnter No.of rows and clos :");
  scanf("%d%d",&row,&col);

  printf("Enter COSTS :-\n");

  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  scanf("%d",&cost[i][j]);
	}
    }

  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  if(cost[i][j]==0)
	    {
	      arr[i][j]=INF;
	    }
	  else
	    {
	      arr[i][j]=cost[i][j];
	    }
	}
    }  

  printf("Adjencency matrix of cost of edges :\n");
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%d\t",arr[i][j]);
	}
      printf("\n");
    }


  for(k=0;k<row;k++)
    {
      for(j=0;j<col;j++)
	{
	  for(i=0;i<row;i++)
	    {
	      if(arr[i][j] > arr[i][k]+arr[k][j])
		{
		  arr[i][j] = arr[i][k]+arr[k][j];
		}
	    }
	}
    }

  printf("\n Adjencncy matrix of lowest cost between the vertices :\n");
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%d\t",arr[i][j]);
	}
      printf("\n");
    }
  return 0;
}
