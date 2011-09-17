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


struct DList
{
  struct TreeNode *head;
  struct TreeNode *tail;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

TreeNode* deque();
void enque(TreeNode* addressOfTreeNode);
void createBinaryTree(TreeNode **root);
void printInOrder(TreeNode* root);
void printPreOrder(TreeNode* root);
void printPostOrder(TreeNode* root);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void printList( struct DList* dll)
{
  TreeNode* head;
  head = dll -> head ;
/*   while(head->leftChild) */
/*     { */
/*       head = head -> leftChild; */
/*     } */
  while(head -> rightChild)
    {
      printf("%d\t",head ->data);
      head = head -> rightChild;
    }
  printf("\n");
}


////////////////////

struct DList * convertToInfixList(struct TreeNode* root )
{
  struct DList *DLeft, *DRight , *Dll1 ;
  Dll1 = (struct DList *) malloc(sizeof(struct DList));
  Dll1 -> head = root ;
  Dll1 -> tail = root ;

  if(! root || (!(root -> leftChild) && !(root -> rightChild )))
    {
      return Dll1;
    }

  DLeft = convertToInfixList(root -> leftChild );
  DRight = convertToInfixList(root -> rightChild );

  root -> leftChild = DLeft -> tail ;
  root -> rightChild = DRight -> head ;

  // printf("Hi1\n");

  if(! DLeft -> head)
    {
      Dll1 -> tail = DRight -> tail ;
      return Dll1;
    }
  //  printf("Hi2\n");
  if(! DRight -> head)
    {
      DLeft -> tail = Dll1 -> tail ;
      return DLeft;
    }
  DLeft -> tail -> rightChild = root ;
  DRight -> head -> leftChild = root ;
  DLeft -> tail = DRight -> tail;
  return DLeft;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  TreeNode *root=NULL;
  createBinaryTree(&root);
  printf("\n\n");
  printPreOrder(root);
  printf("\n");
  printInOrder(root);
  printf("\n");
  printPostOrder(root);
  printf("\n");

  printf("\n Converting to doubly Linked List :-");
  struct DList *dll;
  dll = (struct DList *) malloc(sizeof(struct DList));
  //  dll -> head = (struct TreeNode* )malloc(sizeof(struct TreeNode)) ;
  dll -> head = root ;
  //dll -> tail = (struct TreeNode* )malloc(sizeof(struct TreeNode)) ;
  dll -> tail = root ;
  dll = convertToInfixList(root);
  //  dll = convertToInfixList(root,dll);

  printList(dll);

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
