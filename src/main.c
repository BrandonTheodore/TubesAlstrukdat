#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"

boolean start;
boolean login;
boolean load;
User user;

int main(){
    while(true){
    if(!start && !login){
        printf("\n");
        printf(" __        _______ _     ____ ___  __  __ _____   _____ ___  \n");
        printf(" \\ \\      / / ____| |   / ___/ _ \\|  \\/  | ____|  |_   _/ _ \\ \n");
        printf("  \\ \\ /\\ / /|  _| | |  | |  | | | | |\\/| |  _|      | || | | |\n");
        printf("   \\ V  V / | |___| |__| |__| |_| | |  | | |___     | || |_| |\n");
        printf("    \\_/\\_/  |_____|_____\\____\\___/|_|  |_|_____|    |_| \\___/ \n");
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
            MULAI();
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
        int i = 0;
        while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
            command[i] = currentWord.TabWord[i];
            (&currentWord)->TabWord[i] = '\0';
            i++;
        }
        command[i] = '\0';
        (&currentWord)->TabWord[i] = '\0';
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

        while(currentWord.TabWord[i] != '\0'){
            command[i] = currentWord.TabWord[i];
            (&currentWord)->TabWord[i] = '\0';
            i++;
        }
        command[i] = '\0';
        (&currentWord)->TabWord[i] = '\0';

        printf("%stes",command);

       if (isEqual(command, "WORK")) {
            printf("\n");
            main_work();
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
       }
       
        else if(isEqual(command, "WORK CHALLENGE")){
            printf("\n");
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            selectChallenge(); 
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
        }
        else if(isEqual(command, "STORE LIST")){
            printf("\n");
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            STORE_LIST();
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
        }
        else if(isEqual(command, "STORE REQUEST")){
            printf("\n");
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            STORE_REQUEST();
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
        }
        else if(isEqual(command, "STORE SUPPLY")){
            printf("\n");
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            STORE_SUPPLY();
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
        }
        else if(isEqual(command, "STORE REMOVE")){
            printf("\n");
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            STORE_REMOVE();
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
        } 

        else if(isEqual(command, "LOGOUT")){
            LOGOUT();
        } else if(isEqual(command, "HELP")){
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
            printf("Apakah kamu ingin menyimpan file?(Y/N)\n");
            printf(">>> ");
            STARTWORD2();

            char command[50];
            int i = 0;

            while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
                command[i] = currentWord.TabWord[i];
                (&currentWord)->TabWord[i] = '\0';
                i++;
            }
            command[i] = '\0';
            (&currentWord)->TabWord[i] = '\0';
            
            if(isEqual(command, "Y")){
                SAVE("default.txt");
            }
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);
        } else {
            printf("Command tidak valid, silakan ulangi kembali!\n");
        }
    }

    }
}