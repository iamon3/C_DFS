// This is kept as back up.
// Because it was devloped before the current
// isBst.c method. and after working on this
// only i could figured out correct isBst.c
int isBst(tree* root, tree** predecessor){

  if(!root) 
    return 1;

  printf("root - %d \n",root-> data);

  if(!root-> left && !root -> right){
    if(*predecessor){
      printf("pred - %d \n",(*predecessor) -> data);
      if((*predecessor) -> data > root -> data)
	return 0;
    }
    *predecessor = root;
    return 1;
  }
  /*
  tree* leftTreePredecessor = NULL;

  if(isBst(root ->left, &leftTreePredecessor)){
    if(leftTreePredecessor){
      printf("Left pred - %d \n",leftTreePredecessor -> data);
      if (leftTreePredecessor -> data > root -> data){ return 0;}
    }
    *predecessor = root;
    return isBst(root -> right, predecessor);
  }
  */
  if(isBst(root ->left, predecessor)){
    if(*predecessor){
      printf("Left pred - %d \n",(*predecessor) -> data);
      if ((*predecessor) -> data > root -> data){ return 0;}
    }
    *predecessor = root;
    return isBst(root -> right, predecessor);
  }

  return 0;
}
