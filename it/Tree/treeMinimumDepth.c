#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////

 /* This finds minimum depth of given tree */

//////////////////////////////////////

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};
typedef struct tree tree;

//////////////////////////////////////

// Create your tree manually here

tree* creatTree(){
  tree* root = NULL;
  root = (tree*)malloc(sizeof(root));
  root -> data = 1;

  root-> left = (tree*)malloc(sizeof(root));
  root -> left -> data = 2;
  root -> left -> left = NULL;

  root-> left -> right = (tree*)malloc(sizeof(root));
  root -> left -> right -> data =3 ;
  root ->right = (tree*)malloc(sizeof(root));
  root -> right -> data = 4;

  return root;
}

/////////////// Main Functions ///////////////////////

int min(int a, int b){
  return a +(((b-a)>>31)*(a-b));
}

int mainMinDepth(tree* root){
  if(!root) return 0;
  if(!root -> left && !root -> right)return 1;
  int lmd=0, rmd=0, md=0;

  lmd = mainMinDepth(root-> left);
  rmd = mainMinDepth(root-> right);
 
  if(lmd == 0){md = rmd;}
  else if(rmd == 0){md = lmd;}
  else{md = min(lmd, rmd);}
 
  return 1 + md;
}

int minDepth(tree* root){
  return mainMinDepth(root)-1;
}

//////////////////////////////////////

int main(){
  tree* root = NULL;
  root = creatTree();
  printf("Min Depth = %d\n",minDepth(root));
  return 0;
}
