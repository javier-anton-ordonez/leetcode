#include <stdio.h>

int maxArea(int *height, int heightSize){
  //Optimal way
  int max=0, current=0;

  int izq=0;
  int der=heightSize-1;
  while (izq<der) {
    if (height[izq]<height[der]) {
      current=(der-izq)*height[izq];
      if (current>max) max=current;
      izq++;
    }
    else if(height[izq]>height[der]){   
      current=(der-izq)*height[der];
      if (current>max) max=current;
      der--;
    }
    else{
      current=(der-izq)*height[der];
      if (current>max) max=current;
      der--;
      izq++;
    }
  }
  return max;
}
int maxAreaBR(int* height, int heightSize) {
  //Brute force way
  int max=0, current=0;

  for (int i=0; i<heightSize-1; i++) {
    for (int j=heightSize-1; j>i; j--) {
       
      if (height[i]<height[j]) {
        current=(j-i)*height[i];
      }
      else {   
        current=(j-i)*height[j];
      }

      if (current>max) {
        max=current;
      }
    }
  }
  return max;
}

int main(int argc, char *argv[]){

  int height[]={1,8,6,2,5,4,8,3,7};
  //int height[]={1,1};
  int area=maxArea(height, 9);
  
  printf("%d\n", area);
  return 1;
}
