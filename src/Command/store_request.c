#include "store_request.h"
#include <stdio.h>
ArrayDin AD;
Queue queue;
/* Inisialisasi Store */
// void InitStore(Store *S) {
//     // Inisialisasi daftar barang di toko
//     *S = (Store){MakeList(), {IDX_UNDEF, IDX_UNDEF}};
//     CreateQueue(&(S->requestedItems));
// }

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
    for (int i = IDX_HEAD(S); i <= IDX_TAIL(S); i++) {
        if (isEqual(S.buffer[i], itemName)) {
            return true; // Barang ada di antrian
        }
    }
    return false; // Barang tidak ada di antrian
}

/* STORE REQUEST */
void StoreRequest() {
    // Membaca input nama barang
    printf("Nama barang yang diminta: ");
    STARTWORD2(); 
    char requestedName[MAX_LEN];
    for (int i = 0; i < currentWord.Length; i++) {
        requestedName[i] = currentWord.TabWord[i];

    }
    requestedName[currentWord.Length] = '\0'; 

    // Periksa barang yang sudah ada di toko
    if (IsItemInStore(AD, requestedName)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    // Periksa barang yang sudah ada di antrian
    if (IsItemInQueue(queue, requestedName)) {
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
