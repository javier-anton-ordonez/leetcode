#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LETRAS 23

bool isAnagram(char* s, char* t) {
  int i=0;
  if(strlen(s)!= strlen(t))
    return(0);

  int *letras=calloc(26, sizeof(int));
  int *letrat=calloc(26, sizeof(int));

  
  for(;i<strlen(s); i++){
    printf("%d\t%d\n", s[i]-97, t[i]-97);
    //getchar();
    letras[s[i]-97]+=1;
    letrat[t[i]-97]+=1;
  }

  for(i=0; i<26; i++){ 
    
    if(letrat[i]!=letras[i]){
      free(letras);
      free(letrat);
      return false;
    }
  }
  free(letrat);
  free(letras);
  return true;
 
}

int main()
{
  char *s="ccac";
  char *t="aacc";
  if(isAnagram(s, t))
    printf("\nTrue\n");
  else
    printf("\nfalse\n");
  return (0);
}
