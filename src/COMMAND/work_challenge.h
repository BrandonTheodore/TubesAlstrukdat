#ifndef WORKCHALLANGE_H
#define WORKCHALLANGE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "tebakangka.h"
#include "wordl3.h"
#include "quantum.h"

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