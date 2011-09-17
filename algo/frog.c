#include<stdio.h>

int countNoOfWays(int n);

int main()
{
  int noOfWays,noOfSteps;

  printf("\nEnter No of steps :");
  scanf("%d",&noOfSteps);

  noOfWays=countNoOfWays(noOfSteps);
  printf("\nTotal possibal ways are :%d\n",noOfWays);

  return 0;
}

int countNoOfWays(int n)
{
  int oneStepWays ,twoStepWays , threeStepWays ;

  if(n==0)
    {
      return 0;
    }

  if(n==1)
    {
      return 1;
    }

  if(n==2)
    {
      return 2;
    }

  if(n==3)
    {
      return 4;
    }

  oneStepWays = countNoOfWays(n-1);
  twoStepWays = countNoOfWays(n-2);
  threeStepWays = countNoOfWays(n-3);

  return ( oneStepWays + twoStepWays + threeStepWays );
}
