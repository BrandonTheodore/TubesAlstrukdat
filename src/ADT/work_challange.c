#include "work_challange.h"

void displayWorkChallenge() {
    printf(">> WORK CHALLENGE\n");
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=%d)\n", TA_COST);
    printf("2. WORDL399 (biaya main=%d)\n",W_COST);
}

void selectChallenge() {
    int choice;
    displayWorkChallenge();
    printf("Masukan challenge yang hendak dimainkan: ");
    
    // Baca input menggunakan mesin kata
    STARTWORD2();
    choice = wordToInt(currentWord);
    
    switch(choice) {
        case 1:
            playGuessingGame();
            break;
        case 2:
            playWordle();
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }
}