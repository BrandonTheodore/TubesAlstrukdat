#include "LOGIN.h"
void LOGOUT(){
    UPass upass;
    if(login){
        int i = 0;
        while(upass.user[i] != '\0'){
            (&upass)->user[i] = '\0';
            i++;
        }
    } else {
        printf("Kamu belum melakukan login, silakan login terlebih dahulu!");
        MULAI();
    }
}