#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n; scanf("%d", &n);
    PrioQueue q1;
    PrioQueue q2;
    CreatePrioQueue(&q1);
    CreatePrioQueue(&q2);

    int a;
    int b;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        enqueue(&q1, a);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &b);
        enqueue(&q2, b);
    }

    long long ans = 0;
    long long x, y;
    while (!isEmpty(q1)){
        dequeue(&q1, &x);
        dequeue(&q2, &y);
        ans += x*y;
    }

    printf("%lld\n", ans);
}