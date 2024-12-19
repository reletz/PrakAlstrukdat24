#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>

void invertTree(BinTree *p) {
    Address P, Q;
    if (!isTreeEmpty(*p)) {
        P = RIGHT(*p);
        Q = LEFT(*p);
        LEFT(*p) = P;
        RIGHT(*p) = Q;
        invertTree(&LEFT(*p));
        invertTree(&RIGHT(*p));
    }
}