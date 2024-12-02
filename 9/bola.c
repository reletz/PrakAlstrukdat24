#include "boolean.h"
#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  int N, i, j, val, len;
  List L;
  Address P;

  CreateList(&L);

  scanf("%d", &N);
  for (i = 0; i < N; i++){
    insertLast(&L, i+1);
  }
  
  P = FIRST(L);

  for (i = 0; i < N - 1; i++){
    len = N - i;
    scanf("%d", &val);

    if (val < 0) {
      val = (i != 0) ? val + 1 : val;
      val %= len;
      val += len;
    }

    val %= len;

    if (val == 0) {
      val = len;
    }
    
    for (j = 0; j < val; j++){
      P = NEXT(P);
    } FIRST(L) = P;

    deleteFirst(&L, &val);
  }

  printf("%d\n", INFO(FIRST(L)));

  return 0;
}