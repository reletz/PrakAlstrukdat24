#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"
void printElList(ListStatik l){
  IdxType i;
  if (!isEmpty(l)){
    printf("%d", l.contents[getFirstIdx(l)]);
    for (i = getFirstIdx(l)+1; i <= getLastIdx(l); i++){
      printf(" %d", l.contents[i]);
    }
    printf("\n");
  }
}

int main(){
    IdxType i;
    ListStatik *l;
    ElType temp;
    readList(l);
    (*l).contents[getLastIdx(*l)] += 1;
    insertFirst(l, 0);
    for (i = getLastIdx(*l); i > 0; i--){
        if ((*l).contents[i] / 10 >= 1){
            (*l).contents[i] = (*l).contents[i] % 10;
            (*l).contents[i-1] += 1;
        }
    } if ((*l).contents[getFirstIdx(*l)] == 0) {
        deleteFirst(l, &temp);
    } printElList(*l);
    return 0;
}
