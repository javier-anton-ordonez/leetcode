#include <stdlib.h>
#include <stdio.h>



int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

  *returnSize=2;
  int *ret=(int*) malloc(2*sizeof(int));
  int der = numbersSize-1;
  int izq = 0;

  while (der>izq) {
    if (numbers[izq]+numbers[der]==target) {
      ret[0]=izq+1;
      ret[1]=der+1;
      return ret;
    }
    else if (numbers[izq]+numbers[der]>target) {
      der--;
    }
    else{
      izq++;
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int numbers[7] = {1,2,3,4,5,6,7};
  int retSize;
  int *ret=twoSum(numbers,7,8,&retSize);

  for (int i=0;retSize>i ; i++) {
    printf("%d\t", ret[i]);
    fflush(stdout);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
