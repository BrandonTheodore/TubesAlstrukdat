#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include "../master_header_command.h"

/* ********** CONSTANTS ********** */
#define MAX_STORE_ITEMS 100

/* ********** STRUCTURES ********** */

/* ********** FUNCTION DECLARATIONS ********** */

/* Inisialisasi Store */
// void InitStore(Store *S);

/* Menangani command STORE REQUEST */
void STORE_REQUEST();

/* Mengecek apakah barang dengan nama tertentu sudah ada di toko */
boolean IsItemInStore(ArrayDin S, char itemName[MAX_LEN]);

/* Mengecek apakah barang dengan nama tertentu sudah ada di antrian */
boolean IsItemInQueue(Queue S, char itemName[MAX_LEN]);

#endif