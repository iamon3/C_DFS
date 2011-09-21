#include<stdio.h>

#define ROW 3  
#define COL 5

/////////////////////////////

void  rotateClockWise(int A[ROW][COL],int B[ROW][COL])
{
  int i,j,k = 0 ,l = 0 ,row = ROW-1,col=COL-1 , leftColLimit = 0 , upRowLimit = 0  ;
  int rightFlag = 1 ,downFlag = 0, leftFlag = 0,upFlag = 0;


  for(i= 0 ;i<ROW;i++)
    {
      for(j=0;j<COL;j++)
	{
	  if(rightFlag)
	    {
	      if(k<=col)
		{
		  B[l][k]= A[i][j] ; 
		  k++ ;
		}
	      else
		{
		  k = col ; col -= 1;
		  rightFlag = 0 ; downFlag = 1;
		}
	    }

	  if(downFlag)
	    {
	      if(l<=row)
		{
		  B[l][k]= A[i][j] ; 
		  l++ ;
		}
	      else
		{
		  l = row ; row -= 1;
		  leftFlag = 1 ; downFlag = 0;
		}
	    }

	  if(leftFlag)
	    {
	      if(k >= leftColLimit)
		{
		  B[l][k]= A[i][j] ; 
		  k-- ;
		}
	      else
		{
		  k = leftColLimit ; leftColLimit += 1;
		  leftFlag = 0 ; upFlag = 1;
		}
	    }

	  if(upFlag)
	    {
	      if(l >= upRowLimit)
		{
		  B[l][k]= A[i][j] ; 
		  l-- ;
		}
	      else
		{
		  l = upRowLimit ; upRowLimit += 1;
		  rightFlag = 1 ; upFlag = 0;
		}
	    }

	}
    }
}

/////////////////////////////

void printMat(int arr[ROW][COL])
{
  int i,j;
  for(i=0;i<ROW;i++)
    {
      for(j=0;j<COL;j++)
	{
	  printf("%d\t",arr[i][j]);
	}
      printf("\n");
    }
}
/////////////////////////////

int main()
{
  int B[ROW][COL];
  int A[ROW][COL]= {1,2,3,4,5,
		    6,7,8,9,10,
		    11,12,13,14,15};

  rotateClockWise(A,B);
  printMat(A);
  printf("After Rotation\n");
  printMat(B);

  return 0;
}

/////////////////////////////
