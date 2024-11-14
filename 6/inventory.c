#include <stdio.h>
#include "boolean.h"
#include "stack.h"

// HINT: Gunakan (c - '0') untuk mengubah character ke angka
int charToInt(char c)
{
    return c - '0';
}

int main()
{
    int N, i, j, sum = 0, temp = 0;
    char ch;
    Stack s;
    CreateEmpty(&s);
    scanf("%d\n", &N);

    for (i = 0; i < N; i++){
        sum = 0, temp = 0;
        scanf("%c", &ch);
        if (ch == '+'){
            Pop(&s, &sum);
            Pop(&s, &temp);
            Push(&s, temp);
            Push(&s, sum);
            Push(&s, sum + temp);
        } else if (ch == 'X'){
            Pop(&s, &temp);
        } else if (ch == 'S'){
            while (!IsEmpty(s)){
                Pop(&s, &temp);
                sum += temp;
            } Push (&s, sum);
        } else if (ch == 'A'){
            j = 0;
            while (!IsEmpty(s)){
                Pop(&s, &temp);
                sum += temp;
                j++;
            } if (j == 0) Push (&s, 0);
            else Push (&s, sum/j);
        } else {
            Push(&s, charToInt(ch));
        }
    }

    sum = 0, temp;
    while (!IsEmpty(s)){
        Pop(&s, &temp);
        sum += temp;
    } printf("%d\n", sum);
    return 0;
}