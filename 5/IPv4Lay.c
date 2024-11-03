#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>

boolean disectIP(){
    int i, isValid, num, ctr, first;
    isValid = 1;
    num = 0;
    ctr = 0;
    first = 1;
    for (i = 0; i <= currentWord.Length; i++) {
        if (i == currentWord.Length || currentWord.TabWord[i] == '@') {
            if (first) isValid = 0;
            if (num > 255) isValid = 0;

            first = 1;
            num = 0;
            ctr++;
            continue;
        }
        if (currentWord.TabWord[i] - '0' >= 0 && currentWord.TabWord[i] - '0' <= 9)  {
            if (first) first = 0;
            else if (num == 0) isValid = 0;
            num *= 10;
            num += currentWord.TabWord[i] - '0';
        }
    else isValid = 0;
    } return isValid && ctr == 4;
}

int main () {
    boolean ip;
    STARTWORD();
    while (!EndWord) {
        if (disectIP()){
            printf("4Lay");
        } else {
            printf("ewh");
        }
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}