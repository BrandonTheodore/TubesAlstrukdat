#include <stdio.h>
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkarakter.c"
#include "REGISTER.h"

/*Nunggu fungsi FindUser*/

void REGISTER(){
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
}