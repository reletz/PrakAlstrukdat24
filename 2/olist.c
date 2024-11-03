#include "boolean.h"
#include "liststatik.h"
#include <stdio.h>

int main(){
  //remove duplicate and count for elements which were there
  IdxType i, j;
  ListStatik l, lctr;
  readList(&l);
  CreateListStatik(&lctr);
  int size = getLastIdx(l);
  for (i = 0; i <= size; i++){
    ELMT(lctr, i) += 1;
    if (listLength(l) > 1){
      for (j = i + 1; j <= size; j++){
        if (ELMT(l, i) == ELMT(l, j)){
          deleteAt(&l, &ELMT(l,j), j);
          size--; 
          j--;
          ELMT(lctr, i) += 1;
        }
      }
    }
  } 
  
  printList(l); 
  printf("\n");
  
  for (i = 0; i <= getLastIdx(l); i++){
    printf("%d %d\n", ELMT(l, i), ELMT(lctr, i) - MARK);
  }

  return 0;
}
  