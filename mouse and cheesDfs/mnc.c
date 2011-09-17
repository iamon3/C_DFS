#include<stdio.h>
#include<stdlib.h>


char **ptr;
int row, col ,count=0;

struct travelledPath
{
  int mrow;
  int mcol;
  int position;
}path[50];

//int move(int row , int col, int m,int n, char **);


int backtrack(void);
int findCheese(int m, int n);


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
	//move(row, col, moi, moj, ptr);
	findCheese(moi,moj);

	/*	printf("(%d , %d ) -> ",moi,moj);
	for(i=1;i<count;i++)
	  {
	    printf("(%d , %d ) -> ",path[i].mrow, path[i].mcol);
	  }
	  printf("Cheese Found . Hee Hee !!!\n\n");*/
      }
    return 0;
}

int findCheese(int m, int n)
{
  path[count].mrow = m ; 
  path[count].mcol = n ; 
  path[count].position = count ; 
  count += 1;
  printf("(%d ,%d ) count = %d\n" ,m ,n,count);

  if(*(*(ptr+m)+n) =='c')                                                 // if chese found print successful
    {
      printf("Cheese found \n");
      return 1;
    }

  if (count<=0)
    {printf("Path not possible.\n"); return 0;}                  
  
  if((n+1<col) && (*(*(ptr+m)+n+1)!='w'))                                 // Default direction : if right direction not blocked go right
    {
      *(*(ptr+m)+n)='w'; 
      findCheese(m,n+1);
    }
  
  else if((n-1>=0) && (*(*(ptr+m)+n-1)!='w'))                             // if right direction blocked go left
    {
      *(*(ptr+m)+n)='w'; 
      findCheese(m,n-1);
    }
  
  else  if((m+1 < row) && (*(*(ptr+m+1)+n)!='w'))                         // if left direction blocked  go down
    {
      *(*(ptr+m)+n)='w';
      findCheese(m+1,n);
    }
  
  else if((m-1>=0) && (*(*(ptr+m-1)+n)!='w'))                            //  if down direction blocked go up direction
    {
      *(*(ptr+m)+n)='w';
      findCheese(m-1,n);
    }

  else                                                                                   // if there is no way then backtrack 
    {
      printf("Travelled path not possible . Hence backtrack .\n"); 
      backTrack(); 
      findCheese(path[count].mrow, path[count].mcol);
    }   

  if (count<=0)
    {printf("Path not possible.\n"); return 0;}
}

int backTrack(void)                                     // make current position = 'w' go to prev location of travelled path and make it 'e' and then find path .
{
  count-=1;
  *(*(ptr+path[count].mrow)+path[count].mcol)='w';
  count-=1;
  *(*(ptr+path[count].mrow)+path[count].mcol)='e';
  return 0;
}


/*int move(int row, int col, int m,int n, char **ptr)
{

  if(m<0 || n<0 || m>= row || n>=col)
    return 0;
  printf("(%d , %d) \n",m ,n);  
  if(*(*(ptr+m)+n)=='c')
    {
      printf("(%d , %d).... \n",m ,n);
      return 1;
    }
  if (*(*(ptr+m)+(n+1))=='e')
    {
      *(*(ptr+m)+n)='w';
      if(move(row,col,m,(n+1),ptr)  == 1)
	{
	  printf("(%d , %d)... \n",m ,n);
	  return 1;
	}
    }
  else if((*(*(ptr+m)+n+1)=='w')|| ((n+1)==col))
    {
      printf("Hi5");
      
      if(move( row,col,(m+1), n, ptr) == 1)
	{
	  printf("(%d , %d)... \n",m ,n);
	  return 1;
	}
    }
  else if(*(*(ptr+m+1)+n)=='w'|| (m+1)==row )
    {
      printf("Hi4");
      
      if(move(row, col,m ,(n-1), ptr) == 1)
	{
	  printf("(%d , %d)... \n",m ,n);
	  return 1;
	}
    }
  else  if((n<0) && (*(*(ptr+m)+(n-1))=='w' || (n)!=0 ))
    {
      printf("Hi3");
      move( row, col,(m-1), n, ptr);
    }
  else if((m < 0) && (*(*(ptr+m-1)+n)=='w'|| (m!=0)))
    {
      printf("Hi2");
      move(row, col, m ,(n+1), ptr);
    }
  else 
    {
      printf("Hi1");
      *(*(ptr+m)+n)='w' ;
      move(row, col, m ,(n+1), ptr);
    }
  
  return 0;
}*/

  

