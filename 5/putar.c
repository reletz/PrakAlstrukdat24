#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>

void writeReverse(){
    int i;
    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[currentWord.Length - i - 1]);
    }
}

void writeNormal() {
    int i;
    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
}

int main () {
    int ctr = 0;
    STARTWORD();
    while (!EndWord) {
        if (ctr % 2 == 0) {
            writeReverse();
        } else {
            writeNormal();
        } ctr += 1;
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}