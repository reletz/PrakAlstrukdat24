#include <stdio.h>
#include <string.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean isNumber() {
    return
    currentWord.Length == 3 && currentWord.TabWord[0] == 'n' && currentWord.TabWord[1] == 'o' && currentWord.TabWord[2] == 'l' 
    || 
    currentWord.Length == 4 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'a' && currentWord.TabWord[2] == 't' && currentWord.TabWord[3] == 'u'
    ||
    currentWord.Length == 3 && currentWord.TabWord[0] == 'd' && currentWord.TabWord[1] == 'u' && currentWord.TabWord[2] == 'a'
    ||
    currentWord.Length == 4 && currentWord.TabWord[0] == 't' && currentWord.TabWord[1] == 'i' && currentWord.TabWord[2] == 'g' && currentWord.TabWord[3] == 'a'
    ||
    currentWord.Length == 5 && currentWord.TabWord[0] == 'e' && currentWord.TabWord[1] == 'm' && currentWord.TabWord[2] == 'p' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 't'
    ||
    currentWord.Length == 4 && currentWord.TabWord[0] == 'l' && currentWord.TabWord[1] == 'i' && currentWord.TabWord[2] == 'm' && currentWord.TabWord[3] == 'a'
    ||
    currentWord.Length == 4 && currentWord.TabWord[0] == 'e' && currentWord.TabWord[1] == 'n' && currentWord.TabWord[2] == 'a' && currentWord.TabWord[3] == 'm'
    ||
    currentWord.Length == 5 && currentWord.TabWord[0] == 't' && currentWord.TabWord[1] == 'u' && currentWord.TabWord[2] == 'j' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'h'
    ||
    currentWord.Length == 7 && currentWord.TabWord[0] == 'd' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 'p' && currentWord.TabWord[5] == 'a' && currentWord.TabWord[6] == 'n'
    ||
    currentWord.Length == 8 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'm' && currentWord.TabWord[3] == 'b' && currentWord.TabWord[4] == 'i' && currentWord.TabWord[5] == 'l' && currentWord.TabWord[6] == 'a' && currentWord.TabWord[7] == 'n'
    ||
    currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'p' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'l' && currentWord.TabWord[5] == 'u' && currentWord.TabWord[6] == 'h'
    ||
    currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'b' && currentWord.TabWord[3] == 'e' && currentWord.TabWord[4] == 'l' && currentWord.TabWord[5] == 'a' && currentWord.TabWord[6] == 's'
    ||
    currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'r' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 't' && currentWord.TabWord[5] == 'u' && currentWord.TabWord[6] == 's';
}

boolean isTeen() {
    return currentWord.Length == 5 && currentWord.TabWord[0] == 'b' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 's';
}

boolean isTens() {
    return  currentWord.Length == 5 && currentWord.TabWord[0] == 'p' && currentWord.TabWord[1] == 'u' && currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'h';
}

boolean isHundreds() {
    return currentWord.Length == 5 && currentWord.TabWord[0] == 'r' && currentWord.TabWord[1] == 'a' && currentWord.TabWord[2] == 't' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 's';
}

void writePhrase() {
    int i;
    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
}

int convertNumber() {
    if (currentWord.Length == 3 && currentWord.TabWord[0] == 'n' && currentWord.TabWord[1] == 'o' && currentWord.TabWord[2] == 'l') {
        return 0;
    } else if (currentWord.Length == 4 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'a' && currentWord.TabWord[2] == 't' && currentWord.TabWord[3] == 'u') {
        return 1;
    } else if (currentWord.Length == 3 && currentWord.TabWord[0] == 'd' && currentWord.TabWord[1] == 'u' && currentWord.TabWord[2] == 'a') {
        return 2;
    } else if (currentWord.Length == 4 && currentWord.TabWord[0] == 't' && currentWord.TabWord[1] == 'i' && currentWord.TabWord[2] == 'g' && currentWord.TabWord[3] == 'a') {
        return 3;
    } else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'e' && currentWord.TabWord[1] == 'm' && currentWord.TabWord[2] == 'p' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 't') {
        return 4;
    } else if (currentWord.Length == 4 && currentWord.TabWord[0] == 'l' && currentWord.TabWord[1] == 'i' && currentWord.TabWord[2] == 'm' && currentWord.TabWord[3] == 'a') {
        return 5;
    } else if (currentWord.Length == 4 && currentWord.TabWord[0] == 'e' && currentWord.TabWord[1] == 'n' && currentWord.TabWord[2] == 'a' && currentWord.TabWord[3] == 'm') {
        return 6;
    } else if (currentWord.Length == 5 && currentWord.TabWord[0] == 't' && currentWord.TabWord[1] == 'u' && currentWord.TabWord[2] == 'j' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'h') {
        return 7;
    } else if (currentWord.Length == 7 && currentWord.TabWord[0] == 'd' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 'p' && currentWord.TabWord[5] == 'a' && currentWord.TabWord[6] == 'n') {
        return 8;
    } else if (currentWord.Length == 8 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'm' && currentWord.TabWord[3] == 'b' && currentWord.TabWord[4] == 'i' && currentWord.TabWord[5] == 'l' && currentWord.TabWord[6] == 'a' && currentWord.TabWord[7] == 'n') {
        return 9;
    } else if (currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'p' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'l' && currentWord.TabWord[5] == 'u' && currentWord.TabWord[6] == 'h') {
        return 10;
    } else if (currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'b' && currentWord.TabWord[3] == 'e' && currentWord.TabWord[4] == 'l' && currentWord.TabWord[5] == 'a' && currentWord.TabWord[6] == 's') {
        return 11;
    } else if (currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && currentWord.TabWord[2] == 'r' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 't' && currentWord.TabWord[5] == 'u' && currentWord.TabWord[6] == 's') {
        return 100;
    }
}

void processNumber() {
    int currentNumber, convertedNumber = 0;
    while (isNumber() && !EndWord) {
        currentNumber = convertNumber();
        ADVWORD();
        if (isTeen()) {
            currentNumber += 10;
            ADVWORD();
        } else if (isTens()) {
            currentNumber *= 10;
            ADVWORD();
        } else if (isHundreds()) {
            currentNumber *= 100;
            ADVWORD();
        }
        convertedNumber += currentNumber;
    }
    printf("%d", convertedNumber);
}

int main () {
    STARTWORD();
    while (!EndWord) {
        if (isNumber()) {
            processNumber();
        } else {
            writePhrase();
            ADVWORD();
        }
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}