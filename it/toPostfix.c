/* 
   Given In Order and Pre Order traversal of tree , 
   This programme prints Post Order traversal of Tree .
   This programme works only in case of Complete Binary Tree . 
   Need some more conditions handling to make it general .
*/


///////////////////////////////////////////////

#include<stdio.h>

///////////////////////////////////////////////

void findRootIn_InfixArr(int in[],int pre[],int fstIn ,int lstIn ,int fstPre);
void toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre );

///////////////////////////////////////////////

void findRootIn_InfixArr(int in[],int pre[],int fstIn ,int lstIn ,int fstPre)
{
  int i;
  for( i=fstIn ; i<=lstIn ;i++ )
    {
      if( pre[fstPre] == in[i] )
	{
	  toPostFix(in ,pre ,fstIn ,i-1 ,fstPre+1);
	  toPostFix(in ,pre ,i+1 ,lstIn ,i+1);
	  // toPostFix(in ,pre ,i+1 ,lstIn ,fstPre+1);
	  printf("%d\t",in[i]);
	  return;
	}
    }
}

///////////////////////////////////////////////

/*
  fstIn , lstIn , fstPre are indices in array in=inFix & pre=preFix respectively 
*/

void toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre )
{
  /* if ( fstIn < 0 ) */
/*     { return ;} */
  /*   else */ 
  if(fstIn < lstIn)
    { findRootIn_InfixArr( in, pre, fstIn , lstIn , fstPre );}
  else
    { printf("%d\t",in[lstIn]); return;}
}

///////////////////////////////////////////////

void printArr(int arr[],int lengthOfArr)
{
  int i;
  for(i=0;i<lengthOfArr;i++)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
}


void scanArr(int arr[],int lengthOfArr)
{
  int i;
  for(i=0;i<lengthOfArr;i++)
    {
      scanf("%d",&arr[i]);
    }
  printf("\n");
}

///////////////////////////////////////////////

int main()
{
  int totalNodesInTree, inFixArr[15],preFixArr[15];

  printf("\nEnter length of arr : ");
  scanf("%d",&totalNodesInTree);


  printf("\nEnter values of nodes in preorder\n");
  scanArr(preFixArr,totalNodesInTree);
  printArr(preFixArr,totalNodesInTree);


  printf("\nEnter values of nodes in inorder\n");
  scanArr(inFixArr,totalNodesInTree);
  printArr(inFixArr,totalNodesInTree);


  printf("\n\nPost Fix Order as shown :\n");
  toPostFix(inFixArr,preFixArr,0,totalNodesInTree-1,0);
  printf("\n");

  return 0;
}

///////////////////////////////////////////////
