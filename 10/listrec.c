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

List copy(List l){
   if (isEmpty(l)) {
      return NIL;
   } else {
      return konso(copy(tail(l)), head(l));
   }
}

List concat(List l1, List l2){
   if (isEmpty(l1)) {
      return copy(l2);
   } else {
      return konso(concat(tail(l1), l2), head(l1));
   }
}

/* Fungsi dan Prosedur Lain */
int length(List l){
   if (isEmpty(l)) {
      return 0;
   } else {
      return 1 + length(tail(l));
   }
}

boolean isMember(List l, ElType x){
   if (isEmpty(l)) return false;
   else if (head(l) == x) return true;
   return isMember(tail(l), x);
}

void displayList(List l){
   if (!isEmpty(l)) {
      printf("%d\n", head(l));
      displayList(tail(l));
   }
}

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx){
   if (idx == 0) return konso(l, e);
   if (isEmpty(l)) return NIL;
   NEXT(l) = insertAt(tail(l), e, idx - 1);
   return l;
}

List deleteFirst(List l){
   if (isEmpty(l)) return NIL;
   return (tail(l));
}

List deleteAt(List l, int idx){
   if (isEmpty(l)) return NIL;
   if (idx == 0) return tail(l);
   NEXT(l) = deleteAt(tail(l), idx - 1);
   return l;
}

List deleteLast(List l){
   if (isEmpty(l) || isOneElmt(l)) return NIL;
   NEXT(l) = deleteLast(tail(l));
   return l;
}

List reverseList (List l){
   if (isEmpty(l)) return NIL;
   return konsb(reverseList(tail(l)), head(l));
}

void splitOddEven (List l, List *l1, List *l2){
   if (!isEmpty(l)) {
      ElType val = head(l);
      if (val % 2 == 1) {
         (*l2) = konsb(*l2, val);
      } else {
         (*l1) = konsb(*l1, val);
      }

      splitOddEven(tail(l), l1, l2);
   } 
}

void splitOnX (List l, int x, List *l1, List *l2){
   if (!isEmpty(l)) {
      if (x > 0) {
         (*l1) =  konsb(*l1, head(l));
      } else (*l2) =  konsb(*l2, head(l));

      splitOnX(tail(l), x - 1, l1, l2);
   }
}

ElType getMiddle(List l){
   if (!isEmpty(l)){
      int len = length(l) / 2;
      while (len != 0) {
         l = tail(l);
         len--;
      } return (head(l));
   }
}