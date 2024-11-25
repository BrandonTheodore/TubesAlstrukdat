#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "LOGIN.h"

List L;
User user;
Queue queue;
int IDX;

void LOGIN(){
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

    boolean cek = Search(L, nama, &IDX);
    if(cek){
        if(isEqual(L.A[IDX].password, pass)){
            printf("LOGIN BERHASIL!\n");
            login = true;
            int j = 0;
            while(L.A[IDX].name[j] != '\0'){
                user.name[j] = L.A[IDX].name[j];
                j++;
            }
            user.name[j] = '\0';

            int k = 0;
            while(L.A[IDX].password[k] != '\0'){
                user.password[k] = L.A[IDX].password[k];
                k++;
            }
            user.name[k] = '\0';
            user.money = L.A[IDX].money;
            CreateQueue(&queue);
        } else {
            printf("Password Salah!\n");
        }
    } else {
        printf("Username tidak ditemukan!\n");
    }
}