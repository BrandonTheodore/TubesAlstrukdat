#include <stdio.h>
#include "bioweapon.h"

void DNAtoRNA(Word dna, Word *rna) {
    int i;
    rna->Length = dna.Length;
    
    for(i = 0; i < dna.Length; i++) {
        if(dna.TabWord[i] == 'A') rna->TabWord[i] = 'U';
        else if(dna.TabWord[i] == 'T') rna->TabWord[i] = 'A';
        else if(dna.TabWord[i] == 'G') rna->TabWord[i] = 'C';
        else if(dna.TabWord[i] == 'C') rna->TabWord[i] = 'G';
    }
}

void RNAtoProtein(Word rna, Word *protein) {
    int i, j = 0;
    protein->Length = 0;
    
    for(i = 0; i < rna.Length - 2; i += 3) {
        char c1 = rna.TabWord[i];
        char c2 = rna.TabWord[i+1];
        char c3 = rna.TabWord[i+2];


        if (c1 == 'U') {
            if (c2 == 'U') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'F'; 
                else if (c3 == 'A' || c3 == 'G') protein->TabWord[j] = 'L';
            }
            else if (c2 == 'C') {
                protein->TabWord[j] = 'S'; 
            }
            else if (c2 == 'A') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'Y'; 
                else if (c3 == 'A' || c3 == 'G') break; 
            }
            else if (c2 == 'G') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'C'; 
                else if (c3 == 'G') protein->TabWord[j] = 'W';
                else if (c3 == 'A') break; 
            }
        }
        else if (c1 == 'C') {
            if (c2 == 'U') {
                protein->TabWord[j] = 'L'; 
            }
            else if (c2 == 'C') {
                protein->TabWord[j] = 'P';
            }
            else if (c2 == 'A') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'H'; 
                else if (c3 == 'A' || c3 == 'G') protein->TabWord[j] = 'Q'; 
            }
            else if (c2 == 'G') {
                protein->TabWord[j] = 'R'; 
            }
        }

        else if (c1 == 'A') {
            if (c2 == 'U') {
                if (c3 == 'G') protein->TabWord[j] = 'M'; 
                else protein->TabWord[j] = 'I';
            }
            else if (c2 == 'C') {
                protein->TabWord[j] = 'T'; 
            }
            else if (c2 == 'A') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'N'; 
                else if (c3 == 'A' || c3 == 'G') protein->TabWord[j] = 'K'; 
            }
            else if (c2 == 'G') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'S'; 
                else if (c3 == 'A' || c3 == 'G') protein->TabWord[j] = 'R'; 
            }
        }

        else if (c1 == 'G') {
            if (c2 == 'U') {
                protein->TabWord[j] = 'V'; 
            }
            else if (c2 == 'C') {
                protein->TabWord[j] = 'A'; 
            }
            else if (c2 == 'A') {
                if (c3 == 'U' || c3 == 'C') protein->TabWord[j] = 'D'; 
                else if (c3 == 'A' || c3 == 'G') protein->TabWord[j] = 'E'; 
            }
            else if (c2 == 'G') {
                protein->TabWord[j] = 'G'; 
            }
        }

        if (!(c1 == 'U' && c2 == 'A' && (c3 == 'A' || c3 == 'G')) && 
            !(c1 == 'U' && c2 == 'G' && c3 == 'A')) {
            j++;
            protein->Length++;
        }
    }
}

boolean checkSecretCode(Word protein, Word secretCode) {
    int i, j;
    
    if(secretCode.Length > protein.Length) return false;
    
    for(i = 0; i <= protein.Length - secretCode.Length; i++) {
        boolean match = true;
        for(j = 0; j < secretCode.Length; j++) {
            if(protein.TabWord[i+j] != secretCode.TabWord[j]) {
                match = false;
                break;
            }
        }
        if(match) return true;
    }
    return false;
}

void processBioWeapon() {
    BioWeapon weapon;
    Word rna, secretCode;
    
    printf("Masukkan nama senjata biologis: ");
    RESETWORD();
    STARTWORD2();
    weapon.name = currentWord;
    
    printf("Masukkan sekuens DNA: ");
    RESETWORD();
    STARTWORD2();
    weapon.dna = currentWord;
    
    printf("Masukkan kode rahasia: ");
    RESETWORD();
    STARTWORD2();
    secretCode = currentWord;
    
    DNAtoRNA(weapon.dna, &rna);
    RNAtoProtein(rna, &weapon.protein);
    
    if(checkSecretCode(weapon.protein, secretCode)) {
        printf("Senjata biologis mengandung kode, barang akan ditambahkan ke dalam queue!\n");
        Barang bio;
        
        int i;
        for(i = 0; i < weapon.name.Length; i++) {
            bio.name[i] = weapon.name.TabWord[i];
        }
        bio.name[i] = '\0';
        enqueue(&queue, bio);
    }
    else {
        printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
    }
}
