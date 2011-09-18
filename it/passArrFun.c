#include<stdio.h>

void printArr(int* arr ,int row, int col){
  int i,j;
  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      printf("%d ",arr[i*col + j]);
    }
    printf("\n");
  }
}

int main(){
  int x=3, y=4;
  int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
  printArr(&arr[0][0], x, y);
  return 0;
}
