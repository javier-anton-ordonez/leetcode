#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE{
  int value;
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
NODE *Push(NODE *stack, int *val){
  NODE *nodo=malloc(sizeof(NODE));

  if(nodo==NULL){
    perror("error");
    return NULL;
  }
  nodo->value=*val;
  nodo->next=stack;

  return nodo;
}
NODE *Pop(NODE *stack, int *ret){
  *ret=stack->value;
  NODE *noderet=stack->next;
  free(stack);
  return noderet;
}
int SeeTop(NODE *stack){
  return stack->value;
}
int StackFree(NODE *stack){
  if (stack->value=='\0') {
    return 1;
  }
  else {
    return 2;
  }
}


int evalRPN(char** tokens, int tokensSize) {
  int val1;
  int val2;
  NODE *pila=CreateStack();
  for (int i =0; i<tokensSize; i++) {
    int tmp;
    if (tokens[i][0] == '+'&&strlen(tokens[i])==1) {
        pila = Pop(pila, &val1);
        pila = Pop(pila, &val2);
        tmp = val2 + val1;
        printf("%d + %d = %d\n", val1, val2, tmp);
        pila = Push(pila, &tmp);
    } 
    else if (tokens[i][0] == '-'&&strlen(tokens[i])==1) {
        pila = Pop(pila, &val1);
        pila = Pop(pila, &val2);
        tmp = val2 - val1;
        printf("%d - %d = %d\n", val1, val2, tmp);
        pila = Push(pila, &tmp);
    } 
    else if (tokens[i][0] == '/'&&strlen(tokens[i])==1) {
        pila = Pop(pila, &val1);
        pila = Pop(pila, &val2);
        tmp = val2 / val1;
        printf("%d / %d = %d\n", val1, val2, tmp);
        pila = Push(pila, &tmp);
    } 
    else if (tokens[i][0] == '*'&&strlen(tokens[i])==1) {
        pila = Pop(pila, &val1);
        pila = Pop(pila, &val2);
        tmp = val2 * val1;
        printf("%d * %d = %d\n", val1, val2, tmp);
        pila = Push(pila, &tmp);
    } 
    else {
        val1 = atoi(tokens[i]);
        pila = Push(pila, &val1);
    }
  }
  return SeeTop(pila);
}


int main(int argc, char *argv[]){
  
  char *tokens[]={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  int val=evalRPN(tokens,13);
  printf("%d\n", val);
  return 1;
}
