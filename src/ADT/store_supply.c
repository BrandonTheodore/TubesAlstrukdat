#include "store_supply.h"
#include <stdio.h>

void StoreSupply(Queue *antrian, List *toko) {
    if (isEmpty(*antrian)) {
        printf("Tidak ada barang dalam antrian.\n");
        return;
    }

    // Ambil barang paling depan dalam antrian
    Barang barang;
    dequeue(antrian, (ElType *)&barang);

    // Tampilan
    printf("Apakah kamu ingin menambahkan barang %s: ", barang.name);
    STARTWORD2();

    // Konversi input dari pengguna ke lowercase 
    for (int i = 0; i < currentWord.Length; i++) {
        if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z') {
            currentWord.TabWord[i] += 32;
        }
    }
    currentWord.TabWord[currentWord.Length] = '\0';

    // Evaluasi keputusan pengguna
    if (isEqual(currentWord.TabWord, "terima")) {
        // Validasi harga barang
        printf("Harga barang: ");
        STARTWORD2();

        // Konversi input harga ke integer
        int harga = wordToInt();
        if (harga <= 0) {
            printf("Harga tidak valid. Balik ke menu.\n");
            enqueue(antrian, (ElType)barang); // Kembalikan ke antrian
            return;
        }

        // Tambahkan barang ke toko
        Barang newBarang;
        for (int i = 0; barang.name[i] != '\0'; i++) {
            newBarang.name[i] = barang.name[i];
        }
        newBarang.price = harga;

        InsertLast(toko, (ElType)&newBarang);
        printf("%s dengan harga %d telah ditambahkan ke toko.\n", barang.name, harga);

    } else if (isEqual(currentWord.TabWord, "tunda")) {
        // Kembalikan barang ke antrian
        enqueue(antrian, (ElType)barang);
        printf("%s dikembalikan ke antrian.\n", barang.name);

    } else if (isEqual(currentWord.TabWord, "tolak")) {
        // Hapus barang dari antrian
        printf("%s dihapuskan dari antrian.\n", barang.name);

    } else {
        // Input tidak valid
        printf("< Balik ke menu >\n");
        enqueue(antrian, (ElType)barang); // Kembalikan barang ke antrian
    }
}
