#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int carry = 0;

  // Creamos un dummy node para que ret apunte fijo al inicio
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  if (dummy == NULL) {
      return NULL;
  }

  struct ListNode *actual = dummy;

  // Mientras haya nodos o carry pendiente
  while (l1 != NULL || l2 != NULL || carry) {
      int v1 = (l1 != NULL) ? l1->val : 0;
      int v2 = (l2 != NULL) ? l2->val : 0;

      int sum = v1 + v2 + carry;
      carry = sum / 10;

      // Creamos el nuevo nodo (no pisamos memoria como antes)
      actual->next = malloc(sizeof(struct ListNode));
      if (actual->next == NULL) {
          return NULL;
      }

      actual = actual->next;
      actual->val = sum % 10;
      actual->next = NULL;

      if (l1 != NULL) l1 = l1->next;
      if (l2 != NULL) l2 = l2->next;
  }

  struct ListNode *ret = dummy->next;
  free(dummy);  // liberamos el dummy, no lo necesitamos
  return ret;
}

int main(){
  
  struct ListNode *l1 = malloc(sizeof(struct ListNode));
  struct ListNode *l2 = malloc(sizeof(struct ListNode));

  struct ListNode *l12 = malloc(sizeof(struct ListNode));
  struct ListNode *l22 = malloc(sizeof(struct ListNode));

  struct ListNode *l13 = malloc(sizeof(struct ListNode));
  struct ListNode *l23 = malloc(sizeof(struct ListNode));
  
  l1->next = l12;
  l1->val = 2;
  
  l12->next = l13;
  l12->val = 4;
  
  l13->next = NULL;
  l13->val = 3;

  l2->next = l22;
  l2->val = 5;

  l22->next = l23;
  l22->val = 6;

  l23->next = NULL;
  l23->val = 4;

  struct ListNode *l3 = addTwoNumbers(l1, l2);

  while (l3!=NULL) {
    printf("%d", l3->val);
    l3=l3->next;
  }
  printf("\n");

  return 1;
}
