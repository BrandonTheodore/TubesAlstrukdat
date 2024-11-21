#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkarakter.c"
#include "LOGIN.h"

boolean login;

void LOGIN(){
    UPass upass;
    printf("Username: ");
    STARTWORD2();
    int i = 0;
    boolean cek = true;
    while(currentWord.TabWord[i] != '\0'){
        (&upass)->user[i] = currentWord.TabWord[i];
        (&currentWord)->TabWord[i] = '\0';
        i++;
    }
    (&upass)->user[i] = '\0';
    printf("Password: ");
    STARTWORD2();
    char pass[50];
    int j = 0;
    while(currentWord.TabWord[j] != '\0'){
        (&upass)->pass[j] = currentWord.TabWord[j];
        (&currentWord)->TabWord[j] = '\0';
        j++;
    }
    (&upass)->pass[j] = '\0'; 

    login = true;
    
}

int main(){
    LOGIN();
}