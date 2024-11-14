#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType val){
  Address P = (Address) malloc(sizeof(Node));
  if (P != NULL){
    INFO(P) = val;
    NEXT(P) = NULL;
  }
  return P;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
  FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
  return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
  Address P = FIRST(l);
  int i = 0;
  while (P != NULL && i < idx){
    P = NEXT(P);
    i++;
  }
  return INFO(P);
}

void setElmt(List *l, int idx, ElType val){
  Address P = FIRST(*l);
  int i = 0;
  while (P != NULL && i < idx){
    P = NEXT(P);
    i++;
  }
  INFO(P) = val;
}

int indexOf(List l, ElType val){
  Address P = FIRST(l);
  int i = 0;
  while (P != NULL && INFO(P) != val){
    P = NEXT(P);
    i++;
  } if ((P == NULL) && (i == length(l) - 1)) return IDX_UNDEF;
  return i;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
  Address P = newNode(val);
  if (P != NULL){
    NEXT(P) = FIRST(*l);
    FIRST(*l) = P;
  }
}

void insertLast(List *l, ElType val){
  Address P = newNode(val);
  if (P != NULL){
    if (isEmpty(*l)){
      FIRST(*l) = P;
    } else {
      Address Last = FIRST(*l);
      while (NEXT(Last) != NULL){
        Last = NEXT(Last);
      }
      NEXT(Last) = P;
    }
  }
}

void insertAt(List *l, ElType val, int idx){
  Address P = newNode(val);
  if (P != NULL){
    if (idx == 0){
      NEXT(P) = FIRST(*l);
      FIRST(*l) = P;
    } else {
      Address Prec = FIRST(*l);
      int i = 0;
      while (i < idx-1){
        Prec = NEXT(Prec);
        i++;
      }
      NEXT(P) = NEXT(Prec);
      NEXT(Prec) = P;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
  Address P = FIRST(*l);
  *val = INFO(P);
  FIRST(*l) = NEXT(P);
  free(P);
}

void deleteLast(List *l, ElType *val){
  Address Last = FIRST(*l);
  Address PrecLast = NULL;
  while (NEXT(Last) != NULL){
    PrecLast = Last;
    Last = NEXT(Last);
  }
  *val = INFO(Last);
  if (PrecLast == NULL){
    FIRST(*l) = NULL;
  } else {
    NEXT(PrecLast) = NULL;
  }
  free(Last);
}

void deleteAt(List *l, int idx, ElType *val){
  if (idx == 0){
    deleteFirst(l, val);
  } else {
    Address P = FIRST(*l);
    Address Prec = NULL;
    int i = 0;
    while (i < idx){
      Prec = P;
      P = NEXT(P);
      i++;
    }
    *val = INFO(P);
    NEXT(Prec) = NEXT(P);
    free(P);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
  Address P = FIRST(l);
  printf("[");
  while (P != NULL){
    printf("%d", INFO(P));
    if (NEXT(P) != NULL){
      printf(",");
    }
    P = NEXT(P);
  }
  printf("]\n");
}

int length(List l){
  Address P = FIRST(l);
  int len = 0;
  while (P != NULL){
    len++;
    P = NEXT(P);
  }
  return len;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
  List l;
  CreateList(&l);
  Address P = FIRST(l1);
  while (P != NULL){
    insertLast(&l, INFO(P));
    P = NEXT(P);
  }
  P = FIRST(l2);
  while (P != NULL){
    insertLast(&l, INFO(P));
    P = NEXT(P);
  }
  return l;
}
