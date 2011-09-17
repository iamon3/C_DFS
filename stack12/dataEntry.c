#include<stdio.h>

void enterDataInDirectory_entry(enterDataInSuperBlockptr ptr)
{
  FILE *fp;
  fp=fopen("allData.txt","a+");

}
int main()
{
  struct Directory_entry ptr;

  enterDataInDirectory_entry(ptr);
}
