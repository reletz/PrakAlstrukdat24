#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  int N, i, j, len;
  List L;

  CreateList(&L);

  scanf("%d", &N);
  while (N != -9999){
    insertFirst(&L, N);
    scanf("%d", &N);
  }

  len = length(L);
  for (i = 0; i < len; i++){
    for (j = i + 1; j < len; j++){
      if (getElmt(L, i) > getElmt(L, j)){
        N = getElmt(L, i);
        setElmt(&L, i, getElmt(L, j));
        setElmt(&L, j, N);
      }
    }
  } displayList(L);

  return 0;
}