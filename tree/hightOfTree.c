/* 
   Given In Order and Pre Order traversal of tree , 
   This programme creats Binary Tree .
   This programme works only in case of Complete Binary Tree . 
   Need some more conditions handling to make it general .
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
/*
treeNode * deleteFromBst(treeNode * root,int data)
{
    if(!root)
    {
	printf("\nNod not present\n");
	return root;
    }
    if( root -> data > data)
    {
	deleteFromBst(root -> lTree, data);
    }
    else if(root -> data < data)
    {
	deleteFromBst(root->rTree,data);
    }
    else
    {
	treeNode* treeNodeToBeDeleted = root ;
	root = root -> right;
	if(!root)
	{

	}
    }
}
*/

int hightOfBtree(treeNode * root)
{
    if(!root)
    { return 0;}

    int  lTreeHight,rTreeHight;
    lTreeHight = 1+hightOfBtree(root -> lTree);
    rTreeHight = 1+hightOfBtree(root -> rTree);
    if(lTreeHight > rTreeHight)
    { return lTreeHight;}
    else
    {return rTreeHight;}
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
  int hight,totalNodesInTree, inFixArr[15],preFixArr[15],nodeToBeDeleted;
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
  printf("after creating tree :- \n");
  printf("\nPrefix Notation\n");
  prefix(root);
  printf("\nInfix Notation\n");
  infix(root);
  printf("\nPostfix Notation\n");
  postfix(root);
  printf("\n");

//  printf("Enter node to be deleted :- ");
  //scanf("%d",&nodeToBeDeleted);
  //root = deleteFromBst(root,nodeToBeDeleted);

  hight = hightOfBtree(root);
  printf("Hight of Tree is :- %d\n",hight);

  return 0;
}

///////////////////////////////////////////////
