#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

bool containsDuplicateMio(int* nums, int numsSize)
{
  qsort(nums, numsSize, sizeof(int), cmp); 

  for (int i = 1; i < numsSize; i++)
    if (nums[i] == nums[i-1]) // No puede ser -1 por que si no se compara y luego se resta
          return true;

  return false;
}
bool containsDuplicate(int* nums, int numsSize) {
   
  int min = nums[0];
  int max = nums[0];

  for(int i = 0; i < numsSize; i++) {
    if(min > nums[i]) min = nums[i];
    if(max < nums[i]) max = nums[i];
  }

  printf("max: %d\n", max);
  printf("min: %d\n", min);

  int capacity = max - min + 1;
  printf("capacity %d\n", capacity);
  int *hashmap = calloc(capacity, sizeof(int));
    
  for(int i = 0; i < numsSize; i++){
    if(hashmap[nums[i]-min] >= 1) {
      free(hashmap);
      return true;
    }

    hashmap[nums[i]-min]++;    
  }
  return false;

}

int main(){
  int numsSize = 10;
  int *nums = malloc(sizeof(int)*numsSize);

  nums[0]=0;
  nums[1]=1;
  nums[2]=2;
  nums[3]=3;
  nums[4]=4;
  nums[5]=5;
  nums[6]=6;
  nums[7]=7;
  nums[8]=8;
  nums[9]=9;
  bool valor=containsDuplicate(nums, 10);

  for(int i=0; i<numsSize; i++){
    printf("%d\n", nums[i]);
  }
  if(valor == 1)
    printf("TRUE\n");
  else
    printf("FALSE\n");

  return (0);
}
