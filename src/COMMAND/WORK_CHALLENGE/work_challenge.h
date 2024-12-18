#ifndef WORKCHALLANGE_H
#define WORKCHALLANGE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../master_header_command.h"
#include "../../ADT/master_header_adt.h"

// Konstanta
#define TA_COST 200
#define W_COST 500
#define QUANTUM_COST 1000

// saldo global
extern int global_Saldo; 

// menampilkan daftar permainan
void displayWorkChallenge();

// manampilkan dan memasukan ke dalam pemainan yang dipilih oleh pengguna
void selectChallenge();

#endif