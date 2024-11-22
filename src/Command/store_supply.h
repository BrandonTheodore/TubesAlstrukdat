#ifndef STORE_SUPPLY_H
#define STORE_SUPPLY_H

#include "queue.h"
#include "list.h"

//Fungsi untuk menyuplai barang ke toko
void store_supply(Queue *requestQueue, List *itemList);

#endif