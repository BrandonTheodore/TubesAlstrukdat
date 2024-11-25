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

void enqueue(Queue *q, Barang val)
{
    if (isFull(*q))
    {
        printf("Antrian Penuh!\n");
    }
    else
    {
        if (isEmpty(*q))
        {
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1);
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, Barang *val)
{
    if (isEmpty(*q))
    {
        printf("Antrian kosong!\n");
    }
    else
    {
        *val = HEAD(*q);
        for(int i = IDX_HEAD(*q); i < IDX_TAIL(*q); i++){
            (*q).buffer[i] = q->buffer[i + 1];
        }
        IDX_TAIL(*q) -= 1;
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
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
