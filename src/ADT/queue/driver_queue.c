#include <stdio.h>
#include "queue.h"

int main() {
    /* Membuat queue kosong */
    Queue q;
    CreateQueue(&q);
    
    /* Mengecek dan memastikan bahwa queue sudah kosong */
    printf("Queue created.\n");

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    }
    
    /* Membuat beberapa barang untuk mengisi queue */
    Word barang1 = {"Platypus Laser", 14};
    Word barang2 = {"Shrink Ray", 10};
    Word barang3 = {"Net Shooter", 11};

    /* Menambah barang yang diminta kedalam queue */
    enqueue(&q, barang1);
    enqueue(&q, barang2);
    enqueue(&q, barang3);

    /* Menampilkan queue ke layar */
    printf("After enqueue operations:\n");
    displayQueue(q);

    /* Mengeluarkan barang pertama yang ada dalam antrian ke layar */
    ElTypeQueue HasilDequeue;
    dequeue(&q, &HasilDequeue);
    printf("Dequeued item: %s\n", HasilDequeue.TabWord);

    /* Menampilkan hasil queue setelah dequeue ke layar */
    displayQueue(q);
    
    /* Mengecek apakah queue sudah penuh */
    if (!isFull(q)) {
        printf("Queue belum penuh.\n");
    } else {
        printf("Queue sudah penuh\n");
    }

    return 0;
}
