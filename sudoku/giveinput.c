/* With this file U can create  input file as an command line argument to main sudoku file*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *fp;
  char chr;
  fp=fopen("input.txt","w");
  printf("Enter values in sudoku matrix :\n");
  while((chr=getchar())!=EOF)
    {
      putc(chr,fp);
    }
  fclose(fp);
  return 0;
}
