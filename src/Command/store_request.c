#include "store_request.h"
#include <stdio.h>

/* Inisialisasi Store */
void InitStore(Store *S) {
    // Inisialisasi daftar barang di toko
    *S = (Store){MakeList(), {IDX_UNDEF, IDX_UNDEF}};
    CreateQueue(&(S->requestedItems));
}

/* Mengecek apakah barang dengan nama tertentu sudah ada di toko */
boolean IsItemInStore(Store S, char itemName[MAX_LEN]) {
    for (int i = FirstIdx(S.storeItems); i <= LastIdx(S.storeItems); i++) {
        char *currentItemName = (char *)Get(S.storeItems, i);
        if (isEqual(currentItemName, itemName)) {
            return true; // Barang ada di toko
        }
    }
    return false; // Barang tidak ada di toko
}

/* Mengecek barang yang sudah ada di antrian */
boolean IsItemInQueue(Store S, char itemName[MAX_LEN]) {
    for (int i = 0; i < length(S.requestedItems); i++) {
        Barang currentItem = S.requestedItems.buffer[(S.requestedItems.idxHead + i) % CAPACITY];
        if (isEqual(currentItem.name, itemName)) {
            return true; // Barang ada di antrian
        }
    }
    return false; // Barang tidak ada di antrian
}

/* STORE REQUEST */
void StoreRequest(Store *S) {
    // Membaca input nama barang
    printf("Nama barang yang diminta: ");
    STARTWORD2(); 
    char requestedName[MAX_LEN];
    for (int i = 0; i < currentWord.Length; i++) {
        requestedName[i] = currentWord.TabWord[i];
    }
    requestedName[currentWord.Length] = '\0'; 

    // Periksa barang yang sudah ada di toko
    if (IsItemInStore(*S, requestedName)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    // Periksa barang yang sudah ada di antrian
    if (IsItemInQueue(*S, requestedName)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    }

    // Masukkan barang ke dalam antrian
    Barang newItem;
    for (int i = 0; i < currentWord.Length; i++) {
        newItem.name[i] = currentWord.TabWord[i];
    }
    newItem.name[currentWord.Length] = '\0'; 

    if (isFull(S->requestedItems)) {
        printf("Antrian penuh! Tidak dapat menambahkan barang baru.\n");
        return;
    }
    enqueue(&(S->requestedItems), newItem);
    printf("Barang %s berhasil dimasukkan ke dalam antrian.\n", newItem.name);
}
