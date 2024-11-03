#include <stdio.h>

int fibonacci(int x, int y, int i){
  if (i == 1){
    return x;
  } else if (i == 2){
    return y;
  } else {
    return fibonacci(x, y, i-1) + fibonacci(x, y, i-2);
  }
};

int main(){
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  printf("%d\n", fibonacci(a, b, n));
  return 0;
}