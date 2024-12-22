#ifndef BIOWEAPON_H
#define BIOWEAPON_H

#include "../master_header_command.h"
typedef struct {
    Word name;
    Word dna;
    Word protein;
} BioWeapon;

void DNAtoRNA(Word dna, Word *rna);

void RNAtoProtein(Word rna, Word *protein);

boolean checkSecretCode(Word protein, Word secretCode);

void processBioWeapon();

#endif