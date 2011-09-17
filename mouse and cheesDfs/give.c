	#include<stdio.h>
int main()
{
 FILE *fp;
 char c;
 fp=fopen("input.txt","w");
 printf("Enter Data \n");
 while((c=getchar())!=EOF)
   {
     putc(c,fp);
   }
 fclose(fp);
 return 0;
}

