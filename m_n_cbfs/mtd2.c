#include<stdio.h>
#include<stdlib.h>

char **ptr;
int row, col ,count=0;

struct tree
{
  int child_x;
  int child_y;
  int parent_x;
  int parent_y;
}path[100];

struct queue
{
  int x_cord;
  int y_cord;
 struct queue *next;
};
 
typedef struct queue queue;
 
queue *front=NULL; 
queue *rear=NULL;

void printPath(void);
void nq(int current_i,int current_j,int x,int y);
queue * dq();
int chkchees(int x, int y);
int findCheese(void);


int main(int argc,char *argv[])
{
  FILE *fp ;
  int i,j, moi, moj, chei, chej;
  int flagmouse=0 , flagches=0;
  //**ptr;
  fp=fopen(argv[1],"r");
  
  /*row and column dimensions calculated */
  fscanf(fp,"%d%d",&row,&col);
  
  /*row and column size allocation */
  ptr = (char **)malloc(sizeof(char *)*row);      
  for (i=0;i<row;i++)
    {
      *(ptr+i) = (char *)malloc(sizeof(char)*col);           // col size allocation
    }

  /*scanning and printing Chars in grid */
    for(i=0;i<row;i++)
    {
      fseek(fp,1,1);
      for(j=0;j<col;j++)
	{
	  fscanf(fp,"%c",*(ptr+i)+j);
          printf("%c",*(*(ptr+i)+j));
	  if(*(*(ptr+i)+j)=='c')
	    {
	      //**ches=*(*ptr+i)+j;
	      chei=i;
	      chej=j;
              flagches=1;
	      //printf("ches  %d\t%d\n\n",i,j);   
	    }
          if(*(*(ptr+i)+j)=='m')
             {
	       // **mouse=*(*ptr+i)+j;
	        moi=i;
	        moj=j;
	        flagmouse=1 ; 
               //printf("mouse %d\t%d\n\n",i,j);
	    }
       	}
       printf("\n");
    }
    
    if (flagmouse==0 && flagches==0)
      {
	printf("Mouse and Cheese both Not Present :\n"); 
      }
    else if(flagmouse==0)
      {
	printf("Mouse Not Present :\n"); 
      }
    else if ( flagches==0)
      {
	printf("Chease Not Present :\n");
      }
    else 
      {
	printf("\nmouse %d\t%d\n\n",moi,moj);
	printf("ches  %d\t%d\n\n",chei,chej);
	
	nq(moi,moj,moi,moj);
	
	findCheese();

      }
    return 0;
}


int findCheese(void)
{
  // printf("Hi1\n");
  int flag=0;
  int current_i,current_j;
  queue *dequed;
 
  dequed = dq();
  //printf("Hi2\n");
  current_i = (dequed) -> x_cord;
  current_j = (dequed) -> y_cord;
  //printf("Hi3\n");
  free(dequed);
  printf("%d %d\n",current_i,current_j);
  *(*(ptr+current_i)+current_j)=='w';

  if(((current_j+1)< col) && *(*(ptr+current_i)+current_j+1)!='w')                                 // right direction
    {
      nq(current_i,current_j+1,current_i,current_j);
      printf("Hi4\n");
      if( chkchees(current_i,current_j+1) )
	return 1;
    }
  
  if(((current_j-1)>=0) && *(*(ptr+current_i)+current_j-1)!='w')                                   // for left direction
    {
      nq(current_i,current_j-1,current_i,current_j);
      printf("Hi5\n");
      if ( chkchees(current_i,current_j-1) )
	return 1;
    }
  
  if(((current_i+1)< row) && *(*(ptr+current_i+1)+current_j)!='w')                                 // for down direction
    {
      nq(current_i+1,current_j,current_i,current_j);
      printf("Hi6\n");
      if ( chkchees(current_i+1,current_j) )
	return 1;
    }

  if ( ( (current_i-1) >= 0 )  && *(*(ptr+current_i-1) +current_j ) != 'w' )                       // for up direction
    {
      nq(current_i-1,current_j,current_i,current_j);   
      printf("Hi7\n");
      if ( chkchees(current_i-1,current_j) )
	return 1;
    }

  printf("Hi8\n");
  if (front==NULL && rear == NULL)  
    {
      printf("Hi9\n");
      return 0;
    }
  //printf("Hi10\n");
  flag = findCheese();
    
  if(flag)
    {
      printf("Path is found :\n");
      printPath();
    }  
  else
    printf("Path is not possible :\n");
}
  

void nq(int current_i,int current_j,int x,int y)
{
  queue* new;
  new =(queue *) malloc(sizeof(queue));
  new -> x_cord = current_i;
  new -> y_cord = current_j;
  new -> next = NULL;

  /*if(rear == NULL && front == NULL)
    {
     rear = front = new;
    }
  else if(front == NULL && rear != NULL)
    {
      
      front = rear;
      rear -> next = new ;
      rear = new;
    }
  else
    {
      rear -> next = new ;
      rear = new;
      }*/

  if(rear == NULL)
    {
      front = rear = new;
    }
  else
    {
      rear -> next = new;
      rear = new;
    }
  //printf("wer");
  path[count].child_x=current_i;
  path[count].child_y=current_j;
  path[count].parent_x = x;
  path[count].parent_y = y;
  count += 1;
}

queue * dq(void)
{
  queue *temp;

  /*if( front ==NULL && rear==NULL )
    {
      return front;
    }
  else  if( front == rear ) 
    { 
      temp = front;
      //front = front -> next;
      rear = front = NULL;
      return temp;
    }
  else
    {
      temp = front;
      front = front -> next;
      return temp; 
      }*/

  if(front == rear)
    {
      temp = front;
      front = rear = NULL;
      return temp;
    }

  else
    {
      temp = front;
      front = front -> next;
      return temp;
    }

}


int chkchees(int x, int y)
{
  if( *(*(ptr+x)+y) == 'c' )
    return 1;
  else 
    return 0;
}


void printPath(void)
{
  int i,x,y;
  count -= 1;

  x=path[count].child_x;
  y=path[count].child_y;
  printf("Chees -> ");

  for(i=count;i>=0;i--)
    {
      if( (x==path[i].child_x) && (y==path[i].child_y) )
	{
	  printf("( %d , %d ) -> ",x,y);
	  x=path[i].parent_x;
	  y=path[i].parent_y;
	}
    }

  printf(" Mouse");
  printf("\n");
}
