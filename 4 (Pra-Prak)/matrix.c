#include "boolean.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void createMatrix(int nRows, int nCols, Matrix *m){
  (*m).rowEff = nRows;
  (*m).colEff = nCols;
}

boolean isMatrixIdxValid(int i, int j){
  return (i >= 0) && (j >= 0) && (i < ROW_CAP) && (j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m){
  return ROW_EFF(m) - 1;
}
IdxType getLastIdxCol(Matrix m){
  return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
  return (i >= 0) && (j >= 0) && (i < ROW_EFF(m)) && (j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
  return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
  ROW_EFF(*mOut) = ROW_EFF(mIn);
  COL_EFF(*mOut) = COL_EFF(mIn);
  int i, j;
  for (i = 0; i <= getLastIdxRow(mIn); i++){
    for (j = 0; j <= getLastIdxCol(mIn); j++){
      ELMT(*mOut, i, j) = ELMT(mIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
  int i, j;
  createMatrix(nRow, nCol, m);
  for (i = 0; i < nRow; i++){
    for (j = 0; j < nCol; j++){
      scanf("%d", &ELMT(*m, i, j));
    }
  }
}

void displayMatrix(Matrix m){
  int i, j;
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      if (j == 0) printf("%d", ELMT(m, i, j));
      else printf(" %d", ELMT(m, i, j));
    } if (i != getLastIdxRow(m)) printf("\n");
  }
}

Matrix addMatrix(Matrix m1, Matrix m2){
  int i, j;
  Matrix m;
  createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
  copyMatrix(m1, &m);
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      ELMT(m, i, j) += ELMT(m2, i, j);
    }
  } return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
  int i, j;
  Matrix m;
  createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
  copyMatrix(m1, &m);
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      ELMT(m, i, j) -= ELMT(m2, i, j);
    }
  } return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
  int i, j, k, temp, meetPoint;
  Matrix m;
  meetPoint = getLastIdxCol(m1);
  createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      temp = 0;
      for (k = 0; k <= meetPoint; k++){
        temp += ELMT(m1, i, k) * ELMT(m2, k, j); 
      } ELMT(m, i, j) = temp;
    }
  } return m;
}
//Misal: 2x3 dan 3x2: hasilnya 2x2
//0.0*0.0 + 0.1*1.0 + 0.2 * 2.0    0.0*0.1 + 0.1*1.1 + 0.2*2.1
//1.0*0.0 + 1.1*1.0 + 1.2 * 2.0    1.0*0.1 + 1.1*1.1 + 1.2*2.1 

Matrix multiplyByConst(Matrix m, ElType x){
  int i, j;
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      ELMT(m, i, j) *= x;
    }
  } return m;
}

/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
  int i, j;
  for (i = 0; i <= getLastIdxRow(*m); i++){
    for (j = 0; j <= getLastIdxCol(*m); j++){
      ELMT(*m, i, j) *= k;
    }
  } 
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
  int i, j;
  if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) return false;
  for (i = 0; i <= getLastIdxRow(m1); i++){
    for (j = 0; j <= getLastIdxCol(m1); j++){
      if (ELMT(m1, i, j) != ELMT(m2, i, j)) return false;
    }
  } return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
  return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
  return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
  return ROW_EFF(m)*COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
  return (ROW_EFF(m) == COL_EFF(m));  
}

boolean isSymmetric(Matrix m){
  if (!isSquare(m)) return false;
  int i, j;
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      if (ELMT(m, i, j) != ELMT(m, j, i)){
        return false;
      }
    }
  } return true;
}

boolean isIdentity(Matrix m){
  if (!isSquare(m)) return false;
  int i, j;
  for (i = 0; i <= getLastIdxRow(m); i++){
    if (ELMT(m, i, i) != 1) return false;
    for (j = 0; j <= getLastIdxCol(m); j++){
      if (i != j && ELMT(m, i, j) != 0) return false;
    }
  } return true;
}

boolean isSparse(Matrix m){
  if (!isSquare(m)) return false;
  int i,j, counter = 0;
  for(i = 0; i < ROW_EFF(m); i++){
    for(j = 0; j < COL_EFF(m); j++){
      if (ELMT(m,i,j) != 0) counter++;
    }
  }
  return (counter <= (0.05)*(float)countElmt(m));
}

Matrix negation(Matrix m){
  return multiplyByConst(m, -1);
}

void pNegation(Matrix *m){
  pMultiplyByConst(m, -1);
}

float determinant(Matrix m){
  ElType top;
  float detTemp = 0.0;
  int row, col, i, j, k;
  row = 0; col = 0;
  Matrix temp;

  //Base Case
  if (ROW_EFF(m) == 1){
    return ELMT(m, 0, 0);
  } else if (ROW_EFF(m) == 2){
    return (ELMT(m, 0, 0)*ELMT(m, 1, 1) - ELMT(m, 1, 0)*ELMT(m, 0, 1));
  
  //Recursive Case
  } else {
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &temp);
    for (i = 0; i < COL_EFF(m); i++){
      if (i % 2 == 0){
        top = ELMT(m, 0, i);
      } else {
        top = -ELMT(m, 0, i);
      }

      //make an inner matrix
      row = 0;
      for (j = 1; j < ROW_EFF(m); j++){//skip highest row
        col = 0;
        for (k = 0; k < COL_EFF(m); k++){
          if (k == i){
            k++;
          }
          ELMT(temp, row, col) = ELMT(m, j, k);
          col++;
        } row++;

      } detTemp += (float) top*determinant(temp);
    }
  } return detTemp;
}

Matrix transpose(Matrix m){
  int i, j;
  Matrix mt;
  copyMatrix(m, &mt);
  for (i = 0; i <= getLastIdxRow(m); i++){
    for (j = 0; j <= getLastIdxCol(m); j++){
      ELMT(m, i, j) = ELMT(mt, j, i);
    }
  } return m;
}

void pTranspose(Matrix *m){
  int i, j;
  Matrix mt;
  copyMatrix(*m, &mt);
  for (i = 0; i <= getLastIdxRow(*m); i++){
    for (j = 0; j <= getLastIdxCol(*m); j++){
      ELMT(*m, i, j) = ELMT(mt, j, i);
    }
  }
}