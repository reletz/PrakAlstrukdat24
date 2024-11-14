#include "boolean.h"
#include "stack.h"
#include <stdio.h>

int main(){
    int N, i;
    scanf("%d", &N);
    
    char c[N+1];
    char s[N];
    for (i = 0; i < N+1; i++) {
        scanf("%c", &c[i]);
    }

    for (i = 0; i < N; i++) {
        s[i] = c[i+1];
    }

    if (N < 2) {
        printf("Invalid\n");
        return 0;
    } 

    Stack S;
    CreateEmpty(&S);
    for (i = 0; i < N; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') Push(&S, s[i]);
        else {
            if (s[i] == ')'){
                if (InfoTop(S) == '(') Pop(&S, &s[i]);
                else {
                    printf("Invalid\n");
                    return 0;
                }
            } else if (s[i] == '}'){
                if (InfoTop(S) == '{') Pop(&S, &s[i]);
                else {
                    printf("Invalid\n");
                    return 0;
                }
            } else if (s[i] == ']'){
                if (InfoTop(S) == '[') Pop(&S, &s[i]);
                else {
                    printf("Invalid\n");
                    return 0;
                }
            }
        }
    } if (IsEmpty(S)) printf("Valid\n");
    else printf("Invalid\n");

    return 0;
}