#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
  char ***returnArray;
  int i, j, w;
  int p1=0;
  int posicion1ArrayReturn = 0, posicion2ArrayReturn = 0;
  int coinciden;

  int **hashs=calloc(strsSize, sizeof(int*));
  for (i = 0;i<strsSize; i++) {
    hashs[i]=calloc(26, sizeof(int*));
  }
  for (i=0; i<strsSize; i++) { 
    for (j=0; strs[i][j]!='\0'; j++) {
      hashs[i][strs[i][j]-'a']++;
    }
  }
  //hashs[4]=calloc(26, sizeof(int*));
  //ver tabla de hashs
  
  for (i=0; i<strsSize; i++) { 
    printf("%d\t", i);
    for (j=0; j<26; j++) {
      printf("%d",hashs[i][j]);
    }
    printf("\n");
  }

  for (w=0; w<strsSize; w++) {
    for (i=0;i<strsSize;i++){
      coinciden=1;
      printf("pasa %d\n", w);
      if(w==i)
        continue;
      for (j=0; j<26; j++) {
        if(hashs[i][j]!=hashs[w][j]){
          //printf("Es distinto en la posicion %d %d %d\n", w, i, j);
          coinciden=0;
          break;
        }
      }
      if (coinciden) {
         
      }
    }
    //p1++;
  }
  //printf("%d", *returnColumnSizes[0]);
  return returnArray;
}

int main(){

  char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
  int strsSize = 6;
  int returnSize;
  int* returnColumnSizes;
  
  groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);
  return (1);
}
