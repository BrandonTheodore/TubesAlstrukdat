#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    Queue q;
    Barang barang;

    // Tes CreateQueue
    printf("Membuat queue kosong\n");
    CreateQueue(&q);
    printf("Queue berhasil dibuat\n\n");

    // Tes isEmpty (should be true)
    printf("Apakah queue kosong? ");
    if (isEmpty(q)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    // Tes enqueue
    printf("Menambahkan beberapa barang ke dalam queue\n");
    for (int i = 1; i <= 5; i++) {
        sprintf(barang.name, "Barang%d", i);
        barang.price = i * 1000;
        enqueue(&q, barang);
        printf("Menambahkan: Nama=%s, Harga=%d\n", barang.name, barang.price);
    }
    printf("\n");

    // Tes displayQueue
    printf("Isi dari queue sekarang:\n");
    displayQueue(q);
    printf("\n");

    // Tes length
    printf("Panjang queue: %d\n\n", length(q));

    // Tes isFull
    printf("Apakah queue penuh? ");
    if (isFull(q)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    // Tes dequeue
    printf("Menghapus beberapa barang dari queue...\n");
    for (int i = 0; i < 3; i++) {
        dequeue(&q, &barang);
        printf("Barang yang dihapus: Nama=%s, Harga=%d\n", barang.name, barang.price);
    }
    printf("\n");

    // Display queue after dequeue
    printf("Isi queue setelah penghapusan:\n");
    displayQueue(q);
    printf("\n");

    // Tes length again
    printf("Panjang queue sekarang: %d\n\n", length(q));

    // Tes isEmpty (should be false)
    printf("Apakah queue kosong sekarang? ");
    if (isEmpty(q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");

    // Dequeue remaining items
    printf("Menghapus sisa barang dari queue...\n");
    while (!isEmpty(q)) {
        dequeue(&q, &barang);
        printf("Barang yang dihapus: Nama=%s, Harga=%d\n", barang.name, barang.price);
    }
    printf("\n");

    // Tes isEmpty (should be true)
    printf("Apakah queue kosong? ");
    if (isEmpty(q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    return 0;
}