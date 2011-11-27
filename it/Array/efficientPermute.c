#include<stdio.h>
////////////////////////////
void printArr(int arr[],int lastElmIndex)
{
    static int cnt = 0;
  int i;
  for(i=0;i<=lastElmIndex;i++)
    {
      printf("%d ",arr[i]);
    }
  printf("    count = %d",++cnt);
  printf("\n");
}

/////////////////////////////////////////////

void swap(int arr[], int fst, int snd){
  int temp;
  temp = arr[fst];
  arr[fst]=arr[snd];
  arr[snd]=temp;
}

void palindromSwap(int arr[],int startIndex,int lastIndex){
  while(startIndex < lastIndex){
    swap(arr, startIndex, lastIndex);
    startIndex += 1;
    lastIndex -= 1;
  }
}

void sortedPermute(int arr[],int startIndex,int lastElmIndex)
{
  if( startIndex == lastElmIndex)
    {
      printArr(arr,lastElmIndex);
      return;
    }
  else
    {
      int permutNo;
      for( permutNo=1 ; permutNo<=(lastElmIndex-startIndex + 1) ; permutNo++)
	{
          sortedPermute(arr, startIndex+1, lastElmIndex);
	  if(startIndex < lastElmIndex-permutNo+1){
            swap(arr, startIndex, lastElmIndex-permutNo+1);
            palindromSwap(arr, startIndex+1, lastElmIndex);
	  }
	}
    }
}
/////////////////////////////////

void display(unsigned int *a, unsigned int j, unsigned int i, int noOfElems) {
  unsigned int x; 
   for(x = 0; x < noOfElems; x++)
      printf("%d ",a[x]);
   printf("   swapped(%d, %d)\n", j, i);
   //getch();  // Remove comment for "Press any key to continue" prompt.        
} // display()

void QuickPerm(int a[], int noOfElems) {
   unsigned int p[noOfElems];
   register unsigned int i, j, tmp; // Upper Index i; Lower Index j

   for(i = 0; i < noOfElems; i++) {  // initialize arrays; a[N] can be any type
      a[i] = i + 1;   // a[i] value is not revealed and can be arbitrary
      p[i] = 0;       // p[i] == i controls iteration and index boundaries for i
   }
   //display(a, 0, 0);   // remove comment to display array a[]
   i = 1;   // setup first swap points to be 1 and 0 respectively (i & j)
   while(i < noOfElems) {
      if (p[i] < i) {
         j = i % 2 * p[i];   // IF i is odd then j = p[i] otherwise j = 0
         tmp = a[j];         // swap(a[j], a[i])
         a[j] = a[i];
         a[i] = tmp;
         display(a, j, i, noOfElems); // remove comment to display target array a[]
         p[i]++;             // increase index "weight" for i by one
         i = 1;              // reset index i to 1 (assumed)
      } else {               // otherwise p[i] == i
         p[i] = 0;           // reset p[i] to zero
         i++;                // set new index value for i (increase by one)
      } // if (p[i] < i)
   } // while(i < N)
} // QuickPerm()

////////////////////////////

int main()
{
  int arr2[] = {1,2,3,4,5};
  //sortedPermute(arr2, 0, 4);
  QuickPerm(arr2, 5);
  return 0;
}

////////////////////////////
