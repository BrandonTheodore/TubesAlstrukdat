#include "work_challenge.h"

User user;
int user_id;
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

    STARTWORD2();
    choice = wordToInt(currentWord);

    for (int i = 0; i < currentWord.Length; i++) {
        currentWord.TabWord[i] = '\0';
    }
    currentWord.Length = 0;

    if (choice < 1 || choice > 3) {
        printf("Pilihan tidak valid.\n");
        return;
    }
    else if (choice == 1) {
        if (user.money >= TA_COST) {
            userList.A[user_id].money -= TA_COST;
            playGuessingGame();
        } 
        else {
            printf("Saldo tidak cukup!\n");
        }
    } 
    else if (choice == 2) {
        if (user.money >= W_COST) {
            userList.A[user_id].money -= W_COST;
            playWordle();
        } 
        else {
            printf("Saldo tidak cukup!\n");
        }
    } 
    else if (choice == 3) {
        if (user.money >= QUANTUM_COST) {
            userList.A[user_id].money -= QUANTUM_COST;
            playQuantumWordle();
        } 
        else {
            printf("Saldo tidak cukup!\n");
        }
    }
    
}