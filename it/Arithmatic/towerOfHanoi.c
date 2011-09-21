///////////////////////////////

#include<stdio.h>

///////////////////////////////

void move(int noOfDisks , char start ,char finish ,char temp)
{
  if( noOfDisks > 0 )
    {
      move( noOfDisks-1,start ,temp,finish  );
      printf("\nMove disk %d from peg %c to %c",noOfDisks,start ,finish);
      move( noOfDisks-1,temp ,finish ,start );
    }
}
///////////////////////////////

int main()
{
  int noOfDisks ;
  char start='A' ,finish='C' ,temp='B' ;

  printf("\nEnter no of disks : ");
  scanf("%d",&noOfDisks);

  move(noOfDisks , start ,finish ,temp);
  printf("\n");
}

///////////////////////////////
