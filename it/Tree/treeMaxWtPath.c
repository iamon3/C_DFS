/*
  This Programme takes Binary Tree and number and 
  find maximum weight path. Max Wt function is correct.
  It works in case of complete binary tree, but gives some error 
  in case if tree is not complete binary tree.
  Only problem is with tree construction so you will have to 
  rectify tree correction error in case of some nodes are null.
*/

///////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

///////////////////////////////////////////////

struct treeNode
{
    int data;
    struct treeNode *lTree;
    struct treeNode *rTree;
};

struct maxPath{
 int sum;
 char path[50];
};

typedef struct maxPath maxPath;
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

///////////////////  MAX WEIGHT PATH FINDER IN TREE ////////////////////////////

void printMaxPath(maxPath* mPath){
printf("Max Sum :- %d\n", mPath -> sum);
int i=0;
printf("root -> ");
for(i = strlen(mPath->path)-1; i>= 0 ; i--){
  printf("%c -> ",mPath -> path[i]);
}
printf("(E) meand end . Path Complete");
}


maxPath* findMaxWtPath(treeNode* root){
 
if(!root) { return NULL;}

maxPath* fPath = NULL, *lPath = NULL, *rPath = NULL;

if(!root -> lTree && !root -> rTree){
maxPath* path = NULL;
path = (maxPath *)malloc(sizeof(maxPath));
path -> sum = root -> data; path -> path[0] = 'E';  // E stands for End
path -> path[1] = '\0';
return path;
}

lPath = findMaxWtPath(root->lTree);
rPath = findMaxWtPath(root->rTree);

if(lPath && rPath){
if(lPath -> sum > rPath -> sum){
free(rPath);
rPath = NULL;
}
else{free(lPath);lPath = NULL;}
}

if (lPath){
lPath -> sum += root-> data; 
lPath ->path[strlen(lPath ->path)] = 'L';
lPath ->path[strlen(lPath ->path)] = '\0';
fPath = lPath; 
}
else{
rPath -> sum += root-> data; 
rPath ->path[strlen(rPath ->path)] = 'R';
rPath ->path[strlen(rPath ->path)] = '\0';
fPath = rPath; 
}

return fPath;

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

  maxPath* mPath = NULL;
  mPath = findMaxWtPath(root);
  printMaxPath(mPath); 

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
