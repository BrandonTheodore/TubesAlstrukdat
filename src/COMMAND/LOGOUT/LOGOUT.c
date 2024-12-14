#include "LOGOUT.h"
#include <stdio.h>

User user;

void LOGOUT(){
    if(login){
        for(int i = 0; user.name[i] != '\0'; i++){
            (&user)->name[i] = '\0';
        }
        for(int i = 0; user.password[i] != '\0'; i++){
            (&user)->password[i] = '\0';
        }
        user.money = NIL;
        login = false;
    } else {
        printf("Kamu belum melakukan login, silakan login terlebih dahulu!");
    }
}