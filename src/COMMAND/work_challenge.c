#include "work_challenge.h"

int global_Saldo =0;

void displayWorkChallenge() {
    printf(">> WORK CHALLENGE\n");
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=%d)\n", TA_COST);
    printf("2. WORDL3 (biaya main=%d)\n",W_COST);
    printf("3. Quantum WORDL3 (biaya main =%d)\n", QUANTUM_COST);
}

void selectChallenge() {
    int choice;
    displayWorkChallenge();
    printf("Masukan challenge yang hendak dimainkan: ");
    
    // Baca input menggunakan mesin kata
    STARTWORD2();
    choice = wordToInt(currentWord);

    for (int i = 0; i < currentWord.Length; i++) {
        currentWord.TabWord[i] = '\0';
    }
    currentWord.Length = 0;
    
    switch(choice) {
        case 1:
            global_Saldo -=TA_COST;
            playGuessingGame();
            break;
        case 2:
            global_Saldo -=W_COST;
            playWordle();
            break;
        case 3:
            global_Saldo -=QUANTUM_COST;
            playQuantumWordle();
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }
}