#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  int N, carry, sum;
  List L1, L2, L3;
  Address P1, P2;

  CreateList(&L1);
  CreateList(&L2);
  CreateList(&L3);

  scanf("%d", &N);
  while (N != -1){
    insertFirst(&L1, N);
    scanf("%d", &N);
  } P1 = FIRST(L1);

  scanf("%d", &N);
  while (N != -1){
    insertFirst(&L2, N);
    scanf("%d", &N);
  } P2 = FIRST(L2);
 
  sum = 0; carry = 0;
  while (P1 != NULL && P2 != NULL){
    sum = (INFO(P1) + INFO(P2));
    insertFirst(&L3, (sum + carry) % 10);
    carry = (sum + carry) / 10;
    P1 = NEXT(P1);
    P2 = NEXT(P2);
  } 

  while (P1 != NULL){
    sum = INFO(P1);
    insertFirst(&L3, (sum + carry) % 10);
    carry = (sum + carry) / 10;
    P1 = NEXT(P1);
  }

  while (P2 != NULL){
    sum = INFO(P2);
    insertFirst(&L3, (sum + carry) % 10);
    carry = (sum + carry) / 10;
    P2 = NEXT(P2);
  }

  if (carry > 0) insertFirst(&L3, carry);

  P1 = FIRST(L3);
  while (P1 != NULL){
    printf("%d", INFO(P1));
    P1 = NEXT(P1);
    if (P1 != NULL) printf(" ");
  }

  printf("\n");
  return 0;
}