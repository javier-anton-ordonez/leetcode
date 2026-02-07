#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
/*
  idx=nums[0];
  for (i=1; i<numsSize; i++) {
    //printf("%d", idx);
    if (idx+1==nums[i]) {
      idx=nums[i];
      length++;
    }
    else {
      if (length>1) {
        return length;
      }
      else {
        idx=nums[i];
        length=1;
      }
    }
  }
*/
int cmp(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {

  if (numsSize==0) {
    return 0; 
  }
  int length=1, lengthmax=1;
  qsort(nums, numsSize, sizeof(int), cmp);
  
  //-1 -1 0 1 3 4 5 6 7 8 9 
  for (int i=1; i<numsSize; i++) {
      switch (nums[i] - nums[i - 1]) {
        case 1: 
          length++;
          break;
        case 0: 
          break;
        default:
          if (lengthmax < length)
            lengthmax = length;
          length = 1;
          break;
      }
  }
  if (lengthmax < length)
    lengthmax = length;

  return (lengthmax);
}

int main(int argc, char *argv[])
{
  int nums[]={9,1,4,7,3,-1,0,5,8,-1,6};
  //int nums[]={};
  
  printf("%d\n", longestConsecutive(nums, 11));

  return 0;
}
