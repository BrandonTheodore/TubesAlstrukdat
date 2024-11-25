#include "store_supply.h"
#include <stdio.h>
#include <stdlib.h>

Queue queue;
ArrayDin AD;

void STORE_SUPPLY() {
    if (isEmpty(queue)) {
        printf("Tidak ada barang dalam antrian.\n");
    } else {
        Barang barang;
        dequeue(&queue, &barang);

        // Tampilan
        printf("Apakah kamu ingin menambahkan barang %s: ", barang.name);
        STARTWORD2();
        char command[50];
        int i = 0;
        while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
            command[i] = currentWord.TabWord[i];
            (&currentWord)->TabWord[i] = '\0';
            i++;
        }
        command[i] = '\0';
        (&currentWord)->TabWord[i] = '\0';

        // Evaluasi keputusan pengguna
        if (isEqual(command, "Terima")) {
            // Validasi harga barang
            printf("Harga barang: ");
            STARTWORD2();
            char price[50];
            int i = 0;
            while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
                price[i] = currentWord.TabWord[i];
                (&currentWord)->TabWord[i] = '\0';
                i++;
            }
            price[i] = '\0';
            (&currentWord)->TabWord[i] = '\0';

            // Konversi input harga ke integer
            int harga = atoi(price);
            if (harga <= 0) {
                printf("Harga tidak valid. Balik ke menu.\n");
                enqueue(&queue, barang); // Kembalikan ke antrian
            } else {
                // Tambahkan barang ke toko
                barang.price = harga;

                InsertLastDin(&AD, barang.name, barang.price);
                printf("%s dengan harga %d telah ditambahkan ke toko.\n", barang.name, harga);
            }

        } else if (isEqual(command, "Tunda")) {
            // Kembalikan barang ke antrian
            enqueue(&queue, barang);
            printf("%s dikembalikan ke antrian.\n", barang.name);

        } else if (isEqual(command, "Tolak")) {
            // Hapus barang dari antrian
            printf("%s dihapuskan dari antrian.\n", barang.name);

        } else {
            // Input tidak valid
            printf("< Balik ke menu >\n");
            enqueue(&queue, barang);; // Kembalikan barang ke antrian
        }
    }
}