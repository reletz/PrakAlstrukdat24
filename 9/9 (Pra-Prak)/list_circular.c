/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

/* Definisi list : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* Selektor */
#include "boolean.h"
#include "list_circular.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
  return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
  FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
  Address P  = (Address) malloc(sizeof(ElmtList));
  if (P != NULL) {
    INFO(P) = val;
    NEXT(P) = NULL;
  }
  return P;
}

void deallocate(Address P){
  free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
  Address P = FIRST(l);
  if (P != NULL) {
    do {
      if (INFO(P) == val) {
        return P;
      }
      P = NEXT(P);
    } while (P != FIRST(l));
  }
  return NULL;
}

boolean addrSearch(List l, Address p){
  Address P = FIRST(l);
  if (P != NULL) {
    do {
      if (P == p) {
        return true;
      } P = NEXT(P);
    } while (P != FIRST(l));
  } return false;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
  Address P = allocate(val);
  if (P != NULL) {
    if (isEmpty(*l)) {
      FIRST(*l) = P;
      NEXT(P) = P;
    } else {
      Address Last = FIRST(*l);
      while (NEXT(Last) != FIRST(*l)) {
        Last = NEXT(Last);
      }
      NEXT(P) = FIRST(*l);
      NEXT(Last) = P;
      FIRST(*l) = P;
    }
  }
}
void insertLast(List *l, ElType val){
  Address P = allocate(val);
  if (P != NULL) {
    if (isEmpty(*l)) {
      FIRST(*l) = P;
      NEXT(P) = P;
    } else {
      Address Last = FIRST(*l);
      while (NEXT(Last) != FIRST(*l)) {
        Last = NEXT(Last);
      }
      NEXT(Last) = P;
      NEXT(P) = FIRST(*l);
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
  Address P = FIRST(*l);
  if (P != NULL) {
    if (NEXT(P) == P) {
      FIRST(*l) = NULL;
    } else {
      Address Last = FIRST(*l);
      while (NEXT(Last) != FIRST(*l)) {
        Last = NEXT(Last);
      }
      FIRST(*l) = NEXT(P);
      NEXT(Last) = FIRST(*l);
    }
    *val = INFO(P);
    deallocate(P);
  }
}

void deleteLast(List *l, ElType * val){
  Address P = FIRST(*l);
  if (P != NULL) {
    if (NEXT(P) == P) {
      FIRST(*l) = NULL;
    } else {
      Address Last = FIRST(*l);
      while (NEXT(NEXT(Last)) != FIRST(*l)) {
        Last = NEXT(Last);
      }
      P = NEXT(Last);
      NEXT(Last) = FIRST(*l);
    }
    *val = INFO(P);
    deallocate(P);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
  Address P = FIRST(l);
  printf("[");
  if (P != NULL) {
    printf("%d", INFO(P));
    P = NEXT(P);
    while (P != FIRST(l)) {
      printf(",%d", INFO(P));
      P = NEXT(P);
    }
  } printf("]");
}