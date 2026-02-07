#include <stdio.h>
int trap(int* height, int heightSize) {
  if (heightSize==0) {
    return 0;
  }
  int water=0;
  int izq=0;
  int der=heightSize-1;
  int maxizq=height[izq];
  int maxder=height[der];
  while (izq<der) {
    if (maxizq<maxder) {
      izq+=1;
      if (maxizq<height[izq])
        maxizq=height[izq];
      water+=maxizq-height[izq];
    }
    else{
      der-=1;
      if (maxder<height[der])
        maxder=height[der];
      water+=maxder-height[der];
    }
  }
  return water;
}

int main(int argc, char *argv[])
{
  int height[]={0,1,0,2,1,0,1,3,2,1,2,1};
  int heightSize=12;
  int resultado=trap(height, heightSize);
  printf("%d\n", resultado);
  return 1;
}
