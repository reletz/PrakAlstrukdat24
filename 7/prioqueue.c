#include <stdio.h>
#include "boolean.h"
#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *q){
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue q){
  return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(PrioQueue q){
  return ((IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q));
}

int length(PrioQueue q){
  if (isEmpty(q)){
    return 0;
  } else if (IDX_TAIL(q) >= IDX_HEAD(q)){
    return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
  } return (CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1);
}

void enqueue(PrioQueue *q, ElType val){
  if (isEmpty(*q)){
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    TAIL(*q) = val;
  } else {
    int i = IDX_TAIL(*q);
    while (i != IDX_HEAD(*q) && q->buffer[i] < val){
      q->buffer[(i + 1) % CAPACITY] = q->buffer[i];
      i = (i - 1 + CAPACITY) % CAPACITY;
    } if (i == IDX_HEAD(*q) && q->buffer[i] < val){
      q->buffer[(i + 1) % CAPACITY] = q->buffer[i];
      i = (i - 1 + CAPACITY) % CAPACITY;
    }
    q->buffer[(i + 1) % CAPACITY] = val;
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
  }
}

void dequeue(PrioQueue *q, ElType *val){
  *val = HEAD(*q);
  if (IDX_HEAD(*q) == IDX_TAIL(*q)){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
  } else {
    IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
  }
}

void displayPrioQueue(PrioQueue q){
  if (isEmpty(q)){
    printf("[]\n");
  } else {
    printf("[");
    int i = IDX_HEAD(q);
    while (i != IDX_TAIL(q)){
      printf("%d,", q.buffer[i]);
      i = (i + 1) % CAPACITY;
    } printf("%d]\n", q.buffer[IDX_TAIL(q)]);
  }
}