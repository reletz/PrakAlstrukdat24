
#include "boolean.h"
#include "hapus-duplikat.h"
#include <stdlib.h>
#include <stdio.h>

List hapusDuplikat(List l){
  int iP, iQ;
  boolean found;
  ElType val, searched;
  Address P, Q;
  List newL;

  CreateList(&newL);
  P = FIRST(l);
  iP = IDX_UNDEF; iQ = IDX_UNDEF;
  found = false;

  while (P != NULL) {
    insertFirst(&newL, INFO(P));
    P = NEXT(P);
  }

  P = FIRST(newL);

  while (P != NULL) {
    val = INFO(P);
    iP = indexOf(newL, val);
    Q = NEXT(P);
    iQ = iP + 1;

    while (Q != NULL){
      searched = INFO(Q);
      if (searched != val) break;

      deleteAt(&newL, iQ, &searched);
      Q = NEXT(Q);
      found = true;
    } if (found){
      deleteAt(&newL, iP, &val);
      found = false;
    } P = NEXT(P);
  } return newL;
}