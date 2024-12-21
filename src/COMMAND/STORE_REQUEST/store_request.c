#include "store_request.h"
#include <stdio.h>

Queue queue;
ArrayDin AD;

/* Mengecek apakah barang dengan nama tertentu sudah ada di toko */
boolean IsItemInStore(ArrayDin S, char itemName[MAX_LEN]) {
    for (int i = 0; i < S.Neff; i++) {
        if (isEqual(S.A[i].name, itemName)) {
            return true; // Barang ada di toko
        }
    }
    return false; // Barang tidak ada di toko
}

/* Mengecek barang yang sudah ada di antrian */
boolean IsItemInQueue(Queue S, char itemName[MAX_LEN]) {
    for (int i = 0; i <= IDX_HEAD(S); i++) {
        if (isEqual(S.buffer[i].name, itemName)) {
            return true; // Barang ada di antrian
        }
    }
    return false; // Barang tidak ada di antrian
}

/* STORE REQUEST */
void STORE_REQUEST() {
    CreateQueue(&queue);
    // Membaca input nama barang
    printf("Nama barang yang diminta: ");
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

    // Periksa barang yang sudah ada di toko
    if (IsItemInStore(AD, command)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    } else if (IsItemInQueue(queue, command)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    } else {
        Barang newItem;
        int cnt = 0;
        for (int i = 0; command[i] != '\0'; i++) {
            newItem.name[i] = command[i];
            cnt++;
        }
        newItem.name[cnt] = '\0'; 
        newItem.price = 0;

        if (isFull(queue)) {
            printf("Antrian penuh! Tidak dapat menambahkan barang baru.\n");
        } else {
            enqueue(&queue, newItem);
            printf("Barang %s berhasil dimasukkan ke dalam antrian.\n", newItem.name);
        }
    }
}
