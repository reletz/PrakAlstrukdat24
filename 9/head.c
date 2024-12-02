#include "boolean.h"
#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

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
  FIRST(L) = P;
  displayList(L);

  return 0;
}
