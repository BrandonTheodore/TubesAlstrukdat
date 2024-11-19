#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include "queue.h"
#include "list.h"
#include "barang.h"

// Fungsi untuk memproses permintaan barang dari user
void store_request(List *itemList, Queue *requestQueue, char *itemName);

#endif