/*
  This Programme takes Binary Tree and number and 
  Prints root to node path such that sum of all the data 
  in that path is equal to given number
*/

///////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////

struct treeNode
{
    int data;
    struct treeNode *lTree;
    struct treeNode *rTree;
};

typedef struct treeNode treeNode;

///////////////////////////////////////////////

treeNode *  findRootIn_InfixArr(int in[],int pre[],int fstIn ,int lstIn ,int fstPre);
treeNode *  toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre );


char pathTravelled[50];
int stackTop = 0 ;

///////////////////////////////////////////////

void prefix(treeNode *root)
{
    if(root)
    {
	printf("%d\t",root -> data);
	prefix(root->lTree);
	prefix(root ->rTree);
    }
}

void infix(treeNode *root)
{
    if(root)
    {
	infix(root->lTree);
	printf("%d\t",root -> data);
	infix(root ->rTree);
    }
}

void postfix(treeNode *root)
{
    if(root)
    {
	postfix(root->lTree);
	postfix(root ->rTree);
	printf("%d\t",root -> data);
    }
}


///////////////////////////////////////////////

treeNode * findRootIn_InfixArr(int in[],int pre[],int fstIn ,int lstIn ,int fstPre)
{
    int i;
    treeNode *root=NULL;
    
    for( i=fstIn ; i<=lstIn ;i++ )
    {
	if( pre[fstPre] == in[i] )
	{
	    root = (struct treeNode *)malloc(sizeof(struct treeNode));	    
	    root -> lTree = toPostFix(in ,pre ,fstIn ,i-1 ,fstPre+1);
	    root -> rTree = toPostFix(in ,pre ,i+1 ,lstIn ,i+1);
	    printf("%d\t",in[i]);
	    root -> data = in[i];//creatNode(in[i]);
	    return root;
	}
    }
    return root;
}

///////////////////////////////////////////////

/*
  fstIn , lstIn , fstPre are indices in array in=inFix & pre=preFix respectively 
*/

treeNode * toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre )
{
    /* if ( fstIn < 0 ) 
       { return ;} 
       else */ 
    
    treeNode *root = NULL;
    
    if(fstIn < lstIn)
    { root =findRootIn_InfixArr( in, pre, fstIn , lstIn , fstPre ); return root;}
    else
    { 
	printf("%d\t",in[lstIn]);
	root = (struct treeNode *)malloc(sizeof(struct treeNode)); 
	root -> lTree = NULL;
	root -> rTree = NULL;
	root -> data = in[lstIn];
	return root;
    }
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

void push(char element)
{
  pathTravelled[stackTop] = element ;
  stackTop += 1;
}


void pop ( void )
{
  if( stackTop < 0 )
    {
      printf("\nstack is mpty \n");
      return ;
    }
  stackTop -= 1;
  pathTravelled[stackTop] = '\0';
}


int isTherePath( treeNode *root , int sum , int sumTillNow)
{
  int left=0 , right=0 ;

  if(!root)
    { return 0;}
 
  if( ( sumTillNow + root -> data ) == sum)
    {
      return 1;
    }

  if(  root -> lTree )
    {
      push('L');
      left = isTherePath( root -> lTree , sum , sumTillNow + root -> data );
      if(left)
	{return 1;}
    }

  if(  root -> rTree )
    {
      push('R');
      right = isTherePath( root -> rTree , sum , sumTillNow + root -> data );
      if (right)
	{return 1;}
    }

  pop();
  return 0;
}

void printPath( void )
{
  int i=0;
  printf("root -> ");
  for(i=0 ; i< stackTop ; i++)
    {
      printf("%c -> ",pathTravelled[i]);
    }
  printf("Path Complete \n");
}

/////////////////////////////////////////////////////////////

int main()
{
  int totalNodesInTree , inFixArr[20] , preFixArr[20] ;
  treeNode *root = NULL;
  int sum;
  
  printf("\nEnter length of arr : ");
  scanf("%d",&totalNodesInTree);


  printf("\nEnter values of nodes in preorder\n");
  scanArr(preFixArr,totalNodesInTree);
  printArr(preFixArr,totalNodesInTree);


  printf("\nEnter values of nodes in inorder\n");
  scanArr(inFixArr,totalNodesInTree);
  printArr(inFixArr,totalNodesInTree);


  printf("\n\nPost Fix Order as shown :\n");
  root = toPostFix(inFixArr,preFixArr,0,totalNodesInTree-1,0);
  printf("\n");
  printf("after creating tree :- \n");
  printf("\nPrefix Notation\n");
  prefix(root);
  printf("\nInfix Notation\n");
  infix(root);
  printf("\nPostfix Notation\n");
  postfix(root);
  printf("\n");

 
  printf("\nEnter Sum of Path To Be Searched :- ");
  scanf("%d",&sum);

  if( isTherePath(root , sum , 0) )
    {
      printPath();
      //      printf("root -> %s\n",pathTravelled);
    }
  else
    {
      printf("Path Not Found\n");
    }

  return 0;
}

//////////////////////////////////////////////////////////
