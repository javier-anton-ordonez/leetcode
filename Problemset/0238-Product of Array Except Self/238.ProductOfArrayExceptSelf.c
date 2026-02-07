#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* sol1(int* nums, int numsSize, int* returnSize) { 
  int i,j;
  returnSize=&numsSize;
  int *answer=calloc(numsSize, sizeof(int*));
  for (i=0; i<numsSize; i++ ){
    answer[i]=1;
    for (j=0; j<numsSize; j++){
      if (j==i){
        //printf("Deberia de hacer un brake\n");
        continue;
      }
      answer[i] *=nums[j];
      //printf("cuando i=%d y j=%d\n", i,j);
      //printf("en %d %d vale %d\n", i,j,arrayReturn[i]);
    }
  }

  return answer;
}
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *answer = calloc(numsSize, sizeof(int));

    // 1. Calcular productos prefix (de izquierda a derecha)
    int prefix = 1;
    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix;    // answer[i] guarda producto de todo lo anterior (izquierda)
        prefix *= nums[i];     // actualizamos el prefijo
    }

    // 2. Calcular productos suffix (de derecha a izquierda)
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;   // multiplicamos por el producto derecho
        suffix *= nums[i];     // actualizamos el sufijo
    }

    return answer;
}


int main(int argc, char *argv[])
{

  int nums[4]={1,2,3,4};
  int returnSize;
  int *arrayReturn = productExceptSelf(nums, 4, &returnSize);

  for (int i=0; i<4; i++) {
    printf("%d ", arrayReturn[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
