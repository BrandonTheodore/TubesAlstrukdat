#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "START.h"

boolean start;
boolean login;
boolean load;
User user;

void MULAI(){
    if(!start && !login){
        printf("\n");
        printf(" []=] __        _____ _     ____ ___  __  __ _____   _____ ___  \n");
        printf("      \\ \\      / /___| |   / ___/ _ \\|  \\/  | ____|  |_   _/ _ \\ \n");
        printf("       \\ \\ /\\ / /    | |  | |  | | | | |\\/| |  _|      | || | | |\n");
        printf("        \\ V  V /     | |__| |__| |_| | |  | | |___     | || |_| |\n");
        printf("         \\_/\\_/      |_____\\____\\___/|_|  |_|_____|    |_| \\___/ \n");
        printf("\n");
        printf("                    ____  _   _ ____  ____  __  __    _    ____ _____ \n");
        printf("                   |  _ \\| | | |  _ \\|  _ \\|  \\/  |  / \\  |  _ \\_   _|\n");
        printf("                   | |_) | | | | |_) | |_) | |\\/  | / _ \\ | |_) || |  \n");
        printf("                   |  __/| |_| |  _ <|  _ <| |  | |/ ___ \\|  _ < | |  \n");
        printf("                   |_|    \\___/|_| \\_\\_| \\_\\_|  |_/_/   \\_\\_| \\_\\|_|  \n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("\n");
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
        printf("10. HELP\n");
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

        if (isEqual(command, "WORK")) {
            main_work();
            user.money = user.money + global_Saldo_work;
        } 
        else if(isEqual(command, "WORK CHALLENGE")){
            selectChallenge();
            user.money = user.money + global_Saldo;
        } 
        else if(isEqual(command, "STORE LIST")){
            STORE_LIST();
        } 
        else if(isEqual(command, "STORE REQUEST")){
            STORE_REQUEST();
        } 
        else if(isEqual(command, "STORE SUPPLY")){
            STORE_SUPPLY();
        } 
        else if(isEqual(command, "STORE REMOVE")){
            STORE_REMOVE();
        } 
        else if(isEqual(command, "LOGOUT")){
            start = false;
            login = false;
            MULAI();
        } 
        else if(isEqual(command, "HELP")){
            HELP(start, login);
        }
        else if(isEqual(command, "SAVE")){
            i++;
            int j = i;
            while(currentWord.TabWord[i] != '\0'){
                txt[i - j] = currentWord.TabWord[i];
                (&currentWord)->TabWord[i] = '\0';
                i++;
            }
            txt[i-j] = '\0';
            SAVE(txt);
        } 
        else if(isEqual(command, "QUIT")){
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);
        }
    }

    MULAI();
}