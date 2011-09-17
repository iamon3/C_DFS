#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////////

struct adjecent
{
  int vertex;
  struct graphNode *equalVertex;
};

struct graphNode
{
  int visited;
  int noOfAdjVer;
  struct adjecent *adjList;
};

typedef struct adjecent adjecent;
typedef struct graphNode graphNode;

///////////////////////////////////////////////////

int unVisitAllVertices(graphNode *head,int noOfVertices)
{
  int i;
  for(i=0;i<noOfVertices;i++)
    {
      if(head[i].visited == 0)
	{
	  return 0;
	}
      head[i].visited = 1 ;
    }
  return 1;
}

///////////////////////////////////////////////////

/* void isVertexConnectedToAllVertices(graphNode *head,int vertex,int noOfVertices) */
/* { */
/*   if(!head[vertex].visited) */
/*     { */
/*       int i; */
/*       head[vertex].visited = 1 ; */

/*       for(i=0;i<head[vertex].noOfAdjVer;i++) */
/* 	{ */
/* 	  //  isVertexConnectedToAllVertices( head[vertex].adjList[i].equalVertex ,vertex ,noOfVertices);	} */
/* 	  isVertexConnectedToAllVertices( head[vertex].adjList[i].equalVertex ,head[vertex].adjList[i].vertex ,noOfVertices); */
/* 	} */
/*     } */
/*   return; */
/* } */

void isVertexConnectedToAllVertices(graphNode *head,int noOfVertices)
{
  if(!head -> visited)
    {
      int i;
      head -> visited = 1 ;

      for(i=0;i<head -> noOfAdjVer;i++)
	{
	  //  isVertexConnectedToAllVertices( head[vertex].adjList[i].equalVertex ,vertex ,noOfVertices);	}
	  isVertexConnectedToAllVertices( head -> adjList[i].equalVertex ,noOfVertices);
	}
    }
  return;
}


///////////////////////////////////////////////////

void checkConnectivity(graphNode *head,int noOfVertices)
{
  int i,flag;

  for(i = 0 ;i < noOfVertices ; i++)
    {
      //isVertexConnectedToAllVertices(head,i,noOfVertices);
      isVertexConnectedToAllVertices( head+i , noOfVertices);

      if((flag =unVisitAllVertices(head,noOfVertices) )== 0)
	{
	  printf("Disconnected Graph.\n");
	  return;
	}
    }

  printf("Connected Graph\n");
  return ;
}

///////////////////////////////////////////////////

void creatAdjList(int noOfVertices)
{
  graphNode *head,*saveHead;
  //  adjecent *adj,*saveAdj;
  int i,j;

  head = (graphNode*)malloc(sizeof(graphNode)*noOfVertices);
  saveHead = head;

  //printf("Enter 0 if no adj vertices their \n");
  for(i=0;i<noOfVertices;i++)
    {
      head[i].visited = 0;
      head[i].adjList = NULL;

      printf("\nNo. Of Adj vertices for V%d := ",i);
      scanf("%d",&(head[i].noOfAdjVer));

      if(head[i].noOfAdjVer != 0)
	{
	  head[i].adjList = (adjecent*)malloc(sizeof(adjecent)*(head[i].noOfAdjVer));
	  j=0;
	  while(j != (head[i].noOfAdjVer))
	    {
	      printf("\nEnter adjecent V%d vertex value : ",i);
	      scanf("%d",&head[i].adjList[j].vertex);
	      head[i].adjList[j].equalVertex = &head[head[i].adjList[j].vertex];
	      j++;
	    }
	}
      else
	{
	  printf("Disconnected Graph :\n");
	  return ;
	}
    }

  checkConnectivity(head,noOfVertices);
}
///////////////////////////////////////////////////

int main()
{
  int noOfVertices;

  printf("\nEnter n of vertices :");
  scanf("%d",&noOfVertices);
  creatAdjList(noOfVertices);
  return 0;
}

///////////////////////////////////////////////////
