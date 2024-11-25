#include <stdio.h>
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkarakter.c"
#include "REGISTER.h"

List L;
User user;

void REGISTER(){
    int idx;
    char nama[50];
    printf("Username: ");
    STARTWORD2();
    int i = 0;
    while(currentWord.TabWord[i] != '\0'){
        nama[i] = currentWord.TabWord[i];
        (&currentWord)->TabWord[i] = '\0';
        i++;
    }
    nama[i] = '\0';
    if(!Search(L, nama, &idx)){
        printf("Password: ");
        STARTWORD2();
        char pass[50];
        int j = 0;
        while(currentWord.TabWord[j] != '\0'){
            pass[j] = currentWord.TabWord[j];
            (&currentWord)->TabWord[j] = '\0';
            j++;
        }
        pass[j] = '\0';
        int money = 0;
        InsertLast(&L, nama, pass, money);
    } else {
        printf("Username sudah ada!\n");
    }
}