#include "point.h"
#include "complex.h"
#include <stdio.h>


COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
  COMPLEX temp = C;
  p--;
  while (p--) {
    C = MultiplyCOMPLEX(C, temp);
  }
  return temp;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
  int i;
  COMPLEX temp = C;   

  if (n == 0) {
    printf("Titik keluar dari lingkaran pada iterasi ke 0");
    return;
  }

  for (i = 1; i <= n; i++) {
    float x = (*P).X;
    float y = (*P).Y;

    (*P).X = x*C.Re - y*C.Im;
    (*P).Y = x*C.Im + y*C.Re;

    C = MultiplyCOMPLEX(C, temp);

    if (Jarak0(*P) >= 1) {
      printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
      return;
    }
  }
  printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}