#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char* s) {

  int izq=0;
  int size=0;
  char *duplicate = malloc(sizeof(char) * (strlen(s) + 1)); 
  if (duplicate == NULL) return false;

  for (int i =0; s[i]!='\0' ; i++) {
    
    if (!((s[i] >= 'a' && s[i] <= 'z') || 
      (s[i] >= 'A' && s[i] <= 'Z') || 
      (s[i] >= '0' && s[i] <= '9'))) {
      continue;
    }

    if (s[i]>'A' && s[i]<'Z') {
      s[i]=s[i]+32;
    }
    duplicate[size]=s[i];
    size++;
  }
  size-=1;
  for (;izq<size;izq++) {
    if(duplicate[izq]!=duplicate[size]){
      free(duplicate);
      return false;
    }
    size-=1;
  }
  
  free(duplicate);
  return true;
}
int main(){
  
  char s[]="A man, a plan, a canal: Panama";
  int ret=isPalindrome(s);
  
  if (ret) {
    printf("Palindromo\n");
  }
  else {
    printf("No Palindromo\n");
  }

  return EXIT_SUCCESS;
}
