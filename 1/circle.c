#include <stdio.h>
#include "boolean.h"
#include "circle.h"
#include <math.h>
#include <stdlib.h>

#define pi 3.14

boolean IsCIRCLEValid(float X, float Y, float R){
    return (R > 0);
}

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    (*C).CENTER.X = X;
    (*C).CENTER.Y = Y;
    (*C).R = R;
}

void ReadCIRCLE(CIRCLE *C){
    float x, y, r;
    scanf("%f %f %f", &x, &y, &r);
    while (!IsCIRCLEValid(x, y, r)) {
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &x, &y, &r);
    }
    CreateCIRCLE(C, x, y, r);
}

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", C.CENTER.X, C.CENTER.Y, C.R);
}

float Circumference(CIRCLE C){
    float r = C.R;
    return 2*pi*r;
}

float Area(CIRCLE C){
    float r = C.R;
    return pi*r*r;
} 

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    return (Panjang(C.CENTER, P) < C.R);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    float d = Panjang(C.CENTER, P);
    return ((d -  C.R) <= 0.000001);
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
    return ((Panjang(C1.CENTER, C2.CENTER)) < abs(C1.R - C2.R));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float d = Panjang(C1.CENTER, C2.CENTER);
    float sum = (C1.R + C2.R);
    float diff = abs(C1.R - C2.R);
    return ((abs(d - sum) <= 0.000001) || (abs(d -diff) <= 0.000001));
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    float d = Panjang(C1.CENTER, C2.CENTER);
    float sum = (C1.R + C2.R);
    float diff = abs(C1.R - C2.R);
    return ((d > diff) && (d < sum));
}