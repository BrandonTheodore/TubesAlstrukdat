#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Command/LOAD.c"
#include "Command/START.c"

char input[5];

void start(){
    printf("Selamat datang PURRMART! Silakan masukan perintah anda.\n>>> ");
    scanf("%s", input);
    if(input == "EXIT"){
        printf("Sampai Jumpa!");
    }
}

int main(){
    STARTWORD2();
    char command[50];
    char txt[50];
    int i = 0;
    while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
        command[i] = currentWord.TabWord[i];
        i++;
    }
    command[i] = '\0';
    if(isEqual(command, "START")){
        MULAI();
    } else if (isEqual(command, "LOAD")) {
        i++;
        int j = i;
        while(currentWord.TabWord[i] != '\0'){
            txt[i - j] = currentWord.TabWord[i];
            i++;
        }
        txt[i-j] = '\0';
        LOAD(txt);
    }
}