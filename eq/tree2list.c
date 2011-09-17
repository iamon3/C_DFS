// tree 2 post order doubly linked list 
#include<stdio.h>
typedef struct Node
{
int data;
struct Node *left , *right;
} node;

typedef struct 
{
node *head , *tail;

} dlist;

node *root = NULL;
void main()
{
	int n =0, ret , data;

	printf("\n How many number of values? :  ");
	scanf("%d",&n);
	while(n)
	{
		printf("\n Enter the value : ");
		ret = scanf("%d",&data);
		insert(data);
		printf("%d \t\t ----  ",ret);

	}
}

void insert(int data)
{
	if(!root)
	{
	root = (node *)malloc(sizeof(node));
	root->data  = data;
	root->left = root->right = NULL;
	return ;
	}
	node *temp = root,temp1;
	while(temp)
	{
	 if(temp->data < data)
	 {	temp1 = temp;
		temp = temp ->right;		
	 }
	 else
	 {
		temp1 = temp ;
		temp = temp ->left;
	 }
	}
	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = temp ->right = NULL;
	if(temp1->data > data)
	{
	temp1-> left = temp;
	}
	else
	{
	temp1->right = temp;
	}

}


dlist* treeToList(node *root)
{
	if(!root || !(*root))
	{
	return NULL;
	}
	dlist *rlist, *llist,*retlist;
	retlist = (dlist*)malloc(sizeof(dlist));
	retlist ->head = retlist ->tail = root;
	rlist = treeToList(root->right);
	llist = treeToList(root->left);
	root->right = root->left = NULL;
	if(rlist)
	{
		retlist->head = rlist->head;
	  if(llist)
	  {
		rlist->tail->right = llist->head;
		llist->head->left =  rlist->tail;
		llist->tail->right = root;
		root->left  = llist->tail;
	   }
	   else
	   {
		rlist->tail->right = root;
		root->left = rlist->tail;
	   }
	
	}
	else
	if(llist)
	{	
		llist->tail->right = root;
		root->left = llist->tail;
	}	
return retlist;
}
