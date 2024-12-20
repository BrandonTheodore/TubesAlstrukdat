#include <stdio.h>
#include "mesinkarakter.h"
#include "../../COMMAND/LOAD/LOAD.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START() {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}

void reset() {
    if (pita != NULL) {
        rewind(pita);
    }
}

void adv_baris() {
    int result = fscanf(pita, "%c", &currentChar);
    EOP = (result == EOF);
    if (EOP){
        fclose(pita);
    }
}
void start_files(char *filename) {
    pita = fopen(filename, "r");
    if (pita == NULL) {
        printf("File tidak ditemukan\n");
        load = false;
    } 
    else {
        ADV();
        load = true;
    }
}