/* Check is this valid */

#include<stdio.h>
#include<string.h>

int main()
{
  
  //  char a[3]="abc";
  //  char a[3]="abc\0";
  char a[3]={'\0', 'b', 'c', 'd','e'};
  char arr[100];
  printf("%s\n",&a[1]);
  strcpy(arr,&a[1]);
  printf("%s\n",arr);
  return 0;
}
