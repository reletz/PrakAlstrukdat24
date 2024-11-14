#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include <math.h>

int main(){
    int N, i, j, len, k, count;
    char ch, temp;
    Stack s;
    CreateEmpty(&s);

    char str[10001];

    scanf("%d\n", &N);
    str[0] = '\0';

    // Start code here
    for (i = 0; i < N; i++){
        j = 0; len = 0; count = 0; k = 0;
        scanf("%c", &ch);
        if (ch != ']'){
            Push(&s, ch);
        } else {
            while (InfoTop(s) != '['){
                j++;
                Pop(&s, &str[j]);
            } len = j; Pop(&s, &temp);
            while(!IsEmpty(s)){
                if (InfoTop(s) < '0' || InfoTop(s) > '9'){
                    break;
                } else {
                    count += (InfoTop(s) - '0')*((int) pow(10, k));
                    k += 1;
                    Pop(&s, &temp);
                } 
            } 
            k = 0;
        }

        for (k = 0; k < count; k++){
            while (str[j] != '\0'){
                Push(&s, str[j]);
                j--;
            } j = len;
        }
        count = 0;
    }

    k = 0;
    while (!IsEmpty(s)){
        k++;
        Pop(&s, &ch);
        str[k] = ch;
    }

    while (k > 0){
        printf("%c", str[k]);
        k--;
    }

    printf("\n");
    return 0;
}