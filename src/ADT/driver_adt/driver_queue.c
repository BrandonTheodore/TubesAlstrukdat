#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    Queue q;
    Barang barang;

    // Test CreateQueue
    printf("Membuat queue kosong\n");
    CreateQueue(&q);
    printf("Queue berhasil dibuat\n\n");

    // Test isEmpty (should be true)
    printf("Apakah queue kosong? ");
    if (isEmpty(q)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    // Test enqueue
    printf("Menambahkan beberapa barang ke dalam queue\n");
    for (int i = 1; i <= 5; i++) {
        sprintf(barang.name, "Barang%d", i);
        barang.price = i * 1000;
        enqueue(&q, barang);
        printf("Menambahkan: Nama=%s, Harga=%d\n", barang.name, barang.price);
    }
    printf("\n");

    // Test displayQueue
    printf("Isi queue sekarang:\n");
    displayQueue(q);
    printf("\n");

    // Test length
    printf("Panjang queue: %d\n\n", length(q));

    // Test isFull
    printf("Apakah queue penuh? ");
    if (isFull(q)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    // Test dequeue
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

    // Test length again
    printf("Panjang queue sekarang: %d\n\n", length(q));

    // Test isEmpty (should be false)
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

    // Test isEmpty (should be true)
    printf("Apakah queue kosong sekarang? ");
    if (isEmpty(q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    return 0;
}