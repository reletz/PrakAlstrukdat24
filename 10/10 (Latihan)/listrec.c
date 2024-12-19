#include "listrec.h"
#include <stdlib.h>
#include "boolean.h"

Address newNode(ElType x){
   Address P = (Address) malloc (sizeof(Node));
   if (P != NIL) {
      INFO(P) = x;
      NEXT(P) = NIL;
   } return P;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
   return (l == NIL);
}
boolean isOneElmt(List l){
   return (!isEmpty(l) && NEXT(l) == NIL);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
   return INFO(l);
}

List tail(List l){
   return NEXT(l);
}

List konso(List l, ElType e){
   Address P = newNode(e);
   if (P != NIL) {
      NEXT(P) = l;
      return P;
   } return l;
}

List konsb(List l, ElType e){
   Address P = newNode(e);
   if (P != NIL) {
      if (isEmpty(l)) {
         return P;
      } else {
         NEXT(l) = konsb(tail(l), e);
         return l;
      }
   } return l;
}

List insertAt (List l, ElType e, int i){
   if (i == 0) {
      return konso(l, e);
   }
   NEXT(l) = insertAt(tail(l), e, i-1);
   return l;
}

List deleteFirst(List l, ElType *e){
   *e = head(l);
   return tail(l);
}

List deleteAt(List l, int i, ElType *e){
   if (i == 0) {
      *e = head(l);
      return tail(l);
   }
   NEXT(l) = deleteAt(tail(l), i-1, e);
   return l;
} //Contoh: Jika l adalah 1 2 3 4 5, dan i = 3, maka l menjadi 1 2 3 5. e = 4
//Prosesnya: deleteAt(l, 3, &e) -> deleteAt(2 3 4 5, 2, &e) -> deleteAt(3 4 5, 1, &e) -> deleteAt(4 5, 0, &e) -> 5

List deleteLast(List l, ElType *e){
   if (isOneElmt(l)) {
      *e = head(l);
      return NIL;
   }
   NEXT(l) = deleteLast(tail(l), e);
   return l;
}

List copy(List l){
   if (isEmpty(l)) {
      return NIL;
   } return konso(copy(tail(l)), head(l));
}

List concat(List l1, List l2){
   if (isEmpty(l1)) {
      return copy(l2);
   } return konso(concat(tail(l1), l2), head(l1));
}

/* Fungsi dan Prosedur Lain */
int length(List l){
   if (isEmpty(l)) {
      return 0;
   } return 1 + length(tail(l));
}

boolean isMember(List l, ElType x){
   if (isEmpty(l)) return false;
   else if (head(l) == x) return true;

   return isMember(tail(l), x);
}

List inverseList(List l){
   if (isEmpty(l)) return NIL;
   return konsb(inverseList(tail(l)), head(l));
}

void splitPosNeg(List l, List *positif, List *negatif){
   if (isEmpty(l)) {
      *positif = NIL;
      *negatif = NIL;
   } else {
      splitPosNeg(tail(l), positif, negatif);
      if (head(l) >= 0) {
         *positif = konso(*positif, head(l));
      } else {
         *negatif = konso(*negatif, head(l));
      }
   }
}

void splitOnX(List l, ElType X, List *l1, List *l2){
   if (isEmpty(l)) {
      *l1 = NIL;
      *l2 = NIL;
   } else {
      splitOnX(tail(l), X, l1, l2);
      if (head(l) <= X) {
         *l1 = konso(*l1, head(l));
      } else {
         *l2 = konso(*l2, head(l));
      }
   }
}

List removeDuplicate(List l){
   if (isEmpty(l)) {
      return NIL;
   } else {
      if (isMember(tail(l), head(l))) {
         return removeDuplicate(tail(l));
      } else {
         return konso(removeDuplicate(tail(l)), head(l));
      }
   }
}

void displayList(List l){
   if (!isEmpty(l)) {
      printf("%d\n", head(l));
      displayList(tail(l));
   }
}