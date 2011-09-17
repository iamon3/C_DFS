/* This programme impements Trie data structure used in dictionary creation */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct trieNode
{
  char* word;
  struct  trieNode* alphaBetical[26];
};

typedef struct trieNode trieNode;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

trieNode* searchWord(trieNode* root,char key[])
{
  //  char key[26];
  int i,length;

 /*  printf("\nEnter Word You want to search :"); */
/*   scanf("%s",&key); */
  //gets(key);
  length = strlen(key);
  //printf("Hi0\n");
  for(i=0 ; i<length ; i++)
    {
      /* if(key[i]=='\0')
	{
	  break;
	  }
      else
      {*/
      //  printf("Hi1\n");
	  if(root -> alphaBetical[key[i]-'a'] != NULL)
	    {
	      root = root -> alphaBetical[key[i]-'a'];
	      //  printf("Hi2\n");
	    }
	  else
	    {
	      break;
	    }
    }
  //printf("Hi3\n");
  if(i==length && root->word != NULL)
    {
      // printf("Hi4\n");
      printf("%s Word Found \n",key);
      return root;
    }
  else
    {
      printf("Word you are trying to find is not found \n");
      return NULL;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deleteNode(trieNode** root)
{
  char key[26];
  trieNode* wordToBeDeleted;

  printf("\nEnter Word You want to delete :");
  scanf("%s",&key);

 wordToBeDeleted = searchWord(*root , key);

 if(wordToBeDeleted != NULL)
   {
     int i;
     for(i=0;i<26;)
       {
	 if(i<26 && wordToBeDeleted -> alphaBetical[i] != '\0')
	   {
	     break;
	   }
	 else
	   {
	     i++;
	   }
       }
     if(i==26)
       {
	 free(wordToBeDeleted);
       }
     else
       {
	 wordToBeDeleted -> word = NULL;
       }
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

trieNode* creatNode(void)
{
  int ch;
  trieNode* new = (trieNode *)malloc(sizeof(trieNode));

  for(ch=0;ch < 26 ; ch++)
    {
      new -> alphaBetical[ch] = NULL;
    }
  new -> word = NULL;

  return new;
}


void insertTrie(trieNode** root)
{
  char c;
  printf("\nDo you want insertion (Y/N) :");
  scanf(" %c",&c);

  if(c=='Y')
    {
      trieNode* saveRoot=NULL;
      int length ,i;
      char key[26];

      saveRoot = (*root);

      printf("\nEnter word to be inserted :");
      scanf("%s",&key);
      //gets(key);
      length = strlen(key);

      if(!*root)
	{
	  (*root)=creatNode();
	  saveRoot = (*root);
	}


      for(i=0 ; i <length ; i++)
	{
	  if(key[i]=='\0')
	    {
	      break;
	    }
	  else
	    {
	      if(!(*root) -> alphaBetical[key[i]-'a'])
		{
		  (*root) -> alphaBetical[key[i]-'a'] = creatNode();
		}
	      (*root) = (*root) -> alphaBetical[key[i]-'a'];
	    }
	}
      
      if((*root)->word != NULL)
	{
	  printf("Word You are trying to insert is already present \n");	  
	}

      else
	{
	  (*root) -> word = key;                                                      // Here some work is remaining 
	}
      (*root) = saveRoot;
      insertTrie(&(*root));
      return;
    }

  else if(c=='N')
    {
      printf("\nThank You \n");
      return ;
    }

  else
    {
      printf("\nWrong Input .");
      insertTrie(&(*root));
      return;
    }
  return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  char key[26];
  trieNode* root=NULL;
  insertTrie(&root);

  printf("\nEnter Word You want to search :");
  scanf("%s",&key);
  searchWord(root,key);

  deleteNode(&root);

  printf("\nCheck word deleted is present or not :");
  scanf("%s",&key);
  searchWord(root,key);

  printf("\nEnter Word You want to search :");
  scanf("%s",&key);
  searchWord(root,key);

  return 0;
}
