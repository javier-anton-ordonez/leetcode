/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int** ret = malloc(numsSize * 2 * sizeof(int*));
    *returnColumnSizes = malloc(numsSize * 2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Evitar duplicados

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            if (nums[i] + nums[left] + nums[right]< 0){
                left++;
            } else if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else {

                ret[*returnSize] = malloc(3 * sizeof(int));
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
        }
    }
    return ret;
}



int main(int argc, char *argv[]){

  int nums[]={-1,0,1,2,-1,-4};
  int numsSize=6;
  int returnSize=0;
  int *returnColumnSizes;
  int **returned=threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
  
  for (int i=0;i<returnSize;i++){
    for(int j=0;j<3; j++){
      printf("%d ", returned[i][j]);
    }
    printf("\n");
  }
  return 1;
}
