#ifndef CUSTOM_H
#define CUSTOM_H

#include "boolean.h"


#define MAX_LEN 50
#define NIL -1

typedef struct {
char name[MAX_LEN];
char password[MAX_LEN];
int money;
} User;

extern User user;

typedef struct {
char name[MAX_LEN];
int price;
} Barang;

typedef struct {
char name[MAX_LEN][MAX_LEN];
char password[MAX_LEN][MAX_LEN];
int money;
} AllUser;

typedef struct {
char name[MAX_LEN][MAX_LEN];
int price[MAX_LEN];
} AllBarang;

#endif