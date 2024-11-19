#ifndef STORE_SUPPLY_H
#define STORE_SUPPLY_H

#include "store.h"

//Fungsi untuk menyuplai barang ke toko
void store_supply(Store *store, User *user, const char *itemName, int quantity);

#endif