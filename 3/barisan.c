#include "boolean.h"
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, i, j, count = 0;
    do {
        scanf("%d", &N);
    } while (N < 0);
    ListDin l;
    CreateListDin(&l, N);
    NEFF(l) = N; 
    for (i = 0; i < N; i++){
        scanf("%d", &ELMT(l, i));
    } 
    for (i = 0; i <= N - 1; i++){
        for (j = 0; j <= i; j++){
            if (ELMT(l, i) < ELMT(l, j)){
                count += 1;
        }
    }
  } printf("%d\n", count);
  return 0;
}