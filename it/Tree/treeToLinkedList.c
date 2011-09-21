///////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

///////////////////////////////////////////////

/* This programme converts given tree into doubly linked list */
/* Note here tree created expects tree to be created should complete */
/* binary tree. */
/* You can create your binary tree not necessarily complete by your own logic. */
/* Main conversion function is accurate so it will work in that case also. */

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

void printLL(tree* head){
  while(head){
    printf("%d -> ", head -> data);
    head = head -> right;
  }
  printf("\n=============== Thank You =============\n");
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
	    root -> data = in[i];//creatNode(in[i]);
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
    /* if ( fstIn < 0 ) 
       { return ;} 
       else */ 
    
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

///////// Main Tree To Doubly Linked List conversion logic //////////////

void treeToLL(tree* root, tree** head, tree** tail){
 
 if((!root) || (!root -> left && !root -> right))
    {
      *head = *tail = root;
      return;
    }

 tree *lh=NULL, *lt=NULL, *rh=NULL, *rt=NULL;
 treeToLL(root -> left, &lh, &lt);
 treeToLL(root -> right, &rh, &rt);
 
 if(lh){
   lt -> right = root;
   root -> left=lt;
   *head = lh;
 }
 else{
   *head = root;
 }

 if(rh){
   root -> right = rh;
   rh -> left = root;
   *tail = rt;
 }
 else{
   *tail = root;
 }
}

//////////////////////////////////////////////////////////

int main()
{
  int totalNodesInTree , inFixArr[20] , preFixArr[20] ;
  tree *root = NULL;
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

  tree *head=NULL, *tail = NULL;

  treeToLL(root, &head, &tail);
  printf("After converting tree to Linked List :- \n");
  printLL(head);

  return 0;
}

//////////////////////////////////////////////////////////

