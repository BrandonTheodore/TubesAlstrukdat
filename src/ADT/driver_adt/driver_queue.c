#include <stdio.h>
#include "../queue.h"

int main() {
    Queue q;
    Barang barang;

    // Tes CreateQueue
    printf("Membuat queue kosong\n");
    CreateQueue(&q);
    printf("Queue berhasil dibuat\n\n");

    // Tes isEmpty
    printf("Apakah queue kosong? ");
    if (isEmpty(q)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    // Tes enqueue
    printf("Menambahkan beberapa barang ke dalam queue\n");
    for (int i = 1; i <= 5; i++) {
        barang.id = i;
        sprintf(barang.nama, "barang%d", i);
        barang.harga = i * 1000;
        enqueue(&q, barang);
        printf("Menambahkan: ID=%d, Nama=%s, Harga=%d\n", barang.id, barang.nama, barang.harga);
    }
    printf("\n");

    // Tes displayQueue
    printf("Isi queue sekarang: ");
    displayQueue(q);
    printf("\n\n");

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
        printf("barang yang dihapus: ID=%d, Nama=%s, Harga=%d\n", barang.id, barang.nama, barang.harga);
    }
    printf("\n");

    // Display queue setelah dequeue
    printf("Isi queue setelah penghapusan: ");
    displayQueue(q);
    printf("\n\n");

    // Tes length again
    printf("Panjang queue sekarang: %d\n\n", length(q));

    // Tes isEmpty
    printf("Apakah queue kosong sekarang? ");
    if (isEmpty(q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    // Dequeue remaining barang
    printf("Menghapus sisa barang dari queue...\n");
    while (!isEmpty(q)) {
        dequeue(&q, &barang);
        printf("barang yang dihapus: ID=%d, Nama=%s, Harga=%d\n", barang.id, barang.nama, barang.harga);
    }
    printf("\n");

    // Tes isEmpty
    printf("Apakah queue kosong sekarang? ");
    if (isEmpty(q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    return 0;
}
