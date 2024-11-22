#ifndef LOAD_H
#define LOAD_H

#include "boolean.h"

extern boolean load;

#define MAX_LEN 50

typedef struct {
char name[MAX_LEN];
char password[MAX_LEN];
int money;
} User;

typedef struct {
char name[MAX_LEN];
int price;
} Barang;

typedef struct {
    User TotUs[MAX_LEN];
    Barang TotBar[MAX_LEN];
} Total;


void LOAD();

#endif