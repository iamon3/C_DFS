#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pat_node patricia;

struct pat_node
{
  char *info;
  patricia **next;
};


patricia *creat_node(char* word)
{
  int l=strlen(word);
  patricia *root; 
  root = (patricia*)malloc(sizeof(patricia));
  root->info = (char*)malloc(sizeof(char)*l);
  root->info = strcpy(root->info, word);
  root->next = (patricia**)malloc(sizeof(patricia*)*l);
  return root;
}

void insert(patricia **root,char *word)
{
  patricia **temp;
  temp = (patricia**)malloc(sizeof(patricia*));
  (*temp)=(*root);
  int l=strlen(word), i=0, j=0, len=0;
  if(!root)
    {
      printf("Pointer TO Pointer Of Patricia Is NULL.\nSo Word Was Not Inserted\n");
      return;
    }
  if(!(*temp))
    {
      *root=creat_node(word);
      printf("Word Inserted Succesfully\n");
      return;
    }
  while(1)
    {
      len = strlen((*temp)->info);
      while( (*temp)->info[j] == word[i]  &&  j < len ) { i++; j++;}
      if(i == l)
	{
	  printf("Duplicate Key Tried To Insert\n");
	  return;
	}
      
      //i--;
      if( !((*temp)->next[j]) )
	{
	  (*temp)->next[j] = creat_node(word+i);
	  printf("Word Inserted Succesfully\n");
	  return;
	}
      (*temp) = (*temp)->next[j];
      j=0;
      
    }
  return;
}

int search(patricia *root,char *word)
{
  patricia *temp=root;
  int l=strlen(word), i=0, j=0, len=0;
  if(!root)
    {
      printf("Dictionary Has No Words.\nSo Word Not Found\n");
      return 0;
    }
  while(1)
    {
      len = strlen(temp->info);
      while( temp->info[j] == word[i]  &&  j < len ) {i++; j++; }
      if(i == l)
	{
	  printf(word);
	  printf(" Found\n");
	  return 1;
	}
      temp = temp->next[j];
      if(!temp)
	{
	  printf(word);
	  printf(" Not Found\n");
	  return 0;
	}
      j=0;
      // i--;
    }
}


void display(patricia **root)
{
  int n;
  char ch,*word;
  // word = (char*)malloc(sizeof(char)*10);
  while(1)
    {
      printf("\n*******************************MAIN MENU******************************************\n\n");
      printf("\t\tto insert word in dictionary enter 1\n");
      printf("\t\tto search word in dictionary enter 2\n");
      printf("\t\tto come out of loop enter 3\n");
      printf("\t\tenter your choice=> ");
      scanf("%d",&n);
      switch(n)
	{
	case 1:
	  {
	    printf("\nEnter The Word To Be Inserted=> ");
	    scanf("%s",word);
	    insert(root,word);
	    break;
	  }
	case 2:
	  {
	    printf("\nEnter The Word To Be Searched=> ");
	    scanf("%s",word);
	    search(*root,word);
	    break;
	  }
	case 3:
	  {
	    printf("\n\t\tthanks for visiting\n\n");
	    return;
	  }
	}
      ch = getchar();
    }
}


int main()
{
  patricia **root;
  root = (patricia**)malloc(sizeof(patricia*));
  (*root) = NULL;
  display(root);
  //insert(root,"apple");
  // insert(root,"tree");
  // search(*root,"tree");
  return 0;
}
