/* Return Inorder successor of the given element.
   Though it is not sufficient soln ,it works correct.
   Not efficient because it traverses left subtree first
    though root is element.
*/

tree* mainInOrder(tree* root,tree* element,int* flag){
  if(!root) return NULL;
  tree* result= NULL;

  result = mainInOrder(root -> left, element, flag);

  if (result != NULL) return result;
  if (*flag == 1){*flag = 2; return root;}
  if(root == element){*flag = 1;}

  return mainInOrder(root -> right, element, flag);
}

// Main Function which will interally call recursive function
// input is tree and element of which in-order successor is to be found
 
tree* inOrder(tree*  root, tree* element ){
  if(!root && !element) return NULL;
  int flag = 0;
  return mainInOrder(root, element, &flag);
}
