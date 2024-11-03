#include <stdio.h>

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", a);
  while (a < b){
    if (a % 2 == 0){
      a = a*2;
    } else {
      a = a+1;
    }
    if (a < b){
      printf(" %d", a);
    }
  }
  printf("\n");
  return 0;
}