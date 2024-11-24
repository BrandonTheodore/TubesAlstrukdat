#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "START.h"

boolean start;
boolean login;
boolean load;

void MULAI(){
    if(!start && !login){
        printf("1. START\n");
        printf("2. LOAD\n");
        printf("3. QUIT\n");
        printf("4. HELP\n");
        printf(">>> ");
        STARTWORD2();
        char command[50];
        char txt[50];
        int i = 0;
        while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
            command[i] = currentWord.TabWord[i];
            (&currentWord)->TabWord[i] = '\0';
            i++;
        }
        command[i] = '\0';
        (&currentWord)->TabWord[i] = '\0';
        if(isEqual(command, "START")){
            start = true;
            if(load){
                MULAI();
            } else {
                LOAD("default.txt");
                MULAI();
            }
        } else if (isEqual(command, "LOAD")) {
            i++;
            int j = i;
            while(currentWord.TabWord[i] != '\0'){
                txt[i - j] = currentWord.TabWord[i];
                (&currentWord)->TabWord[i] = '\0';
                i++;
            }
            txt[i-j] = '\0';
            LOAD(txt);
        } else if(isEqual(command, "QUIT")){
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);
        } else if(isEqual(command, "HELP")){
            HELP(start, login);
        } else {
            printf("Command tidak valid, silakan ulangi kembali!\n");
        }
    } else if (!login && start){
        printf("1. REGISTER\n");
        printf("2. LOGIN\n");
        printf("3. QUIT\n");
        printf("4. HELP\n");
        printf(">>> ");
        STARTWORD2();
        char command[50];
        char txt[50];
        int i = 0;
        while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
            command[i] = currentWord.TabWord[i];
            (&currentWord)->TabWord[i] = '\0';
            i++;
        }
        command[i] = '\0';
        if(isEqual(command, "REGISTER")){
            REGISTER();
        } else if (isEqual(command, "LOGIN")) {
            LOGIN();
        } else if(isEqual(command, "QUIT")){
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);
        } else if(isEqual(command, "HELP")){
            HELP(start, login);
        } else {
            printf("Command tidak valid, silakan ulangi kembali!\n");
            MULAI();
        }
    } else {
        printf("1. WORK\n");
        printf("2. WORK CHALLENGE\n");
        printf("3. STORE LIST\n");
        printf("4. STORE REQUEST\n");
        printf("5. STORE SUPPLY\n");
        printf("6. STORE REMOVE\n");
        printf("7. LOGOUT\n");
        printf("8. SAVE\n");
        printf("9. QUIT\n");
        printf("10. HELP");
        printf(">>> ");
        // STARTWORD2();
        // char command[50];
        // int i = 0;
        // while(currentWord.TabWord[i] != '\0'){
        //     command[i] = currentWord.TabWord[i];
        //     (&currentWord)->TabWord[i] = '\0';
        //     i++;
        // }
        // command[i] = '\0';
        // if(isEqual(command, "WORK")){
        //     REGISTER();
        // } else if (isEqual(command, "WORK CHALLENGE")) {
        //     selectChallenge();
        // } else if(isEqual(command, "QUIT")){
        //     printf("Aplikasi akan ditutup");
        //     exit(EXIT_SUCCESS);
        // } else if(isEqual(command, "HELP")){
        //     HELP(start, login);
        // }
    }

    MULAI();
}