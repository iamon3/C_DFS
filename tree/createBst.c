/* this programme is to create Binary Search Tree and Inserrtion opration as well recursivly */

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BSTnode
{
  int data;
  struct BSTnode *right;
  struct BSTnode *left;
};

typedef struct BSTnode bstNode;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void preOrderTraversal(bstNode* root)
{
  if(root)
    {
      printf("%d\t",root->data);
      preOrderTraversal(root -> left);
      preOrderTraversal(root -> right);
    }
}

void inOrderTraversal(bstNode* root)
{
  if(root)
    {
      inOrderTraversal(root -> left);
      printf("%d\t",root->data);  
      inOrderTraversal(root -> right);
    }
}

void postOrderTraversal(bstNode* root)
{
  if(root)
    {
      postOrderTraversal(root -> left);
      postOrderTraversal(root -> right);
      printf("%d\t",root->data);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void insertNode(bstNode** head, int valueToBeInserted)
{
  if(((*head)->data) > valueToBeInserted )
    {
      if((*head)->left == NULL)
	{
	  bstNode* new;
	  new = (bstNode*)malloc(sizeof(bstNode));
	  new -> data = valueToBeInserted;
	  new -> right = NULL;
	  new -> left = NULL;
	  (*head)-> left = new;
	}
      else
	{
	  insertNode(&((*head) -> left) ,valueToBeInserted);
	}
    }

  else
    {
      if((*head) -> right == NULL)
	{
	  bstNode* new;
	  new = (bstNode*)malloc(sizeof(bstNode));
	  new -> data = valueToBeInserted;
	  new -> right = NULL;
	  new -> left = NULL;
	  (*head)-> right = new;
	}
      else
	{
	  insertNode(&((*head) -> right) ,valueToBeInserted);
	}
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bstNode* createBST(bstNode** root)
{
  char c;
  printf("\nDo you want insertion (Y/N) : ");
  scanf(" %c",&c);
  if(c=='Y')
    {
      int valueToBeInserted;

      printf("\nEnter no :");
      scanf("%d",&valueToBeInserted);

      if(!(*root))
	{
	  bstNode* new;
	  new = (bstNode*)malloc(sizeof(bstNode));
	  new -> data = valueToBeInserted;
	  new -> right = NULL;
	  new -> left = NULL;
	  (*root) = new;
	  printf("\nRoot Value is %d",(*root)->data);
 	}

      else
	{
	  bstNode* head ;
	  head = (*root);
	  insertNode(&head ,valueToBeInserted);
	}
      createBST(&(*root));
    }
  else if(c=='N')
    {
      printf("\nThank You\n");
      return (*root);
    }
  else
    {
      printf("\n Wrong input .Different from (Y/N)");
      createBST(&(*root));
    }
  return (*root);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  bstNode* root=NULL;
  root = createBST(&root);

  printf("\nPre Order is as shown\n");
  preOrderTraversal(root);
  
  printf("\n In Order is as shown\n");
  inOrderTraversal(root);

  printf("\n Post Order is as shown\n");
  postOrderTraversal(root);
  
  printf("\n");
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
