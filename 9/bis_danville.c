#include "boolean.h"
#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

boolean checkC(List L, Address P){
  if (INFO(NEXT(P)) != 1) return false;
  
  Address Q = NEXT(P);
  while (INFO(Q) < INFO(NEXT(Q))) {
    Q = NEXT(Q);
  } return Q == P;
}

boolean checkCC(List L, Address P){
  Address Q = P;
  while (INFO(Q) > INFO(NEXT(Q))) {
    Q = NEXT(Q);
  } return NEXT(Q) == P;
}

int main(){
  int N, i, max, val;
  List L;
  Address P;
  CreateList(&L);

  scanf("%d", &N);

  max = 0;
  for (i = 0; i < N; i++){
    scanf("%d", &val);
    insertLast(&L, val);
    max = (val > max) ? val : max;
  }

  P = search(L, max);

  if (checkC(L, P) || checkCC(L, P)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
