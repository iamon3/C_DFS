///////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////

/* Main LCA finder function works perfectly. */
/* Only problem is with Tre creation when nodes are greater 7. */
/* But function is perfect. Works in all cases. So use it where u have proper tree  */
/* builidng function. */

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

/////////////////// MAIN CODE TO FIND LCA ////////////////////////

/* This function works in preoder traversal way. */
/* If both elements are found then it does not goes further down the tree. */
/* Main Idea is used is to check if return value is  */
/* 2 then current root is LCA.  */
/* >2 then already LCA is found in subtree. just return. */

/* if root is one of elements then it searches second element in left subtree, */
/*   if in left subtree return 1 then current root is 1 element and */
/*     left subtree contains 2nd element, So return 2 i.e 2 elements found. */
/*     So parent will see returned value is 2, so parent is LCA */
/*   if left subtree return 0 */
/*     then it finds in right subtree */
/*   if right subtree contains second element then again root return 2 */
/*     parent will see returned value == 2 .. Parent will be LCA. */

/* Parameters :-  noOfElementsFound keeps track of elems found. 
Thus reduce further going down in tree */

int findLca(tree* root, int* noOfElementsFound, int fistElm, int sndElm){
 
  if(!root) return 0;
  int ret = 0;

  if(root -> data == fistElm || root -> data == sndElm){
    *noOfElementsFound += 1;
    ret = 1;
    if (*noOfElementsFound == 2){return 1;} 
  }
 
  int lc = 0;
  
  lc = findLca(root -> left, noOfElementsFound, fistElm, sndElm );
  
  if(lc > 2) {return 1 + lc;} // i.e return greater than 2
  if (lc == 2){printf("LCA is => %d\n",root -> data); return 1+lc;} // i.e return greater than 2 
  if(lc == 1 && ret == 1) {return ret + lc;} // i.e. return 2
  
  int rc = 0;
  rc = findLca(root -> right, noOfElementsFound, fistElm, sndElm);

  if(rc == 1){
    if(lc == 1){printf("LCA is => %d\n",root -> data); return 1+lc+rc;} // i.e return greater than 2
    if(ret == 1){return ret + rc;} // i.e return 2
    return rc; // i.e. return 1
  }

  if(rc == 2){printf("LCA is => %d\n", root -> data); return 1+rc;} // i.e. return greater than 2
  if(rc > 2) {return 1+rc;} // i.e. return greater than 2
  
  return ret + lc + rc;

}

//////////////////////////////////////////////////////////

int main()
{
  int totalNodesInTree ;
  tree *root = NULL;
 
  int totalNodesInTree1 = 3;
  int preFixArr1[]={1,2,3};
  int inFixArr1[]={2,1,3};

  int totalNodesInTree2 = 7;
  int preFixArr2[]={1,2,4,5,3,6,7};
  int inFixArr2[]={4,2,5,1,6,3,7};
  
  int totalNodesInTree3 = 15;
  int preFixArr3[]={1,2,4,8,9,5,10,11,3,6,12,13,7,14,15};
  int inFixArr3[] ={8,4,9,2,10,5,11,1,12,6,13,3,14,7,15};

  printf("Values of nodes in preorder\n");
  printArr(preFixArr2,totalNodesInTree2);

  printf("Values of nodes in inorder\n");
  printArr(inFixArr2,totalNodesInTree2);


  printf("Post Fix Order as shown :\n");
  root = toPostFix(inFixArr2,preFixArr2,0,(totalNodesInTree2) - 1,0);
  printf("\n");
  printf("after creating tree :- \n");
  printf("\nPrefix Notation\n");
  prefix(root);
  printf("\nInfix Notation\n");
  infix(root);
  printf("\nPostfix Notation\n");
  postfix(root);
  printf("\n");

  int fst, snd, noOfElementsFound=0;

  printf("Enter two elements of which LCA to be found :- \n");
  scanf("%d%d",&fst, &snd);

  int ret = 0;

  if((ret = findLca(root, &noOfElementsFound, fst, snd)) >= 2){
    if(ret == 2){
      printf("Note :- If one of elements you entered is at root LCA will not be there\n");
    }
    else {
      printf("LCA Found\n");
    }
  }
  else{
    printf("One/both of the elements you entered not present in tree. SO LCA not there \n");
  }

  return 0;
}

//////////////////////////////////////////////////////////
