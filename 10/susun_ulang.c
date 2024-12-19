#include "listrec.c"

int main(){
  int N;
  scanf("%d", &N);

  List L = NIL;

  int i, X;
  for(i = 0; i < N; i++){
    scanf("%d", &X);
    L = konsb(L, X);
  }

  displayList(L);

  return 0;
}