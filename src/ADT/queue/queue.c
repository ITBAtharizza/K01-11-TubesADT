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
    return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY;
}

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

void enqueue(Queue *q, ElTypeQueue val)
{
    if (isFull(*q))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (isEmpty(*q)) 
        {
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = 0;
            HEAD(*q) = val; 
        }
        else if (!isMemberQueue(*q, val)) 
        {
            IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
            TAIL(*q) = val; 
        }
    }
}


void dequeue(Queue *q, ElTypeQueue *val)
{
    if (isEmpty(*q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}


void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("ANTRIAN KOSONG!\n\n");
    } else {
        int i, count = 1;
        printf("ISI ANTRIAN:\n");
        printf("============================================================\n");
        printf("| %-3s | %-50s |\n", "No", "Content");
        printf("============================================================\n");

        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY) {
            printf("| %-3d | %-50s |\n", count++, q.buffer[i].TabWord);
        }
        printf("| %-3d | %-50s |\n", count, TAIL(q).TabWord);
        printf("============================================================\n");
    }
}


int isMemberQueue(Queue q, ElTypeQueue val)
{
    if (isEmpty(q)) return 0;

    for (int i = IDX_HEAD(q);; i = (i + 1) % CAPACITY)
    {
        if (IsSameString(q.buffer[i].TabWord, val.TabWord))
        {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
            return 1;
        }
        if (i == IDX_TAIL(q)) break;
    }
    return 0;
}
