////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

////////////////////////////////

typedef struct avlTreeNode
{
  int data;
  int height;
  char balanceFactor;
  struct avlTreeNode* leftTree;
  struct avlTreeNode* rightTree;
}avlTreeNode;


#define LH '/'
#define RH '\\'
#define EQ '='


////////////////////////////////

void preOrderTraversal( avlTreeNode* root )
{
  if( root )
    { 
      printf("%d ",root -> data );
      preOrderTraversal( root -> leftTree );
      preOrderTraversal( root -> rightTree );
    }
}

void inOrderTraversal( avlTreeNode* root )
{
  if( root )
    {
      inOrderTraversal( root -> leftTree );
      printf("%d ",root -> data );
      inOrderTraversal( root -> rightTree );
    }
  
}

void postOrderTraversal( avlTreeNode* root)
{
  if( root )
    {
      postOrderTraversal( root -> leftTree );
      postOrderTraversal( root -> rightTree );
      printf("%d ",root -> data );
    }

}


void printTree(avlTreeNode* root)
{
  printf("\n\n**********************************\n\n");

  printf("\nInOrder Traversal\n");
  inOrderTraversal(root);

  printf("\nPreOrder Traversal\n");
  preOrderTraversal(root);

  printf("\nPostOrder Traversal\n");
  postOrderTraversal(root);
  printf("\t\t[%d]\n",root->height);
}

////////////////////////////////

int calculateMaxHight( avlTreeNode* root )
{
  printf("\nIn CalculateMaxHight\n");

  if( !(root -> leftTree) && !(root -> rightTree) )
    {
      return -15;
    }

  if(!(root-> leftTree) )
    {
      return -(root->rightTree -> height) ;
    }

  if( !(root -> rightTree) )
    {
      return root -> leftTree -> height ;
    }

  return ((root -> leftTree -> height) - ( root -> rightTree -> height )) ;
}

////////////////////////////////

avlTreeNode* creatNode( int key )
{
  avlTreeNode* temp = NULL;

  temp = (avlTreeNode* )malloc(sizeof (avlTreeNode ));

  temp -> data = key;
  temp -> height = 1;
  temp -> balanceFactor = EQ ;
  temp -> leftTree = NULL;
  temp -> rightTree = NULL;

  return temp;
}

////////////////////////////////

int maxHt( avlTreeNode* root )
{
  if(!(root -> leftTree) && !( root -> rightTree) )
    return 0;
  if(!(root-> leftTree))
    return root -> rightTree -> height;
  if(!(root -> rightTree))
    return root -> leftTree -> height;
  if( (root -> leftTree -> height) > (root -> rightTree -> height))
    return root -> leftTree -> height;
  return  root -> rightTree -> height;
}

avlTreeNode* leftRotation( avlTreeNode* root )
{
  printf("\nIn leftRotation DEFINATION Insertion\n");
  avlTreeNode* temp = NULL;
  temp = root -> rightTree;
  root -> rightTree = temp -> leftTree ;
  //  ( root -> rightTree ? ( root-> height = 1+ root -> rightTree -> height ) : (root -> height = 1 ) );
  root -> height = 1 + maxHt( root );
  root -> balanceFactor = RH;
  temp -> leftTree = root ;
  temp -> height = 1 + maxHt( temp );
  temp -> balanceFactor = EQ;
  //  ( root -> leftTree ? ( root-> height = 1+ root -> leftTree -> height ) : (root -> height = 1 ) );
  return temp;
}
 
avlTreeNode* rightRotation( avlTreeNode* root )
{
  printf("\nIn RightRotation Defination Insertion\n");

  avlTreeNode* temp;
  temp = root -> leftTree;
  root -> leftTree = temp -> rightTree ;
  ( root -> leftTree ? ( root-> height = 1+ root -> leftTree -> height ) : (root -> height = 1 ) );
  root -> balanceFactor = LH;
  root -> height = 1 + maxHt( root );
  temp -> rightTree = root;
  temp -> height = 1 + maxHt( temp );
  temp -> balanceFactor = EQ;
  //  ( root -> leftTree ? ( root-> height = 1+ root -> leftTree -> height ) : (root -> height = 1 ) );
  root = temp;
  return root;
}

avlTreeNode* balanceLeft(avlTreeNode* root)
{
  int balanceDifference;
  
  balanceDifference = calculateMaxHight( root-> leftTree );
  printf("\nIn balanceLeft Insertion\n");

  switch ( balanceDifference )
    {

    case 1: case 0:
      {
	printf("\nIn RightRotation Insertion\n");
	return rightRotation( root );
      }

    case -1:
      {
	printf("\nIn LeftRotation Insertion\n");
	root -> leftTree = leftRotation( root -> leftTree );
	printf("\nIn RightRotation Insertion\n");
	return rightRotation( root );
      }

    }

  return root;
}


avlTreeNode* balanceRight( avlTreeNode* root )
{
  int balanceDifference;

  printf("\nIn BalnaceRight Insertion\n");

  balanceDifference = calculateMaxHight( root-> rightTree );
  
  printf("========== %d\n",balanceDifference);
  switch ( balanceDifference )
    {
      
    case 1:
      {
	printf("\nIn RightRotation Insertion\n");
	root -> rightTree = rightRotation( root -> rightTree );
	printf("\nIn leftRotation Insertion\n");	
	return leftRotation( root );
      }

    case -1:  case 0 :
      {
	return leftRotation( root );
      }

    }

  return root;
}


/////////////////////////////////////////////////

avlTreeNode* rightBalanceCases(avlTreeNode* root)
{
  int balanceDifference;
  
  balanceDifference = calculateMaxHight( root );
  
  switch (balanceDifference) 
    {
      
    case -15:
      {
	printf("\nDon have left and right child\n");
	root -> rightTree -> height = 1;
	root -> rightTree -> balanceFactor = EQ;
	break;
      }
            
    case 0:
      {
	printf("\nBoth equal hight subtrees\n");
	root -> height = 1 + ( root -> rightTree -> height ) ;
	root -> balanceFactor = EQ ;
	break;
      }
      
    case -2:
      {
	printf("\nRight highted, calling balanceRight\n");
	root  = balanceRight( root );
	break;
      }
      
    case -1:
      {
	/*	    printf("\nLeft subtree hightedt\n");*/
	root -> height = 1 + ( root -> rightTree -> height );
	root -> balanceFactor = RH ;
	break;
      }
    }  
  return root;
}

////////////////////////////////

avlTreeNode* leftBalanceCases(avlTreeNode* root)
{
  int balanceDifference;
  
  balanceDifference = calculateMaxHight( root );
  
  switch (balanceDifference) 
    {
      
    case -15:
      {
	printf("\nDon have left and right child\n");
	root -> leftTree -> height = 1;
	root -> leftTree -> balanceFactor = EQ;
	break;
      }
	  
      
    case 0:
      {
	printf("\nBoth equal hight subtrees\n");
	root -> height = 1 + ( root-> leftTree -> height ) ;
	root -> balanceFactor = EQ ;
	    break;
      }
      
    case 1:
      {
	/*	    printf("\nright subtree highted\n");*/
	root -> height = 1 + (root -> leftTree -> height) ;
	root -> balanceFactor = LH ;
	break;
      }
	
    case 2:
      {
	printf("\nLeft subtree highted calling balanceLeft\n");
	root  = balanceLeft( root );
	break;
      }
    } 

  return root;
}

////////////////////////////////

avlTreeNode* insertNode(avlTreeNode* root , int key )
{
  if( !root )
    {
      printf("\nIn leaf Insertion\n");
      root = creatNode( key );
      return root;
    }
  
  if( root -> data == key )
    {
      printf("\nDuplicate Key Not permitted\n");
      return root;
    }
  
  else if( root -> data > key )
    {
      printf("\nBefore Left Insertion\n");
      root -> leftTree = insertNode( root -> leftTree , key ) ;
      printf("\nAfter Left Insertion\n");
      root =  leftBalanceCases(root);
      return root;
    }

  else
    {
      printf("\nBefore Rightt Insertion\n");
      root -> rightTree = insertNode( root -> rightTree , key ) ;
      printf("\nAfter Right Insertion\n");
      root = rightBalanceCases(root);
      return root;
    }

  return root;
}

////////////////////////////////

avlTreeNode* balanceDown(avlTreeNode** toBedeleted , avlTreeNode* parent , avlTreeNode* child)
{
  if( child -> leftTree)
    {
      parent -> leftTree = balanceDown(&(*toBedeleted) , child ,child -> leftTree );
      parent = rightBalanceCases(parent);
      return parent;
    }
  else
    {
      parent -> leftTree = child -> rightTree ;
      child -> rightTree = NULL;
      parent = rightBalanceCases( parent );
      child -> leftTree = (*toBedeleted ) -> leftTree;
      child -> rightTree = (*toBedeleted) -> rightTree;
      free(*toBedeleted);
      (*toBedeleted)= child;
      return parent;
    }
  return parent;
}

////////////////////////////////

avlTreeNode* deletionAvlTree( avlTreeNode* root ,int key )
{
  if(!root)
    {
      printf("Key not present\n");
      return root;
    }

  if( root-> data == key )
    {
      avlTreeNode* temp = NULL;

      if(!root -> rightTree)
	{
	  free(root);
	  root = temp;
	}
      else
	{
	  temp = root -> rightTree ; 
	  root -> rightTree = balanceDown(&root,temp,temp);
	  root = leftBalanceCases(root);
	}
      return root;
    }

  else if( root -> data > key )
    {
      printf("\nBefore Left Deletion\n");
      root -> leftTree = deletionAvlTree( root -> leftTree , key ) ;
      printf("\nAfter Left Deletion\n");
      root =  leftBalanceCases(root);
      return root;
    }
  
  else
    {
      printf("\nBefore Rightt Deletion\n");
      root -> rightTree = deletionAvlTree( root -> rightTree , key ) ;
      printf("\nAfter Right Deletion\n");
      root = rightBalanceCases(root);
      return root;
    }
 
  return root;
}

////////////////////////////////

avlTreeNode * createAvlTree(avlTreeNode* root)
{
  int option = 0;

  printf("\nEnter data (-1 to stop) :- ");
  scanf("%d",&option);

  while( option != -1 )
    {
      root = insertNode(root , option );
      printTree(root);
      printf("\n\nEnter data (-1 to stop) :- ");
      scanf("%d",&option);
    }

  printf("\nEnter data to be deleted :- ");
  scanf("%d",&option);
  root = deletionAvlTree(root,option );
  printTree(root);

  return root;
}

////////////////////////////////

int main()
{
  avlTreeNode* root = NULL;

  root = createAvlTree(root);
  return 0;
}

////////////////////////////////
