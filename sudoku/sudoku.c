#include<stdio.h>
#include<stdlib.h>

struct vacancies 
{ 
  int xCordinate;
  int yCordinate;
  int valuePut;
};

typedef struct vacancies vac;
vac put[100];

int **ptr;

int count=0 ;

int findEmpty(int i,int j);
int solveSudoku(int i, int j, int no);
int searchRow(int i,int j,int no,int m);
int searchCol(int i,int j,int no,int n);
int searchMat(int m,int n, int a,int b,int no);

int main(int argc,char *argv[])
{
  FILE *fp ;
  
  int i,j;
  
  fp=fopen(argv[1],"r");
  
  /*row and column size allocation */
  ptr = (int **)malloc(sizeof(int *)*9);      
  for (i=0;i<9;i++)
    {
      *(ptr+i) = (int *)malloc(sizeof(int)*9);           // col size allocation
    }

  /*scanning and printing Chars in grid */
    for(i=0;i<9;i++)
    {
      // fseek(fp,0,1);
      for(j=0;j<9;j++)
	{
	  fscanf(fp,"%d",*(ptr+i)+j);
          printf("%d\t",*(*(ptr+i)+j));
        	}
       printf("\n");
    }
    findEmpty(0,0);
    for(i=0;i<9;i++)
      {
	for(j=0;j<9;j++)
	  {
	   printf("%d\t",*(*(ptr+i)+j));
	  }
	printf("\n");
      }
    return 0;
}

int findEmpty(int i,int j)
{
  //  printf("Hi1\n");
  if(*(*(ptr+i)+j)==0)
    {
      put[count].xCordinate= i;
      put[count].yCordinate = j;
      //count+=1;
      solveSudoku(i,j,1);
    }
  if(i>=8 && j>=8)
    {
      printf("Sudoku successful \n");
      return 1;
    }
  else if(j!=8)
    {
      findEmpty(i,j+1);
    }
  else
    {
      findEmpty(i+1,0);
    }
  return 1;
}

int solveSudoku(int i, int j, int no)
{ 
  int a=i, b=j;
  //if(((searchRow(0,j,no,a)==1) || (searchCol(i,0,no,b)==1) || (searchMat(i/3,j/3,a,b,no)==1)) || (no>9))      
  printf("count= %d ,(%d,%d) = %d\n",count,i,j,no);
  if(no>9)      
    {
      printf("count =%d , (%d,%d) = %d\n",count,i,j,no);
      printf("No Greter than 9 hence backtrack\n");
      *(*(ptr+put[count].xCordinate)+put[count].yCordinate) = 0;
      count -= 1;
      printf("count =%d, (%d,%d) = %d\n",count,i,j,no);
      //*(*(ptr+put[count].xCordinate)+put[count].yCordinate) = 0;
      solveSudoku(put[count].xCordinate,put[count].yCordinate,(put[count].valuePut)+1);
      //count += 1;
      //  return 1;
      findEmpty (put[count].xCordinate,put[count].yCordinate);
      return 1;
    }

  /* if(no>9)
     return 0;*/
  //a=i;
  //b=j;

  if((searchRow(0,j,no,a)==0) && (searchCol(i,0,no,b)==0) && (searchMat(i/3,j/3,a,b,no)==0))      
    {
      *(*(ptr+i)+j)= no;
      put[count].valuePut = no;
      count+=1;
      return 1;
    }
  else
    {
      solveSudoku(i,j,no+1);
      return 1;
    }
  return 1;
}

 
int searchRow(int i,int j,int no,int a)
{
  int isFound ;
  if(i==a)
    {
      searchRow(i+1,j,no,a);
    }
  if(i>8)
    {
      return 0;
    }
  else if(*(*(ptr+i)+j)==no)
    {
      return 1;
    }
  else
    {
      isFound= searchRow(i+1,j,no,a);
    }
  if(isFound==1)
    {
      return 1;
    }
  else
    return 0;
}


int searchCol(int i,int j,int no,int b)
{
  int isFound ;
  if(j==b)
    {
      searchCol(i,j+1,no,b);
    }
  if(*(*(ptr+i)+j)==no)
    {
      return 1;
    }
  else if(j>8)
    {
      return 0;
    }
  else
    {
      isFound= searchCol(i,j+1,no,b);
    }
  if (isFound==1)
  {
    return 1;
  }
 else
   return 0;
}


int searchMat(int m,int n, int a,int b,int no)
{
  int i,j,flag=0;
  for(i=3*m;i<3*(m+1);i++)
    {
      for(j=3*n;j<3*(n+1);j++)
	{
	  if(i==a && j==b)
	    {
	      continue;
	    }
       
	  if(*(*(ptr+i)+j)==no)
	    {
	      flag=1;
	      break;
	    }
	}
    }
  return flag ;
}
