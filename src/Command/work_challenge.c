#include "work_challenge.h"

User user;

void displayWorkChallenge() {
    printf(">>> WORK CHALLENGE\n");
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
            if(user.money >= TA_COST){
                user.money -=TA_COST;
                playGuessingGame();
                break;
            } else {
                printf("Saldo tidak cukup!");
            }
        case 2:
            if(user.money >= W_COST){
                user.money -=W_COST;
                playWordle();
                break;
            } else {
                printf("Saldo tidak cukup!");
            }
        case 3:
            if(user.money >= QUANTUM_COST){
                user.money -=QUANTUM_COST;
                playQuantumWordle();
                break;
            } else {
                printf("Saldo tidak cukup!");
            }
        default:
            printf("Pilihan tidak valid.\n");
    }
}