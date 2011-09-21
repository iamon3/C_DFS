/* This programme prints output as programme itself 
   without using file handling function like fprintf fscanf etc*/

#include<stdio.h>
#include<fcntl.h>

int main()
{
  int fp;
  char ptr[500];

  fp = open("printCode.c",O_RDWR);

  while(read(fp,ptr,500) > 0)
    {           
      printf("%s",ptr);
    }
   
  return 0;
}
