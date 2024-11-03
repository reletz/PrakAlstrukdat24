#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

void CreateListStatik(ListStatik *l){
  IdxType i;
  for (i = 0; i < CAPACITY; i++){
    (*l).contents[i] = MARK;
  }
}

int listLength(ListStatik l){
  IdxType i = 0;
  while (l.contents[i] != MARK && i != CAPACITY){
    i += 1;
  } return i;
}

IdxType getFirstIdx(ListStatik l){
  return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
  return (listLength(l) - 1);
}

boolean isIdxValid(ListStatik l, IdxType i){
  return ((i < CAPACITY) && (i >= IDX_MIN));
}

boolean isIdxEff(ListStatik l, IdxType i){
  return ((i < listLength(l)) && (i >= 0));
}

boolean isEmpty(ListStatik l){
  return (listLength(l) == 0);
}

boolean isFull(ListStatik l){
  return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l){
  int n;
  IdxType i;
  do {
    scanf("%d", &n);
  } while (n > CAPACITY || n < 0);
  CreateListStatik(l);
  for (i = 0; i < n; i++){
    scanf("%d", &((*l).contents[i]));
  }
}

void printList(ListStatik l){
  IdxType i;
  if (!isEmpty(l)){
    printf("[%d", l.contents[getFirstIdx(l)]);
    for (i = getFirstIdx(l)+1; i <= getLastIdx(l); i++){
      printf(",%d", l.contents[i]);
    }
    printf("]");
  } else {
    printf("[]");
  }
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
  IdxType i;
  ListStatik l;
  CreateListStatik(&l);
  if (plus){
    for (i = 0; i <= listLength(l1) - 1; i++){
      l.contents[i] = l1.contents[i] + l2.contents[i];
    }
  } else {
    for (i = 0; i <= listLength(l1) - 1; i++){
      l.contents[i] = l1.contents[i] - l2.contents[i];
    }
  } return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
  IdxType i;
  if (listLength(l1) != listLength(l2)){
    return false;
  } for (i = 0; i <= listLength(l1) - 1; i++){
      if (l1.contents[i] != l2.contents[i]) {
        return false;
    }
  } return true;
}

IdxType indexOf(ListStatik l, ElType val){
  IdxType i;
  for (i = getFirstIdx(l); i <= listLength(l) - 1; i++){
    if (l.contents[i] == val) {
      return i;
    }
  } 
  return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
  IdxType i;
  *max = l.contents[getFirstIdx(l)];
  *min = l.contents[getFirstIdx(l)];
  for (i = getFirstIdx(l); i <= listLength(l) - 1; i++){
    if (l.contents[i] > *max){
      *max = l.contents[i];
    }
    if (l.contents[i] < *min){
      *min = l.contents[i];
    }
  }
}

void insertFirst(ListStatik *l, ElType val){
  IdxType i;
  for (i = getLastIdx(*l); i >= getFirstIdx(*l); i--){
    (*l).contents[i+1] = (*l).contents[i]; 
  } (*l).contents[getFirstIdx(*l)] = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
  IdxType i;
  for (i = getLastIdx(*l); i >= idx; i--){
    (*l).contents[i+1] = (*l).contents[i]; 
  } (*l).contents[idx] = val;
}

void insertLast(ListStatik *l, ElType val){
  (*l).contents[getLastIdx(*l) + 1] = val;
}

void deleteFirst(ListStatik *l, ElType *val){
  IdxType i;
  *val = (*l).contents[getFirstIdx(*l)];
  for (i = getFirstIdx(*l); i < listLength(*l) - 1; i++){
    (*l).contents[i] = (*l).contents[i+1];
  } (*l).contents[getLastIdx(*l)] = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
  IdxType i;
  *val = (*l).contents[idx];
  for (i = idx; i < listLength(*l) - 1; i++){
    (*l).contents[i] = (*l).contents[i+1];
  } (*l).contents[getLastIdx(*l)] = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
  *val = (*l).contents[getLastIdx(*l)];
  (*l).contents[getLastIdx(*l)] = MARK;
}

void sortList(ListStatik *l, boolean asc){
  IdxType i,j;
  for (i = 0; i < listLength(*l) - 1; i++){
    for (j = i + 1; j < listLength(*l); j++){
      if ((asc && (*l).contents[i] > (*l).contents[j]) || (!asc && (*l).contents[i] < (*l).contents[j])) {
        ElType temp = (*l).contents[i];
        (*l).contents[i] = (*l).contents[j];
        (*l).contents[j] = temp;
      }
    }
  }
}