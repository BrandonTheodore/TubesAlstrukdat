#include <stdio.h>
#include "REGISTER.h"

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
    if(!Search(userList, nama, &idx)){
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
        int umur = 0;
        char nickname[50] = {'\0'};
        User newUser;
        strcopy(nama, newUser.name);
        strcopy(pass, newUser.password);
        newUser.money = money;
        newUser.umur = umur;
        strcopy(nickname, newUser.nickname);
        CreateEmptyLinier(&newUser.wishlist);
        CreateEmptyMap(&newUser.keranjang);
        CreateEmptyStack(&newUser.riwayat_pembelian);
        InsertLast(&userList, newUser);
    } else {
        printf("Username sudah ada!\n");
    }
}