#include "LOGOUT.h"
char name[50];
char password[50];
int money;
boolean login;

void LOGOUT(){
    if(login){
        for(int i = 0; name[i] != '\0'; i++){
            name[i] = '\0';
        }
        for(int i = 0; password[i] != '\0'; i++){
            password[i] = '\0';
        }
        money = NIL;
        login = false;
    } else {
        printf("Kamu belum melakukan login, silakan login terlebih dahulu!");
        MULAI();
    }
}