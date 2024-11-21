#include <stdio.h>
#include "queue.h"

int main() {
    int n;
    scanf("%d", &n);

    // Lakukan inisialisasi Queue disini
    Queue q;
    CreateQueue(&q);

    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);
        // Kerjakan keempat tipe query disini
        if (op == 1) {
            int val;
            scanf("%d", &val);
            if (!isFull(q)){
                enqueue(&q, val);
                printf("Enqueue %d Berhasil\n", val);
            } else printf("Queue Penuh\n");
        } else if (op == 2) {
            int temp;
            if (isEmpty(q)) printf("Queue Kosong\n");
            else {
                dequeue(&q, &temp);
                printf("Dequeue %d Berhasil\n", temp);
            }
        } else if (op == 3) {
            if (isEmpty(q)) printf("Queue Kosong\n");
            else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
        } else if (op == 4) {
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
    }

    displayQueue(q);
    return 0;
}