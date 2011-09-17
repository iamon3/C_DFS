/* 
   Given In Order and Pre Order traversal of tree , 
   This programme creats Binary Tree .
   This programme works only in case of Complete Binary Tree . 
   Need some more conditions handling to make it general .
   This function also successfully deletes node from BST , 
   Look carefully and understand how pointers are effectively used
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
treeNode **  searchNode( treeNode** root , int data);
treeNode **  findInfixSuccessor(treeNode ** nodeToBeDeleted);
void        deleteAndUpdateBst( treeNode** nodeToBeDeleted ,treeNode** nodeToBeReplacedWith);
treeNode *  toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre );
treeNode * deleteFromBst(treeNode** root,int data);

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


void treeTraversal(treeNode* root )
{
  printf("\nPrefix Notation\n");
  prefix(root);
  printf("\nInfix Notation\n");
  infix(root);
  printf("\nPostfix Notation\n");
  postfix(root);
  printf("\n");
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

//////////////////////////////////////////////////

treeNode ** searchNode(treeNode **root , int data)
{
  treeNode **temp ;
  temp = ( root ) ;
  while( *temp  )
    {
      if( ((*temp) -> data) > data )
	{
	  temp =  &((*temp) -> lTree);
	}
      else if( ( (*temp) -> data) < data)
	{
	  temp = &( (*temp) -> rTree );
	}
      else 
	return temp;
    }
  printf("Node  to be deleted not present \n");
  return NULL;
}


treeNode** findInfixSuccessor(treeNode** nodeToBeDeleted)
{
  treeNode ** infixSucc;
  infixSucc = &((*nodeToBeDeleted) -> rTree) ;
  while( (*infixSucc) -> lTree )
    {
      infixSucc = &((*infixSucc) -> lTree );
    }
  return infixSucc ;
}


void  deleteAndUpdateBst( treeNode** nodeToBeDeleted ,treeNode** nodeToBeReplacedWith)
{
  treeNode *temp1 , *temp2 ;
  temp1 = *nodeToBeDeleted , temp2 = *nodeToBeReplacedWith ;

  (*nodeToBeReplacedWith) = (*nodeToBeReplacedWith )-> rTree ;

  temp2 -> lTree = (*nodeToBeDeleted) -> lTree ;
  temp2 -> rTree = (*nodeToBeDeleted) -> rTree ;
  ( *nodeToBeDeleted )  = temp2 ;

  free( temp1 );
}


treeNode * deleteFromBst(treeNode** root,int data)
{
  treeNode **nodeToBeDeleted = NULL , **nodeToBeReplacedWith = NULL ;

  nodeToBeDeleted =  searchNode( root , data );
  nodeToBeReplacedWith = findInfixSuccessor(nodeToBeDeleted);
  deleteAndUpdateBst(nodeToBeDeleted , nodeToBeReplacedWith);

  return *root ;
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
  int totalNodesInTree, inFixArr[15],preFixArr[15],nodeToBeDeleted;
  treeNode *root = NULL;
  
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
  printf("\n\nafter creating tree :- \n");
  treeTraversal( root );
  
  printf("\n\nEnter node to be deleted :- ");
  scanf("%d",&nodeToBeDeleted);
  root = deleteFromBst( &root , nodeToBeDeleted );
  
  printf("\n\nafter deletion on tree :- \n");
  treeTraversal( root );

  return 0;
}

///////////////////////////////////////////////
