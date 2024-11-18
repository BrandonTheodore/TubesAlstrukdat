#include "boolean.h"
#include <stdio.h>

#ifndef SALDO_H
#define SALDO_H

typedef struct {
    int userId;
    int saldo;
} SaldoData;

// mengupdate saldo 
void updateSaldoInFile(int userId, int additionalAmount);

//mengabil saldo pengguna
int getCurrentSaldo(int userId);

#endif


