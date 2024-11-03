#include <stdio.h>

int main(){
  int n, i, j;
  scanf("%d", &n);
  for (i = n; i > 0; i--){
    for (j = 0; j < n-i; j++){
      printf(" ");
    };
    for (j = 2*i-1; j > 0; --j){
      printf("*");
    };
    printf("\n");
  };
  return 0;
}