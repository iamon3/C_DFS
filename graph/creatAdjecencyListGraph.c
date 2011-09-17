/*
  This programme creates adjecency List Graph 
  with adjecent node containg pointer (address) of
  self node in graph
  This Programme also includes functions for vertex 
  search , insertion of new vertex in graph 
*/

//////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////

int isDirected ;

typedef struct adjecencyList
{
  struct graphNode *addressOfThisVertexIs ;
  struct adjecencyList *next;
}adjecencyList;


typedef struct graphNode
{
  int isVisited;
  int vertexNo;
  struct graphNode *next;
  struct adjecencyList *start;
}graphNode ;


graphNode *head = NULL , *tail = NULL ; 

//////////////////////////////////////////////////////////

int addNodeToAdjListOfParent(adjecencyList *new , graphNode * parentNode)
{
  adjecencyList *temp;
  temp = parentNode -> start ;
  if(!temp)
    {
      parentNode -> start = new ;
      return 0;
    }
  while(temp -> next)
    {
      if ( temp -> addressOfThisVertexIs == new -> addressOfThisVertexIs )	
	{
	  printf("\nVertex u r trying 2 insert in adjecncy List already present\n");
	  free(new);
	  return 1;
	}
      temp  = temp -> next ;
    }
  if ( temp -> addressOfThisVertexIs == new -> addressOfThisVertexIs )	
    {
      printf("\nVertex u r trying 2 insert in adjecncy List already present\n");
      free(new);
      return 1;
    }
  temp -> next = new;
  return 0;
}

/*******************************************/


adjecencyList * creatAdjecencyNode(graphNode* adjecentVertex)
{
  adjecencyList * new=NULL;

  new = ( adjecencyList * )malloc(sizeof(adjecencyList));
  new -> addressOfThisVertexIs = adjecentVertex;
  new -> next = NULL;

  return new;
}

/*******************************************/

int updateCurrentVertexAdjecency(graphNode * adjecentNode , graphNode* parentNode)
{
  adjecencyList *new;
  new =  creatAdjecencyNode( adjecentNode );
  return addNodeToAdjListOfParent(new ,parentNode);
}

//////////////////////////////////////////////////////////////////

graphNode *searchAdjecentVertexInGraph(int adjecentVertex)
{
  graphNode *temp;
  temp = head;

  while( temp )
    {
      if( (temp -> vertexNo) == vertexNo )
	{
	  printf("\nVertex Found");
	  return temp ;
	}
      temp = temp -> next;
    }

  printf("\nVertex number entered is Invalid");

  return NULL;
}

/************************************************/

void updateAdjecency(graphNode* currentVertex )
{
  char option;
  int adjecentVertex;
  graphNode * adjecentGraphVertexToBeUpdated;
  int isError=0;

  do
    {
      printf("\nIs there any adjecent vertex (Y/N) ? ");
      // option = getchar();
      scanf(" %c",&option);

      if(option == 'Y')
	{
	  printf("\nEnter Adjecent Vertex :- ");
	  scanf("%d",&adjecentVertex);

	  adjecentGraphVertexToBeUpdated = searchAdjecentVertexInGraph(adjecentVertex);

	  if( adjecentGraphVertexToBeUpdated )
	    {
	      isError = updateCurrentVertexAdjecency( adjecentGraphVertexToBeUpdated ,currentVertex );
	      if( isError == 0 && isDirected == 0 )
		{
		  updateCurrentVertexAdjecency( currentVertex ,adjecentGraphVertexToBeUpdated );
		}
	      // updateRelatedFoundVertex = ();
	    }

	}

      else if (option == 'N')
	{
	  return;
	  //	  break;
	}

      else 
	{
	  printf("\nWrong Input\n");
	}
    }  while(1)
    ;
}

////////////////////////////////////////////////////////////

void addNodeToGraph(graphNode* new)
{
  if( !head )
    {
      head = tail = new;
    }
  else 
    {
      tail -> next = new ;
      tail = new;
    }
}

/**********************************************/

graphNode * creatGraphNode(int vertexNo)
{
  graphNode * new = NULL;

  new = ( graphNode *)malloc(sizeof(graphNode));
 
  new -> isVisited = 0;
  new -> vertexNo = vertexNo ;
  new -> next = NULL;
  new -> start = NULL ;

  return new;
}

/***********************************************/

void buildGraph( int noOfVertices )
{
  int i=0;
  graphNode* new;

  for(i=0 ; i < noOfVertices ; i++)
    {
      //printf("\nEnter Values For vertex = %d\n",i+1);
      new = creatGraphNode(i+1);
      addNodeToGraph(new);
    }
  new = head ;
  while( new )
    {
      printf("\n******** This is for vertex %d *********\n",new->vertexNo);
      updateAdjecency(new);
      new = new -> next;
    }
}

////////////////////////////////////////////////////////////

void printAdjecency(graphNode *temp)
{
  adjecencyList *start ;
  start = temp -> start ;
  while(start)
    {
      printf("%d -> ",start -> addressOfThisVertexIs -> vertexNo);
      start = start -> next ;
    }
}

void printGraph()
{
  graphNode *temp;
  temp = head ;

  while( temp )
    {
      printf("%d -> ",temp->vertexNo);
      printAdjecency(temp);
      printf("NULL\n|\n");
      temp = temp -> next;
    }

}

//////////////////////////////////////

int main()
{
  int noOfVertices;

  printf("Is Directed/UnDirected (1/0) Graph ?");
  scanf("%d",&isDirected);

  printf("\nEnter No. Of vertices :- ");
  scanf("%d",&noOfVertices);

  buildGraph( noOfVertices );
  printGraph();
 
  return 0;
}

//////////////////////////////////////
