#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "LOGIN.h"

List L;
User user;

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

    for(int i = 0; i < L.Neff; i++){
        if(isEqual(nama, L.A[i].name)){
            if(isEqual(pass, L.A[i].password)){
                printf("Login Berhasil!");
                login = true;
                int j = 0;
                while(L.A[i].name[j] != '\0'){
                    user.name[j] = L.A[i].name[j];
                    j++;
                }
                user.name[j] = '\0';

                int k = 0;
                while(L.A[i].password[k] != '\0'){
                    user.password[k] = L.A[i].password[k];
                    k++;
                }
                user.name[k] = '\0';
            } else {
            printf("Username/Password salah!");
            }
        } else {
            printf("Username/Password salah!");
        }
    }
    
}