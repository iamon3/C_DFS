#include<stdio.h>
#include<stdlib.h>

int move(int row , int col, int m,int n, char **);
int main(int argc,char *argv[])
{
  FILE *fp ;
  char **ptr;
  
  int row, col,i,j, moi, moj, chei, chej ;
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
	      chei=i;
	      chej=j;
	    }
          if(*(*(ptr+i)+j)=='m')
             {
	        moi=i;
	        moj=j;
	    }
       	}
       printf("\n");
    }

   printf("\nmouse %d\t%d\n\n",moi,moj);
   printf("ches  %d\t%d\n\n",chei,chej);
   printf("Indices starting from Cheese toward mouse are :\n");

  move( row, col, moi, moj, ptr); 
  printf("\n");
  /* print grid 
  for(i=0;i<row;i++)
    {
      fseek(fp,1,1);
      for(j=0;j<col;j++)
	{
	  printf("%c",*(*(ptr+i)+j));
	}
      printf("\n");
      } */
  
    return 0;
}

int move(int row, int col, int m,int n, char **ptr)
{
  //printf("(%d ,%d)\n",m, n);
if(m < 0 || n<0 || m>= row || n>=col)
  {
    return 0;
  }
  if(*(*(ptr+m)+n)=='c')
    {
      printf("(%d ,%d)\n",m, n);
      return 1;
    }
  if(*(*(ptr+m)+n)=='w')
    {
      return 0;
    }
 
  *(*(ptr+m)+n)='w';
  int isfound =( move( row,col,(m-1), n, ptr) || move( row,col,(m+1), n, ptr)|| move( row,col,m, (n+1), ptr) || move( row,col,m, (n-1), ptr) );
   
  if (isfound) 
    printf("(%d ,%d)\t",m, n);
    *(*(ptr+m)+n)='|';
  return isfound ;
   }
