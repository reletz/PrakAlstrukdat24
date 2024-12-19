#ifndef LISTREC_H
#define LISTREC_H

#include "boolean.h"
#include <stdio.h>

#define NIL NULL

typedef int ElType;
typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next;
} Node;

typedef Address List;

/* Selektor */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

/* Manajemen Memori */
Address newNode(ElType x);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l);
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isOneElmt(List l);
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l);
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l);
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e);
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e);
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 

List insertAt (List l, ElType e, int i);
/* I.S. l mungkin kosong, i menunjukkan indeks yang valid. */
/* F.S. e dimasukkan pada indeks ke-i pada l. */
/* Proses: Jika alokasi gagal, l tetap. */
/* Contoh: Jika l adalah 1 2 3 4 5, dan e = 6, dan i = 3, maka l menjadi 1 2 6 3 4 5. */

List deleteFirst(List l, ElType *e);
/* I.S. l tidak kosong */
/* F.S. e adalah elemen pertama l sebelum penghapusan */
/*      elemen pertama l dihapus dari list l */
/*      Jika l menjadi kosong, l berisi NIL */

List deleteAt(List l, int i, ElType *e);
/* I.S. l tidak kosong, i adalah indeks posisi elemen yang dihapus */
/* F.S. e adalah elemen pada indeks ke-i sebelum penghapusan */
/*      Elemen pada indeks ke-i dihapus dari list l */
/*      Jika l menjadi kosong, l berisi NIL */
/*      Jika i < 0 atau i > length(l), l tetap dan e = -1 */

List deleteLast(List l, ElType *e);
/* I.S. l tidak kosong */
/* F.S. e adalah elemen terakhir l sebelum penghapusan */
/*      Elemen terakhir l dihapus */
/*      Jika l menjadi kosong, l berisi NIL */

List copy(List l);
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
List concat(List l1, List l2);
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

/* Fungsi dan Prosedur Lain */
int length(List l);
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */

boolean isMember(List l, ElType x);
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */

List inverseList(List l);
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen l dari ujung ke ujung */

void splitPosNeg(List l, List *l1, List *l2);
/* I.S. l sembarang */
/* F.S. l1 berisi semua elemen l yang positif atau 0, l2 berisi semua elemen l yang negatif */

void splitOnX(List l, ElType X, List *l1, List *l2);
/* I.S. l sembarang */
/* F.S. Jika ada elemen l yang berisi X, maka l1 berisi semua elemen l yang sebelum elemen yang berisi X, dan l2 berisi semua elemen l yang setelah elemen yang berisi X. Jika tidak ada elemen l yang berisi X, maka l1 berisi semua elemen l dan l2 kosong. */

List removeDuplicate(List l);
/* Mengirimkan list baru yang merupakan l dengan semua elemen yang duplikasi dihapus */

void displayList(List l);
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

#endif