#include <stdio.h>
#include "point.h"
#include <math.h>

void CreatePoint (POINT *P, float X, float Y){
  Absis(*P) = X;
  Ordinat(*P) = Y;
}

void BacaPOINT (POINT *P){
  float x, y;
  scanf("%f %f", &x, &y);
  CreatePoint(P, x, y);
}

void TulisPOINT (POINT P){
  printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}             

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
  return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
  return !EQ(P1, P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
  return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
  return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
  return (Absis(P) == 0);
}

int Kuadran (POINT P){
  if (Absis(P) > 0 && Ordinat(P) > 0) {
    return 1;
  } else if (Absis(P) < 0 && Ordinat(P) > 0) {
    return 2;
  } else if (Absis(P) < 0 && Ordinat(P) < 0) {
    return 3;
  } else {
    return 4;
  }
}
                        
POINT NextX (POINT P){
  POINT n;
  Absis(n) = Absis(P) + 1;
  Ordinat(n) = Ordinat(P);
  return n;
}       

POINT NextY (POINT P){
  POINT n;
  Absis(n) = Absis(P);
  Ordinat(n) = Ordinat(P) + 1;
  return n;
}      

POINT PlusDelta (POINT P, float deltaX, float deltaY){
  POINT n;
  Absis(n) = Absis(P) + deltaX;
  Ordinat(n) = Ordinat(P) + deltaY;
  return n;
}      

POINT MirrorOf (POINT P, boolean SbX){
  POINT n;
  Absis(n) = Absis(P);
  Ordinat(n) = Ordinat(P);
  if (SbX) {
    Ordinat(n) *= -1;
  } else {
    Absis(n) *= -1;
  } return n;
}

float Jarak0 (POINT P){
  return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
  return sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)) + (Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2)));
}

void Geser (POINT *P, float deltaX, float deltaY){
  Absis(*P) += deltaX;
  Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
  Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
  Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
  if (SbX) {
    Ordinat(*P) *= -1;
  } else {
    Absis(*P) *= -1;
  }
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */{
  float rad = Sudut*3.14159265358979323846/180.0;
  float sina = sinf(rad);
  float cosa = cosf(rad);
  float x = Absis(*P);
  float y = Ordinat(*P);

  Absis(*P) = x*cosa + y*sina;
  Ordinat(*P) = -x*sina + y*cosa;
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
  int a = (Ordinat(P2) - Ordinat(P1))/(Absis(P2) - Absis(P1));
  int b = Ordinat(P1) - a*(Absis(P1));
  printf("(%d,%d)", a, b);
}