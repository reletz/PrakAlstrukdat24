#include <stdio.h>
#include "boolean.h"
#include "fraction.h"

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D){
    return (D != 0);
}

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R){
    (*F).N = N;
    (*F).D = R;
}

void ReadFRACTION(FRACTION *F){
    int x, y;
    scanf("%d %d", &x, &y);
    while (!IsFRACTIONValid(x, y)){
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &x, &y);
    }
    CreateFRACTION(F, x, y);
}

void WriteFRACTION(FRACTION F){
    if (F.N == 0){
        printf("0/1");
    } else {
        F = SimplifyFRACTION(F);
        printf("%d/%d", F.N, F.D);
    }
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    F.N = F1.N*F2.D + F2.N*F1.D;
    F.D = F1.D*F2.D;
    return SimplifyFRACTION(F);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    F.N = F1.N*F2.D - F2.N*F1.D;
    F.D = F1.D*F2.D;
    return SimplifyFRACTION(F);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    F.N = F1.N*F2.N;
    F.D = F1.D*F2.D;
    return SimplifyFRACTION(F);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    F.N = F1.N*F2.D;
    F.D = F1.D*F2.N;
    return SimplifyFRACTION(F);
}
FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
    FRACTION F;
    F.N = F1.N*n;
    F.D = F1.D;
    return SimplifyFRACTION(F);
}
/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F){
    FRACTION F1;
    boolean negN = F.N < 0;
    boolean negD = F.D < 0;
    if (negN && negD){
        CreateFRACTION(&F1, -F.N / gcd(-F.N, -F.D), -F.D / gcd(-F.N, -F.D));
    } else if (negN){
        CreateFRACTION(&F1, F.N / gcd(-F.N, F.D), F.D / gcd(-F.N, F.D));
    } else if (negD){
        CreateFRACTION(&F1, -F.N / gcd(F.N, -F.D), -F.D / gcd(F.N, -F.D));
    } else {
        CreateFRACTION(&F1, F.N / gcd(F.N, F.D), F.D / gcd(F.N, F.D));
    }
    return F1;
}

float ToDecimal(FRACTION F){
    return ((float)F.N/(float)F.D);
}
