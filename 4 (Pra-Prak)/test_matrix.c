#include <stdio.h>
#include <assert.h>
#include "matrix.h"

// Test createMatrix
void test_createMatrix() {
    Matrix m;
    createMatrix(3, 3, &m);
    assert(m.rowEff == 3);
    assert(m.colEff == 3);
}

// Test isMatrixIdxValid
void test_isMatrixIdxValid() {
    assert(isMatrixIdxValid(0, 0) == true);
    assert(isMatrixIdxValid(-1, 0) == false);
    assert(isMatrixIdxValid(0, -1) == false);
    assert(isMatrixIdxValid(ROW_CAP, 0) == false);
    assert(isMatrixIdxValid(0, COL_CAP) == false);
}

// Test getLastIdxRow
void test_getLastIdxRow() {
    Matrix m;
    createMatrix(3, 3, &m);
    assert(getLastIdxRow(m) == 2);
}

// Test getLastIdxCol
void test_getLastIdxCol() {
    Matrix m;
    createMatrix(3, 3, &m);
    assert(getLastIdxCol(m) == 2);
}

// Test isIdxEff
void test_isIdxEff() {
    Matrix m;
    createMatrix(3, 3, &m);
    assert(isIdxEff(m, 2, 2) == true);
    assert(isIdxEff(m, 3, 3) == false);
}

// Test getElmtDiagonal
void test_getElmtDiagonal() {
    Matrix m;
    createMatrix(3, 3, &m);
    ELMT(m, 0, 0) = 1;
    ELMT(m, 1, 1) = 2;
    ELMT(m, 2, 2) = 3;
    assert(getElmtDiagonal(m, 0) == 1);
    assert(getElmtDiagonal(m, 1) == 2);
    assert(getElmtDiagonal(m, 2) == 3);
}

// Test copyMatrix
void test_copyMatrix() {
    Matrix m1, m2;
    createMatrix(3, 3, &m1);
    ELMT(m1, 0, 0) = 1;
    ELMT(m1, 1, 1) = 2;
    ELMT(m1, 2, 2) = 3;
    copyMatrix(m1, &m2);
    assert(ELMT(m2, 0, 0) == 1);
    assert(ELMT(m2, 1, 1) == 2);
    assert(ELMT(m2, 2, 2) == 3);
}

// Test readMatrix and displayMatrix
void test_readMatrix_displayMatrix() {
    Matrix m;
    createMatrix(3, 3, &m);
    ELMT(m, 0, 0) = 1;
    ELMT(m, 0, 1) = 2;
    ELMT(m, 0, 2) = 3;
    ELMT(m, 1, 0) = 4;
    ELMT(m, 1, 1) = 5;
    ELMT(m, 1, 2) = 6;
    ELMT(m, 2, 0) = 7;
    ELMT(m, 2, 1) = 8;
    ELMT(m, 2, 2) = 9;
    displayMatrix(m);
    printf("\n");
}

// Test addMatrix
void test_addMatrix() {
    Matrix m1, m2, m3;
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);
    ELMT(m1, 0, 0) = 1;
    ELMT(m1, 0, 1) = 2;
    ELMT(m1, 0, 2) = 3;
    ELMT(m1, 1, 0) = 4;
    ELMT(m1, 1, 1) = 5;
    ELMT(m1, 1, 2) = 6;
    ELMT(m1, 2, 0) = 7;
    ELMT(m1, 2, 1) = 8;
    ELMT(m1, 2, 2) = 9;
    ELMT(m2, 0, 0) = 1;
    ELMT(m2, 0, 1) = 2;
    ELMT(m2, 0, 2) = 3;
    ELMT(m2, 1, 0) = 4;
    ELMT(m2, 1, 1) = 5;
    ELMT(m2, 1, 2) = 6;
    ELMT(m2, 2, 0) = 7;
    ELMT(m2, 2, 1) = 8;
    ELMT(m2, 2, 2) = 9;
    m3 = addMatrix(m1, m2);
    assert(ELMT(m3, 0, 0) == 2);
    assert(ELMT(m3, 0, 1) == 4);
    assert(ELMT(m3, 0, 2) == 6);
    assert(ELMT(m3, 1, 0) == 8);
    assert(ELMT(m3, 1, 1) == 10);
    assert(ELMT(m3, 1, 2) == 12);
    assert(ELMT(m3, 2, 0) == 14);
    assert(ELMT(m3, 2, 1) == 16);
    assert(ELMT(m3, 2, 2) == 18);
}

// Test subtractMatrix
void test_subtractMatrix() {
    Matrix m1, m2, m3;
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);
    ELMT(m1, 0, 0) = 1;
    ELMT(m1, 0, 1) = 2;
    ELMT(m1, 0, 2) = 3;
    ELMT(m1, 1, 0) = 4;
    ELMT(m1, 1, 1) = 5;
    ELMT(m1, 1, 2) = 6;
    ELMT(m1, 2, 0) = 7;
    ELMT(m1, 2, 1) = 8;
    ELMT(m1, 2, 2) = 9;
    ELMT(m2, 0, 0) = 1;
    ELMT(m2, 0, 1) = 2;
    ELMT(m2, 0, 2) = 3;
    ELMT(m2, 1, 0) = 4;
    ELMT(m2, 1, 1) = 5;
    ELMT(m2, 1, 2) = 6;
    ELMT(m2, 2, 0) = 7;
    ELMT(m2, 2, 1) = 8;
    ELMT(m2, 2, 2) = 9;
    m3 = subtractMatrix(m1, m2);
    assert(ELMT(m3, 0, 0) == 0);
    assert(ELMT(m3, 0, 1) == 0);
    assert(ELMT(m3, 0, 2) == 0);
    assert(ELMT(m3, 1, 0) == 0);
    assert(ELMT(m3, 1, 1) == 0);
    assert(ELMT(m3, 1, 2) == 0);
    assert(ELMT(m3, 2, 0) == 0);
    assert(ELMT(m3, 2, 1) == 0);
    assert(ELMT(m3, 2, 2) == 0);
}

// Test multiplyMatrix
void test_multiplyMatrix() {
    Matrix m1, m2, m3;
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);
    ELMT(m1, 0, 0) = 1;
    ELMT(m1, 0, 1) = 2;
    ELMT(m1, 0, 2) = 3;
    ELMT(m1, 1, 0) = 4;
    ELMT(m1, 1, 1) = 5;
    ELMT(m1, 1, 2) = 6;
    ELMT(m1, 2, 0) = 7;
    ELMT(m1, 2, 1) = 8;
    ELMT(m1, 2, 2) = 9;
    ELMT(m2, 0, 0) = 1;
    ELMT(m2, 0, 1) = 2;
    ELMT(m2, 0, 2) = 3;
    ELMT(m2, 1, 0) = 4;
    ELMT(m2, 1, 1) = 5;
    ELMT(m2, 1, 2) = 6;
    ELMT(m2, 2, 0) = 7;
    ELMT(m2, 2, 1) = 8;
    ELMT(m2, 2, 2) = 9;
    m3 = multiplyMatrix(m1, m2);
    assert(ELMT(m3, 0, 0) == 30);
    assert(ELMT(m3, 0, 1) == 36);
    assert(ELMT(m3, 0, 2) == 42);
    assert(ELMT(m3, 1, 0) == 66);
    assert(ELMT(m3, 1, 1) == 81);
    assert(ELMT(m3, 1, 2) == 96);
    assert(ELMT(m3, 2, 0) == 102);
    assert(ELMT(m3, 2, 1) == 126);
    assert(ELMT(m3, 2, 2) == 150);
}

// Test multiplyByConst
void test_multiplyByConst() {
    Matrix m;
    createMatrix(3, 3, &m);
    ELMT(m, 0, 0) = 1;
    ELMT(m, 0, 1) = 2;
    ELMT(m, 0, 2) = 3;
    ELMT(m, 1, 0) = 4;
    ELMT(m, 1, 1) = 5;
    ELMT(m, 1, 2) = 6;
    ELMT(m, 2, 0) = 7;
    ELMT(m, 2, 1) = 8;
    ELMT(m, 2, 2) = 9;
    m = multiplyByConst(m, 2);
    assert(ELMT(m, 0, 0) == 2);
    assert(ELMT(m, 0, 1) == 4);
    assert(ELMT(m, 0, 2) == 6);
    assert(ELMT(m, 1, 0) == 8);
    assert(ELMT(m, 1, 1) == 10);
    assert(ELMT(m, 1, 2) == 12);
    assert(ELMT(m, 2, 0) == 14);
    assert(ELMT(m, 2, 1) == 16);
    assert(ELMT(m, 2, 2) == 18);
}

// Test pMultiplyByConst
void test_pMultiplyByConst() {
    Matrix m;
    createMatrix(3, 3, &m);
    ELMT(m, 0, 0) = 1;
    ELMT(m, 0, 1) = 2;
    ELMT(m, 0, 2) = 3;
    ELMT(m, 1, 0) = 4;
    ELMT(m, 1, 1) = 5;
    ELMT(m, 1, 2) = 6;
    ELMT(m, 2, 0) = 7;
    ELMT(m, 2, 1) = 8;
    ELMT(m, 2, 2) = 9;
    pMultiplyByConst(&m, 2);
    assert(ELMT(m, 0, 0) == 2);
    assert(ELMT(m, 0, 1) == 4);
    assert(ELMT(m, 0, 2) == 6);
    assert(ELMT(m, 1, 0) == 8);
    assert(ELMT(m, 1, 1) == 10);
    assert(ELMT(m, 1, 2) == 12);
    assert(ELMT(m, 2, 0) == 14);
    assert(ELMT(m, 2, 1) == 16);
    assert(ELMT(m, 2, 2) == 18);
}

// Test isMatrixEqual
void test_isMatrixEqual() {
    Matrix m1, m2;
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);
    ELMT(m1, 0, 0) = 1;
    ELMT(m1, 0, 1) = 2;
    ELMT(m1, 0, 2) = 3;
    ELMT(m1, 1, 0) = 4;
    ELMT(m1, 1, 1) = 5;
    ELMT(m1, 1, 2) = 6;
    ELMT(m1, 2, 0) = 7;
    ELMT(m1, 2, 1) = 8;
    ELMT(m1, 2, 2) = 9;
    ELMT(m2, 0, 0) = 1;
    ELMT(m2, 0, 1) = 2;
    ELMT(m2, 0, 2) = 3;
    ELMT(m2, 1, 0) = 4;
    ELMT(m2, 1, 1) = 5;
    ELMT(m2, 1, 2) = 6;
    ELMT(m2, 2, 0) = 7;
    ELMT(m2, 2, 1) = 8;
    ELMT(m2, 2, 2) = 9;
    assert(isMatrixEqual(m1, m2) == true);
    ELMT(m2, 2, 2) = 10;
    assert(isMatrixEqual(m1, m2) == false);
}

// Test isMatrixNotEqual
void test_isMatrixNotEqual() {
    Matrix m1, m2;
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);
    ELMT(m1, 0, 0) = 1;
    ELMT(m1, 0, 1) = 2;
    ELMT(m1, 0, 2) = 3;
    ELMT(m1, 1, 0) = 4;
    ELMT(m1, 1, 1) = 5;
    ELMT(m1, 1, 2) = 6;
    ELMT(m1, 2, 0) = 7;
    ELMT(m1, 2, 1) = 8;
    ELMT(m1, 2, 2) = 9;
    ELMT(m2, 0, 0) = 1;
    ELMT(m2, 0, 1) = 2;
    ELMT(m2, 0, 2) = 3;
    ELMT(m2, 1, 0) = 4;
    ELMT(m2, 1, 1) = 5;
    ELMT(m2, 1, 2) = 6;
    ELMT(m2, 2, 0) = 7;
    ELMT(m2, 2, 1) = 8;
    ELMT(m2, 2, 2) = 9;
    assert(isMatrixNotEqual(m1, m2) == false);
    ELMT(m2, 2, 2) = 10;
    assert(isMatrixNotEqual(m1, m2) == true);
}

// Test isMatrixSizeEqual
void test_isMatrixSizeEqual() {
    Matrix m1, m2;
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);
    assert(isMatrixSizeEqual(m1, m2) == true);
    createMatrix(2, 3, &m2);
    assert(isMatrixSizeEqual(m1, m2) == false);
}

// Test countElmt
void test_countElmt() {
    Matrix m;
    createMatrix(3, 3, &m);
    assert(countElmt(m) == 9);
}

// Test isSquare
void test_isSquare() {
    Matrix m;
    createMatrix(3, 3, &m);
    assert(isSquare(m) == true);
    createMatrix(2, 3, &m);
    assert(isSquare(m) == false);
}

int main(){
    test_createMatrix();
    test_isMatrixIdxValid();
    test_getLastIdxRow();
    test_getLastIdxCol();
    test_isIdxEff();
    test_getElmtDiagonal();
    test_copyMatrix();
    test_readMatrix_displayMatrix();
    test_addMatrix();
    test_subtractMatrix();
    test_multiplyMatrix();
    test_multiplyByConst();
    test_pMultiplyByConst();
    test_isMatrixEqual();
    test_isMatrixNotEqual();
    test_isMatrixSizeEqual();
    test_countElmt();
    test_isSquare();
    printf("All tests passed!\n");
    return 0;
}