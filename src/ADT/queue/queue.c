#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    return IDX_TAIL(q) == (CAPACITY - 1);
}

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

void enqueue(Queue *Q, Barang val) {
    if (isFull(*Q)) {
        printf("Queue penuh!\n");
        return;
    }

    if (isEmpty(*Q)) {
        Q->idxHead = 0;
        Q->idxTail = 0;
    } else {
        Q->idxTail = (Q->idxTail + 1) % CAPACITY;
    }
    
    Q->buffer[Q->idxTail] = val;
}

void dequeue(Queue *Q, Barang *val) {
    if (isEmpty(*Q)) {
        printf("Queue kosong!\n");
        return;
    }

    *val = Q->buffer[Q->idxHead];
    
    if (Q->idxHead == Q->idxTail) {
        Q->idxHead = IDX_UNDEF;
        Q->idxTail = IDX_UNDEF;
    } else {
        Q->idxHead = (Q->idxHead + 1) % CAPACITY;
    }
}

// void displayQueue(Queue q)
// {
//     if (isEmpty(q))
//     {
//         printf("[]\n");
//     }
//     else
//     {
//         int i;
//         printf("[");
//         for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
//         {
//             printf("%d,", q.buffer[i]);
//         }
//         printf("%d]\n", TAIL(q));
//     }
// }
