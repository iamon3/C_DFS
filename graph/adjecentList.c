
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct graphNode
{
  int vertex;
  struct graphNode *next;
  struct adjecentVertices* adjecent;
};
typedef struct graphNode graphNode;


struct adjecentVertices
{
  int vertex;
  int weightFromOriginalVertex;
  //  struct graphNode *dummyOfVertexInList;
  struct adjecentVertices* adjecent;
};
typedef struct adjecentVertices adjecentVertices;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adjecentVertices* creatAdjecentVertice(void)
{
  int vertex=1,weight;
  adjecentVertices *start=NULL , *saveStart=NULL, *new=NULL;

  while(1)
    {
      printf("\nEnter adjecent vertex and weight(0,0 for to stop):");
      scanf("%d%d",&vertex,&weight);

      if(vertex == 0)
	{
	  break;
	}  

      new = (adjecentVertices *) malloc (sizeof(adjecentVertices));
      new -> vertex = vertex ;
      new -> weightFromOriginalVertex = weight;
      new -> adjecent = NULL;

      if( start == NULL )
	{
	  start = saveStart = new;
	}

      else
	{
	  start -> adjecent = new; 
	  start = start -> adjecent;
	}
      
      //      printf("\nEnter adjecent vertex and weight(-1,-1 for to stop):");
      //     scanf("%d%d",&vertex,&weight);
    }
  start = saveStart;
  /*  while(start)
    {
      printf("%d -> ",start -> vertex);
      start = start -> adjecent;
      }*/
  return saveStart;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int printMenu(void)
{
  int option;

  printf("######################### MENU ###############################\n");
  printf("\nSelect Option\n");
  printf("1)Insert Vertex\n2)Insert Edge\n3)Delete Vertex\n4)Delete Edge\n");
  printf(" \nOption: ");
  scanf("%d",&option);

  return option;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printVertices(graphNode* start)
{
  adjecentVertices* adjstart;

  while(start)
    {
      printf("%d -> ",start -> vertex);
      adjstart = start -> adjecent;

      while(adjstart)
	{
	  printf("%d -> ", adjstart -> vertex);
	  adjstart = adjstart -> adjecent;
	}
      printf("NULL\n|\n");
      start = start -> next;
    }
  printf("Done \n");
  printMenu();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void insertVertex(graphNode **start)

{  
      int vertex;
      graphNode *new=NULL , *saveStartVertex=NULL;
      saveStartVertex = *start;

      printf("\nEnter New Vertex To be inserted :");
      scanf("%d",&vertex);

      new =(graphNode *) malloc(sizeof(graphNode));
      new -> vertex = vertex;
      new -> adjecent = (adjecentVertices *)creatAdjecentVertice();
     
      if(!(*start))
	{
	  saveStartVertex = (*start) = new ;
	}
      else
	{
	  while((*start)-> next)
	    {
	      (*start) = (*start) -> next ;
	    }
	  (*start) -> next = new; 
	}
      (*start) = saveStartVertex ;
      printVertices(*start);  
  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adjecentVertices* deleteAdjency(adjecentVertices** start, int vertex)
{
  adjecentVertices *saveStart, *deleteAdjecent;
  saveStart = *start;

  if((*start) && ((*start) -> vertex == vertex))
    {
      (*start) = (*start) -> adjecent;
      free(saveStart);
    }

  else
    {
      while(*start)
	{
	  if( (*start) -> vertex == vertex )
	    {
	      deleteAdjecent = *start;
	      (*start) = (*start) -> adjecent;

	      free(deleteAdjecent);
	      break;
	    }

	  (*start) = (*start) -> adjecent;
	}

       (*start) = saveStart;
    }

  return (*start);
}


graphNode* deleteVertex(graphNode** start)
{
  int vertexToBeDeleted ;
  graphNode *deleteVertex ,*saveStart, *prev;

  printf("\nEnter Vertex To be deleted : ");
  scanf("%d",&vertexToBeDeleted);

  if(!*start)
    {
      printf("No vertex present\n");
      return *start;
    }

  else
    {
      saveStart = (*start);
      //printf("Hi1\n");      
      if( (saveStart -> vertex) == vertexToBeDeleted )
	{
	  deleteVertex = saveStart ;
	  saveStart = saveStart -> next;
	  (*start) = prev = saveStart;
	}
      //      printf("Hi2\n");      

      while((*start))
	{
	  //	  printf("Hi3\n");
	  prev = (*start);
	  (*start) = (*start) -> next;
	  prev -> adjecent = deleteAdjency(&(prev-> adjecent),vertexToBeDeleted);
	  //printf("Hi4\n");     

	  if((*start) && (*start) -> vertex == vertexToBeDeleted )
	    {
	      deleteVertex = (*start);
	      prev -> next = (*start) -> next ;
	      (*start) = (*start) -> next;
	      //      printf("Hi5\n");     
	    }
	  printVertices(saveStart);  
	}

      //  printf("Hi6\n");
      free(deleteVertex);     
    } 
 
  printVertices(saveStart);  
  //printf("Hi7\n");
  return saveStart;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

graphNode* creatAdjecencyList(graphNode **start)
{
  graphNode *saveStartVertex=NULL;

  int noOfVertices,i,vertex;

  printf("Enter total no of vertices : ");
  scanf("%d",&noOfVertices);
  (*start) =(graphNode *)malloc(sizeof(graphNode)*noOfVertices);

  for(i=0;i<noOfVertices;i++)
    {
      printf("\nEnter vertex %d:",i+1);
      scanf("%d",&vertex);

      ((*start)+i)->vertex = vertex;
      ((*start)+i)->adjecent = creatAdjecentVertice();

      if(i<noOfVertices-1)
	{
	  ((*start)+i)->next = ((*start)+i+1);
	}
      else
	{
	  ((*start)+i)->next = NULL;
	}
    }
  (*start) = ((*start)+0);

  printVertices(*start);
  return (*start);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  
  graphNode* start=NULL;
  /* For iterative creation */
  start = creatAdjecencyList(&start);
    
  insertVertex(&start);  
  start = deleteVertex(&start);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
