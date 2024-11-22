#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "LOAD.h"

boolean load;

void MULAI(){
    if(load){
        printf("Selamat datang di PURRMART!\nSilakan masukan perintah anda!\n>>>");
        STARTWORD2();
    } else if (!load){
        LOAD("default.txt");
    }
}