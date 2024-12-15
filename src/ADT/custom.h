#ifndef CUSTOM_H
#define CUSTOM_H

#include "master_header_adt.h"


#define MAX_LEN 50
#define NIL -1

typedef struct {
char name[MAX_LEN];
char password[MAX_LEN];
int money;
char nickname[MAX_LEN];
int umur;
Map keranjang;
Stack riwayat_pembelian;
List wishlist;
} User;

extern User user;

typedef struct {
char name[MAX_LEN];
int price;
} Barang;

#endif
