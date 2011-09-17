////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                  
#include<stdio.h>                                 
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                       
int count=0;

struct TreeNode
{
  int data;
  struct TreeNode *leftChild;
  struct TreeNode *rightChild;
};
typedef struct TreeNode TreeNode;



struct que
{
  struct TreeNode *queNode;
  struct que *next;
};
typedef struct que Que;
Que *front,*rear;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

TreeNode* deque();
int countInternalNodes(TreeNode* root);
void enque(TreeNode* addressOfTreeNode);
void createBinaryTree(TreeNode **root);
void printInOrder(TreeNode* root);
void printPreOrder(TreeNode* root);
void printPostOrder(TreeNode* root);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
  int internalNodes ;
  TreeNode *root=NULL;
  createBinaryTree(&root);
  printf("\n\n");
  printPreOrder(root);
  printf("\n");
  printInOrder(root);
  printf("\n");
  printPostOrder(root);
  printf("\n");
  internalNodes = countInternalNodes(root);
  printf("Internal nodes =%d\n",internalNodes);
  return 0;
}


void createBinaryTree(TreeNode **root)
{
  char c;
  int data;
  TreeNode *newNode=NULL,*parentNode = NULL;

  printf("\n Do you want insertion(Y/N) :");
  scanf(" %c",&c);
  //  c=getchar();
  
  if(c=='Y')
    {

      parentNode = deque();
      
      if( parentNode == NULL )
	{
	  printf("\n Enter data of root of tree :");
	  scanf("%d",&data);
	  newNode = (TreeNode *)malloc(sizeof(TreeNode));
	  newNode -> data = data ;
	  newNode -> leftChild = NULL;
	  newNode -> rightChild = NULL ;
	  (*root)= newNode ;
	  enque(newNode);
	  createBinaryTree(&*root);
	  return;
	}
      
      printf("\n Enter left child of parent %d . (If NULL enter -1) :",parentNode -> data);
      scanf("%d",&data);
      
      if(data != -1)
	{
	  newNode = (TreeNode *)malloc(sizeof(TreeNode));
	  newNode -> data = data ;
	  newNode -> leftChild = NULL;
	  newNode -> rightChild = NULL ;
	  parentNode -> leftChild = newNode ;
	  enque(newNode);
	}

      printf("\n Enter right child of parent %d . (If NULL enter -1) :",parentNode -> data);
      scanf("%d",&data);
      
      if(data != -1)
	{
	  newNode = (TreeNode *)malloc(sizeof(TreeNode));
	  newNode -> data = data ;
	  newNode -> leftChild = NULL;
	  newNode -> rightChild = NULL ;
	  parentNode -> rightChild = newNode ;
	  enque(newNode);
	}

      createBinaryTree(&*root);
      return;
    }

  else if(c=='N')
    {
      printf("Thank You.............. \n");
      return;
      // exit(0) ;
    }

  else
    {
      printf("\nWrong input .");
      createBinaryTree(&*root);
    }
  return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void enque(TreeNode* addressOfTreeNode)
{
  Que* new=NULL;

  new =(Que *)malloc(sizeof(Que));
  new -> queNode = addressOfTreeNode; 
  new -> next = NULL;

  if(front == NULL)
    {
      front = rear = new;
    }

  else
    {
      rear -> next = new;
      rear = rear -> next;
    }
}


TreeNode* deque()
{
  Que* new=NULL;
  
  if( front == NULL )
    {
      return NULL;
    }
  
  else
    {
      new = front ;
      front = front -> next ;
      return ( new -> queNode );
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void printInOrder(TreeNode* root)
{
  //  TreeNode *left = NULL ,*right = NULL;
 
  if(!root)
    {
      return ;
    }
  
  if(root->leftChild)
    {
        printInOrder(root -> leftChild);
    }
  
  printf("%d\t",root->data);     
  
  if(root->rightChild)
    {
      printInOrder( root -> rightChild );
    }

  return ;
}


void printPreOrder(TreeNode* root)
{
  if(!root)
    {
      return ;
    }
  if(root)
    printf("%d\t",root->data);
  if(root->leftChild)
    {
      printInOrder(root -> leftChild);
    }
  if(root->rightChild)
    {
      printInOrder( root -> rightChild );
    }
  return ;
}


void printPostOrder(TreeNode* root)
{
  if(!root)
    {
      return ;
    }
  if(root->leftChild)
    {
      printInOrder(root -> leftChild);
    }

  if(root->rightChild)
    {
      printInOrder( root -> rightChild );
    }

  printf("%d\t",root->data);
  return ;     
}
                                                                                                                 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int countInternalNodes(TreeNode* root)
{
  int leftCount=0,rightCount=0,count=0;
  
  if(!root)
    {
      return 0;
    }
  
else if(!(root->leftChild) && !(root->rightChild))
  {
    return -1  ;
  }
  
  else
    {
      if(root->leftChild)
	{
	  leftCount =1+ countInternalNodes( root -> leftChild );
	}
      if(root->rightChild)
	{
	  rightCount = 1+ countInternalNodes( root -> rightChild );
	}
    }

  return ( leftCount + rightCount );
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
