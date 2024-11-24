#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "LOGIN.h"

List L;
User user;

void LOGIN(){
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

    for(int i = 0; i < L.Neff; i++){
        if(isEqual(user, L.A[i].name)){
            if(isEqual(pass, L.A[i].password)){
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
            }
        } else {
            printf("Username/Password salah!");
        }
    }
    
}