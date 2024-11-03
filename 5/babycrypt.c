#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>

int exps(int a, int b){
    int i, temp = a;
    if (b == 0) return 1;
    if (b == 1) return a;
    a = a*temp;
    for (i = 2; i < b; i++){
        a = a * temp;
    } return a;
}

void writeShift(int shift){
    int i;
    char newC;
    for (i = 0; i < currentWord.Length; i++){
        int temp = (int) currentWord.TabWord[i];
        if ((temp <= 90 && temp >= 65)){
            newC = (-(shift % 26) + currentWord.TabWord[i]);
            if (newC <= 64) newC += 26;
            newC = (char) newC;
        } else if (temp <= 122 && temp >= 97){
            newC = (-(shift % 26) + currentWord.TabWord[i]);
            if (newC <= 96) newC += 26;
            newC = (char) newC;
        } else newC = currentWord.TabWord[i];
        printf("%c", newC);
        
    }
}
//65 itu awalnya, akhirnya 90
//97 itu awalnya, akhirnya 122

int main(){
    int i;
    STARTWORD();
    int shifter = 0;
    for (i = 0; i < currentWord.Length; i++){
        shifter += ((int) currentWord.TabWord[i] - 48) * exps(10, currentWord.Length - i - 1);
    } ADVWORD();
    int ctr = 0;
    while (!EndWord) {
        writeShift(shifter);
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}