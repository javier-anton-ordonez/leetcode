#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _NODE{
  char value;
  struct _NODE *next;
} NODE;

NODE *CreateStack(){
  NODE *Stack=malloc(sizeof(NODE));
  if (Stack==NULL) {
    perror("Error al alocar memoria");
  }
  Stack->value='\0';
  Stack->next=NULL;
  return Stack;
}
NODE *Push(NODE *stack, char *val){
  NODE *nodo=malloc(sizeof(NODE));

  if(nodo==NULL){
    perror("error");
    return NULL;
  }
  nodo->value=*val;
  nodo->next=stack;

  return nodo;
}
NODE *Pop(NODE *stack){
  NODE *noderet=stack->next;
  free(stack);
  return noderet;
}
char SeeTop(NODE *stack){
  return stack->value;
}
bool StackFree(NODE *stack){
  if (stack->value=='\0') {
    return true;
  }
  else {
    return false;
  }
}
bool isValid(char* s) {
  if(strlen(s)<2){
    printf("O 0 o 1 elemenotos\n");
    return false;
  }

  NODE *Stack=CreateStack(); 
  for (int i=0; s[i]!='\0';i++) {
    printf("Stack: %c\tS[i]: %c\n", SeeTop(Stack), s[i]);
    if (StackFree(Stack)) {
      Stack=Push(Stack, &s[i]);
    }else {
      switch (s[i]) {
        case '(':
        case '[':
        case '{':
          Stack=Push(Stack, &s[i]);
          break;
        case ')':
          if (SeeTop(Stack)=='(') {
            Stack=Pop(Stack);
          }
          else {
            printf("Stack:%c\ts[i]: %c\n",SeeTop(Stack),s[i]);
            return false;
          }
          break;
        case ']':
          if (SeeTop(Stack)=='[') {
            Stack=Pop(Stack);
          }
          else {
            printf("Stack:%c\ts[i]: %c\n",SeeTop(Stack),s[i]);
            return false;
          }
          break;
        case '}':
          if (SeeTop(Stack)=='{') {
            Stack=Pop(Stack);
          }
          else {
            printf("Stack:%c\ts[i]: %c\n",SeeTop(Stack),s[i]);
            return false;
          }
          break;
      }
    }
  }
  
  return !StackFree(Stack);
}

int main(int argc, char *argv[]){

  char *strin="((";
  int stacklen=isValid(strin);

  if (!stacklen) {
    printf("TRUE %s\n", strin);
  }
  else{
    printf("FALSE %s\n", strin);
  }

  return 1;
}
