#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include "custom.h"
#include "List.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "queue.h"
#include "boolean.h"

/* ********** CONSTANTS ********** */
#define MAX_STORE_ITEMS 100

/* ********** STRUCTURES ********** */
typedef struct {
    List storeItems;         // Daftar barang di toko (menggunakan ADT List)
    Queue requestedItems;    // Antrian barang yang diminta (menggunakan ADT Queue)
} Store;

/* ********** FUNCTION DECLARATIONS ********** */

/* Inisialisasi Store */
void InitStore(Store *S);

/* Menangani command STORE REQUEST */
void StoreRequest(Store *S);

/* Mengecek apakah barang dengan nama tertentu sudah ada di toko */
boolean IsItemInStore(Store S, char itemName[MAX_LEN]);

/* Mengecek apakah barang dengan nama tertentu sudah ada di antrian */
boolean IsItemInQueue(Store S, char itemName[MAX_LEN]);

#endif
