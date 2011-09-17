#include<stdio.h>
#include<stdlib.h>

int count =0;

void chkSequence(char ptr[], int length);
int createStackSequence(char** ptr);

int main()
{
  char *ptr;
  int length;

  length=createStackSequence(&ptr);
  chkSequence(ptr,length);

  return 0;
}

/* void createStackSequence(char** ptr)
{
  char c;
  printf("\nDo you want insertion (Y/N) :");
  scanf(" %c",&c);

  if(c == 'Y')
    {
      char opration;

      printf("\nEnter (push-X)/(pop-X) : ");
      scanf("%s",&opration);
 
     *(ptr+count) = (char *)malloc(sizeof(char));
      count += 1;
      *(*(ptr+count)) = opration ;
      
      createStackSequence(&*ptr);
     
      return ;
    }

  else if(c=='N')
    {
      return ;
    }

  else
    {
      printf("\nWrong Input");
      createStackSequence(&*ptr);
      return ; }  return ;}
 */


int createStackSequence(char** ptr)
{
  int lengthOfSeq, i;
  char operation;

  printf("\nEnter length of sequence ");
  scanf("%d",&lengthOfSeq);
  *ptr = (char *)malloc(sizeof(char));
  printf("\nEnter (PUSH-S)/(POP-X):\n"); 

  for(i=0;i<lengthOfSeq;i++)
    {   
      scanf(" %c",&operation);
      *((*ptr)+i)= operation;
    }

  return lengthOfSeq;
}

void chkSequence(char *ptr, int length)
{
  int i,pushCount=0, popCount=0;

  for(i=0;i<length;i++)
    {
      if(*(ptr+i)=='S')
	{pushCount +=1;}

      if(*(ptr+i) == 'X')
	{popCount += 1;}

      if(pushCount < popCount)
	{
	  printf("\nWrong Sequence\n");
	  break;
	}
    }

  if(i==length)
    {
      printf("\nCorrect Sequence\n");
    }
}
