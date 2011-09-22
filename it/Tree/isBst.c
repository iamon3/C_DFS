///////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////

 /* Main Idea behind checking whether given tree is BST or not */
 /* is , BST when printed in InOrder Treversal it prints sorted Array. */
 /* i.e. All we need is to keep track of predecessor of a node in in-order */
 /* traversal and check whether node is greter than its predecessor or not. */

///////////////////////////////////////////////

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree tree;

tree *  findRootIn_InfixArr(int in[],int pre[],int fstIn ,int lstIn ,int fstPre);
tree *  toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre );

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

void prefix(tree *root)
{
    if(root)
    {
	printf("%d\t",root -> data);
	prefix(root->left);
	prefix(root ->right);
    }
}

void infix(tree* root)
{
    if(root)
    {
	infix(root->left);
	printf("%d\t",root -> data);
	infix(root ->right);
    }
}

void postfix(tree*root)
{
    if(root)
    {
	postfix(root->left);
	postfix(root ->right);
	printf("%d\t",root -> data);
    }
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

tree * findRootIn_InfixArr(int in[],int pre[],int fstIn ,int lstIn ,int fstPre)
{
    int i;
    tree *root=NULL;
    
    for( i=fstIn ; i<=lstIn ;i++ )
    {
	if( pre[fstPre] == in[i] )
	{
	    root = (struct tree *)malloc(sizeof(struct tree));	    
	    root -> left = toPostFix(in ,pre ,fstIn ,i-1 ,fstPre+1);
	    root -> right = toPostFix(in ,pre ,i+1 ,lstIn ,i+1);
	    printf("%d\t",in[i]);
	    root -> data = in[i];
	    return root;
	}
    }
    return root;
}


/*
  fstIn , lstIn , fstPre are indices in array in=inFix & pre=preFix respectively 
*/

tree * toPostFix( int in[],int pre[],int fstIn ,int lstIn ,int fstPre )
{
   
    tree *root = NULL;
    
    if(fstIn < lstIn)
    { root =findRootIn_InfixArr( in, pre, fstIn , lstIn , fstPre ); return root;}
    else
    { 
	printf("%d\t",in[lstIn]);
	root = (struct tree *)malloc(sizeof(struct tree)); 
	root -> left = NULL;
	root -> right = NULL;
	root -> data = in[lstIn];
	return root;
    }
}

/////////////////// MAIN FUNCTION TO CHECK BST ////////////////////////

int isBst(tree* root, tree** predecessor){

  if(!root) 
    return 1;

  if(!root-> left && !root -> right){
    if(*predecessor){
      if((*predecessor) -> data > root -> data)
	return 0;
    }
    *predecessor = root;
    return 1;
  }
  if(isBst(root ->left, predecessor)){
    if(*predecessor){
      if ((*predecessor) -> data > root -> data){ return 0;}
    }
    *predecessor = root;
    return isBst(root -> right, predecessor);
  }

  return 0;
}

//////////////////////////////////////////////////////////

int main()
{
  int totalNodesInTree , inFixArr[20] , preFixArr[20] ;
  tree *root = NULL;
  tree* pred = NULL;
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

  if(isBst(root, &pred)){
    printf("Its BST \n");
  }
  else{
    printf("Its not BST\n");
  }
  printf("Final root pred => %d\n",pred -> data);
  return 0;
}

//////////////////////////////////////////////////////////
