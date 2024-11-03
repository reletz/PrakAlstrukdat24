#include "boolean.h"
#include "complex.h"
#include <stdio.h>

boolean IsCOMPLEXValid(float Re, float Im){
  return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im){
  Real(*C) = Re;
  Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C){
  float Re, Im;
  scanf("%f %f", &Re, &Im);
  CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C){
  if (C.Im < 0){
    printf("%.2f%.2fi\n", C.Re, C.Im);
  } else {
    printf("%.2f+%.2fi\n", C.Re, C.Im);
  }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
  COMPLEX C;
  CreateComplex(&C, C1.Re+C2.Re, C1.Im+C2.Im);
  return C;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
  COMPLEX C;
  CreateComplex(&C, C1.Re-C2.Re, C1.Im-C2.Im);
  return C;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
  COMPLEX C;
  CreateComplex(&C, C1.Re*C2.Re-C1.Im*C2.Im, C1.Re*C2.Im+C2.Re*C1.Im);
  return C;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
  COMPLEX C;
  float den = (C2.Re*C2.Re+C2.Im*C2.Im);
  if (den == 0){
    CreateComplex(&C, 0, 0);
    return C;
  } else {
    CreateComplex(&C, (C1.Re*C2.Re+C1.Im*C2.Im)/den, (-C1.Re*C2.Im+C2.Re*C1.Im)/den);
    return C;
  }
}

float AbsCOMPLEX(COMPLEX C){
  return sqrt(C.Re*C.Re + C.Im*C.Im);
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
  COMPLEX C1;
  CreateComplex(&C1, C.Re, -C.Im);
  return C1;
}

boolean CEQ(COMPLEX C1, COMPLEX C2){
  return ((C1.Re == C2.Re) && (C1.Im == C2.Im));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
  return !CEQ(C1, C2);
}