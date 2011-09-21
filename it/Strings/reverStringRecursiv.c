/* This programme reverses string recursively */

#include<stdio.h>
#include<string.h>

void swap(char str[], int fst, int lst)
{
  char temp;
  temp = str[fst];
  str[fst]=str[lst];
  str[lst]=temp;
}

void recursiveReverseString(char str[],int fst, int lst)
{
  // if(fst != lst)
  if(fst < lst)
    {
      swap(str,fst,lst);      
      recursiveReverseString(str,fst+1,lst-1);
    }
  else {return ;} 
}

void reversewordwise(char str[],int lengthOfString)
{
  int i,j;
  j=0,i=0;
  while(i != lengthOfString+2)
    {
      if(str[i]==' '|| str[i]=='\0')
	{
	  recursiveReverseString(str,j,i-1);
	  j=i+1;
	}
 
      // printf("i=%d\tj=%d\n",i,j);
      i+=1;
    }
}

int main()
{
  char str[50];
  int lengthOfString;

  printf("\nEnter string :");
  gets(str);

  lengthOfString = strlen(str);

  recursiveReverseString(str,0,strlen(str)-1);
  puts(str);
  reversewordwise(str,lengthOfString-1);
  puts(str);
  return 0;
}
