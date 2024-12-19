#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    /* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
    Menghasilkan pohon kosong (NULL) jika alokasi gagal */

    BinTree tree = newTreeNode(root);
    if (tree != NULL){
        LEFT(tree) = left_tree;
        RIGHT(tree) = right_tree;
    }
    return tree;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    /* I.S. Sembarang
    F.S. Menghasilkan sebuah pohon p
    Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
    berhasil 
    Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val){
    /* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
    /* Mengirimkan address hasil alokasi sebuah elemen bernilai val
    Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
    menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
    Jika alokasi gagal, mengirimkan NULL */

    Address node = (Address) malloc(sizeof(TreeNode));
    if (node != NULL){
        ROOT(node) = val;
        LEFT(node) = NULL;
        RIGHT(node) = NULL;
    }
    return node;
}

void deallocTreeNode (Address p){
    /* I.S. p terdefinisi 
    F.S. p dikembalikan ke sistem 
    Melakukan dealokasi/pengembalian address p */

    free(p);
}

boolean isTreeEmpty (BinTree p){
    /* Mengirimkan true jika p adalah pohon biner yang kosong */

    return p == NULL;
}

boolean isOneElmt (BinTree p){
    /* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL;
}

boolean isUnerLeft (BinTree p){
    /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
    hanya mempunyai subpohon kiri */

    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL;
}

boolean isUnerRight (BinTree p){
    /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
    hanya mempunyai subpohon kanan */

    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL;
}

boolean isBinary (BinTree p){
    /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
    mempunyai subpohon kiri dan subpohon kanan */

    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL;
}


/* ****** Display Tree ***** */
void printPreorder(BinTree p){
    /* I.S. p terdefinisi */
    /* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (A()()) adalah pohon dengan 1 elemen dengan akar A
    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

    if (isTreeEmpty(p)){
        printf("()");
    } else {
        printf("(%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}

void printInorder(BinTree p){
    /* I.S. p terdefinisi */
    /* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (()A()) adalah pohon dengan 1 elemen dengan akar A
    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

    if (isTreeEmpty(p)){
        printf("()");
    } else {
        printf("(");
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}

void printPostorder(BinTree p){
    /* I.S. p terdefinisi */
    /* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (()()A) adalah pohon dengan 1 elemen dengan akar A
    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

    if (isTreeEmpty(p)){
        printf("()");
    } else {
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d)", ROOT(p));
    }
}

void pDepth(BinTree p, int h, int depth){
    if(!isTreeEmpty(p)){
        int i;

        for (i = 0; i < h * depth; i++){
            printf(" ");
        }

        printf("%d\n", ROOT(p));
        pDepth(LEFT(p), h, depth+1);
        pDepth(RIGHT(p), h, depth+1);
    }
}

void printTree(BinTree p, int h){
    /* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
    /* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
    /* Penulisan akar selalu pada baris baru (diakhiri newline) */
    /* Contoh, jika h = 2: 
    1) Pohon preorder: (A()()) akan ditulis sbb:
    A
    2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
    A
    B
    C
    3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
    A
    B
        D
    C
        E
    Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
    */

    pDepth(p, h, 0);
}

boolean isEqual(BinTree p1, BinTree p2){
    if (isTreeEmpty(p1) && isTreeEmpty(p2)) return true;
    if (isTreeEmpty(p1) && !isTreeEmpty(p2)) return false;
    if (!isTreeEmpty(p1) && isTreeEmpty(p2)) return false;

    if (ROOT(p1) != ROOT(p2)) return false;
    return isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2));
}

int getMaximumDepth(BinTree p){
    int left;
    if (isTreeEmpty(LEFT(p))) left = 1;
    else left = 1 + getMaximumDepth(LEFT(p));

    int right;
    if (isTreeEmpty(RIGHT(p))) right = 1;
    else right = 1 + getMaximumDepth(RIGHT(p));

    return (left > right) ? left : right;
}

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end){
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;

    BinTree left = createBinSearchTreeFromSortedArray(arr, start, mid-1);
    BinTree right = createBinSearchTreeFromSortedArray(arr, mid+1, end);
    BinTree rootNow = NewTree(arr[mid], left, right);

    return rootNow;
}

int countNodes(BinTree p){
    if (p == NULL) return 0;
    return (1 + countNodes(LEFT(p)) + countNodes(RIGHT(p)));
}

boolean searchTarget(BinTree p, ElType target) {
    if (p == NULL) return false;
    if (ROOT(p) == target) return true;
    else {
        boolean found = 0;
        if (LEFT(p) != NULL) found |= searchTarget(LEFT(p), target);
        if (RIGHT(p) != NULL) found |= searchTarget(RIGHT(p), target);

        return found;
    }
}

void printPathToElement(BinTree p, ElType target) {
    if (!searchTarget(p, target)) {
        printf("-1\n");
        return;
    }

    if (ROOT(p) == target) {
    printf("%d\n", ROOT(p));
    return;
    }
    else {
        if (searchTarget(LEFT(p), target)) {
            printf("%d -> ", ROOT(p));
            printPathToElement(LEFT(p), target);
        } 
        else {
            printf("%d -> ", ROOT(p));
            printPathToElement(RIGHT(p), target);
        }
    }
}



