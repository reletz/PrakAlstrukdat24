#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
  char c;
  int i, idx, temp;
  List L;

  CreateList(&L);

  i = 0;
  scanf("%c", &c);
  while (c != 'X'){
    if (c == 'P'){
      scanf("%d", &i);
      insertFirst(&L, i);
    } else if (c == 'I'){
      scanf("%d", &i);
      insertLast(&L, i);
    } else if (c == 'C'){
      if (!isEmpty(L)){
        deleteFirst(&L, &temp);
      }
    } else if (c == 'D'){
      scanf("%d", &i);
      idx = indexOf(L, i);
      if (!isEmpty(L) && idx != IDX_UNDEF){
        deleteAt(&L, idx, &temp);
      }
    } scanf("%c", &c);
  } displayList(L);
}