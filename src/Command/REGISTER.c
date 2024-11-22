#include <stdio.h>
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkarakter.c"
#include "REGISTER.h"

void REGISTER(){
    Total total;
    char user[50];
    printf("Username: ");
    STARTWORD2();
    int i = 0;
    while(currentWord.TabWord[i] != '\0'){
        user[i] = currentWord.TabWord[i];
        (&currentWord)->TabWord[i] = '\0';
        i++;
    }
    user[i] = '\0';
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

    for(int i = 0; i < 50; i++){
        if(isEqual(user, total.TotUs[i].name)){
            if(isEqual(pass, total.TotUs[i].password)){
                printf("Login Berhasil!");
                login = true;
                int j = 0;
                while(user[j] != ' ' && user[i] != '\0'){
                    name[j] = user[j];
                    j++;
                }
                name[j] = '\0';
            } else {
                printf("Username/Password salah!");
                MULAI();
            }
        } else {
            printf("Username/Password salah!");
            MULAI();
        }
    }
}