#include<stdio.h>

char input[15],output[15],stack[15];
int inputTop=0,stackTop=-1,outputTop=0,way[15];

int push(char item, char bucket[], int *top);
char pop(char bucket[], int *top);
void checkCombination();

int main()
{
  int inputLength,outputLength;
  printf("Enter length of input and output :\n");
  scanf("%d%d",&inputLength ,&outputLength);

  printf("Enter input elements :\n");
  for(inputTop=0;inputTop<inputLength;inputTop++)
    {
      scanf(" %c",&input[inputTop]);
    }

  printf("Enter output elements :\n");
  for(outputTop=0;outputTop<outputLength;outputTop++)
    {
      scanf(" %c",&output[outputTop]);
    }
  checkCombination();
  return 0;
}

void checkCombination()
{
  int i,j, k,m=0;
  i=j=0;
  while((i<outputTop)&&(j<inputTop))
    {
      if(output[i]==stack[stackTop])
	{
	  pop(stack,&stackTop);
	  way[m]=0;	 
	  m+=1;
	  i++;
	}
      else if(output[i]==input[j])
	{
	  push(input[i],stack,&stackTop);
	  way[m]=1;
	  m+=1;
	  pop(stack,&stackTop);
	  way[m]=0;
	  m+=1;
	  j++;
	  i++;
	}
      /*else if(output[i]==stack[stackTop])
	{
	  pop(stack,&stackTop);
	  }*/
      else
	{
	  push(input[j],stack,&stackTop);
	  way[m]=1;
	  m+=1;
	  j++;
	}
    }
  if(stackTop==-1)
    {
      printf("Possible\t%d\t%d\n",m,stackTop);

      printf("Push =1 \t Pop=0\n");

      for(k=0;k<m;k++)
	{
	  printf("%d\t",way[k]);
	  if(way[k]==1)
	    {printf("push\n");}
	  else{printf("pop\n");}
	}
      printf("\n");
    }
  else
    {
      printf("Not Possible%d\n",stackTop);
    }
}

int push(char item, char bucket[], int *top)
{
  /*if(top==MAXSTK)
    {printf("Overflow :\n"); return ;}
    else*/
  { *top+=1; bucket[*top]=item ;  return 0;}
}

char pop(char bucket[], int *top)
{
  char item;
  /*  if(top==0)
    {printf("Underflow :\n");return ;}
    else*/
    {  item = bucket[*top]; *top-=1 ; return item;}
}
