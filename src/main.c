#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"

boolean start;
boolean login;
boolean load;
int user_id;
User user;

int main(){
    printf("\n");
    printf("                                                                                                                             \n");
    printf("                                                                                                                             \n");
    printf("                                                     .:.......                                                               \n");
    printf("                                                    - .:.      ......                         .:-=-.                         \n");
    printf("                                                   : -%%-*--#+*.++=   .                    .-+*******=                        \n");
    printf("                                                   : #--+=#*+*=*:%%-   .          :===:  -+***********+                       \n");
    printf("                                                  :  -#+#+@-#+*#@=   ..        -*****##***************+                      \n");
    printf("                                                  ..    :..  -=. +-:  :      -*************************:                     \n");
    printf("                                                   :==--:-:::::.::.... :   .+**********##########*****#=                     \n");
    printf("                                                 -=----------=---=     .  :############################*                     \n");
    printf("                                               :+=---------------=       -##############################*+=-:.               \n");
    printf("                                               +=---=-----------=:   .-=+##############*****###########*******+.             \n");
    printf("                                              :+==------------=-= :+###**+++===++******************************.             \n");
    printf("                                               ++=-----------=-=--=---------------=+*************************+.              \n");
    printf("                                               :+==--==--===---------------------::--=+*##*****************+-                \n");
    printf("                                                =========-------------------:..-==-    :-++**###********++-                  \n");
    printf("                                                 ++=+===-------------------..++*%%*  ::   .=-====++::::-#%%.:.                \n");
    printf("                                                 :+====------------------=  =%%%%%%**##    .=----=.    +*%%%%#-                \n");
    printf("                                                  =====------------------=  :%%%%%%%%+    .=------    .=+*=.:                \n");
    printf("                                                   +===--------------------  :+#%%#*-    .---==----:.    .:.                 \n");
    printf("                                                   -====--------------------:.         .----====----=+:..                    \n");
    printf("                                                   .+===-------------------------:::-------==============:                   \n");
    printf("                                                    +===---------------------------------==+:..-=========+                   \n");
    printf("                                                    =====-------------------------------===+-====---=-::.                    \n");
    printf("                                                    -======-----------------------------------------=.                       \n");
    printf("                                                    .==========------------------------------------=+                        \n");
    printf("                                                    :+====================----===----------------===+                        \n");
    printf("                                                     ======.  ..::=+++++=======--------===========+=-                        \n");
    printf("                                                     :+==+:       .++++--=-.:==-------+==----====-:                          \n");
    printf("                                                      -+===-:.     .:--::.    =-------       +====                           \n");
    printf("                                                       .====-                  =----=        =====.                          \n");
    printf("                                                         .                     ------        :===++:                         \n");
    printf("                                                                                =---=.          ..                           \n");
    printf("                                                                                .-=+=*                                        \n");
    printf("                           ( ___ )                                                                                 ( ___ ) \n");
    printf("                            |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |  \n");
    printf("                            |   |       __          ________ _      _____ ____  __  __ ______   _______ ____        |   |  \n");
    printf("                            |   |       \\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____| |__   __/ __ \\       |   |  \n");
    printf("                            |   |        \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__       | | | |  | |      |   |  \n");
    printf("                            |   |         \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|      | | | |  | |      |   |  \n");
    printf("                            |   |          \\  /\\  /  | |____| |___| |___| |__| | |  | | |____     | | | |__| |      |   |  \n") ;
    printf("                            |   |           \\/  \\/   |______|______\\_____\\____/|_|  |_|______|    |_|  \\____/       |   |  \n");
    printf("                            |   |              _____  _    _ _____  _____  __  __          _____ _______            |   |  \n")   ;
    printf("                            |   |             |  __ \\| |  | |  __ \\|  __ \\|  \\/  |   /\\   |  __ \\__   __|           |   |  \n");
    printf("                            |   |             | |__) | |  | | |__) | |__) | \\  / |  /  \\  | |__) | | |              |   |  \n") ;
    printf("                            |   |             |  ___/| |  | |  _  /|  _  /| |\\/| | / /\\ \\ |  _  /  | |              |   |  \n");
    printf("                            |   |             | |    | |__| | | \\ \\| | \\ \\| |  | |/ ____ \\| | \\ \\  | |              |   |  \n");
    printf("                            |   |             |_|     \\____/|_|  \\_\\_|  \\_\\_|  |_/_/    \\_\\_|  \\_\\ |_|              |   |  \n");
    printf("                            |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|  \n");
    printf("                           (_____)                                                                                 (_____) \n");
    printf("\n");
    printf("\n");
    
    while(true){
    if(!start && !login){
        printf("\n");
        printf("===================================\n");
        printf("|           MENU OPTIONS          |\n");
        printf("===================================\n");
        printf("|  1. START                       |\n");
        printf("|  2. LOAD                        |\n");
        printf("|  3. QUIT                        |\n");
        printf("|  4. HELP                        |\n");
        printf("===================================\n");
        printf(">>> ");
        STARTWORD2();
        printf("\n");

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
        if(isEqual(command, "START") || isEqual(command, "1")){
            MULAI();
           
        } else if (isEqual(command, "LOAD") || isEqual(command, "2")) {
            i++;
            int j = i;
            while(currentWord.TabWord[i] != '\0'){
                txt[i - j] = currentWord.TabWord[i];
                (&currentWord)->TabWord[i] = '\0';
                i++;
            }
            txt[i-j] = '\0';
            LOAD(txt);
            
        } else if(isEqual(command, "QUIT") || isEqual(command, "3")){
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);
        } else if(isEqual(command, "HELP") || isEqual(command, "4")){
            printf("\n");
            HELP(start, login);
            printf("Ketik apapun untuk kembali ke menu utama\n");
            printf(">>> ");
            STARTWORD2();
        }
    } else if (!login && start){
        printf("\n");
        printf("===================================\n");
        printf("|           MENU OPTIONS          |\n");
        printf("===================================\n");
        printf("|  1. REGISTER                    |\n");
        printf("|  2. LOGIN                       |\n");
        printf("|  3. QUI                         |\n");
        printf("|  4. HELP                        |\n");
        printf("===================================\n");
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
        if(isEqual(command, "REGISTER") || isEqual(command, "1")){
            REGISTER();
        } else if (isEqual(command, "LOGIN") || isEqual(command, "2")) {
            LOGIN();
        } 
        else if(isEqual(command, "QUIT") || isEqual(command, "3")){
            printf("Apakah kamu ingin menyimpan file? (Y/N)\n");
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

            if(isEqual(command, "Y") || isEqual(command, "y")){
                do {
                    printf("Masukkan Nama File Yang Ingin Anda Save: ");
                    STARTWORD2();
                    char txt[50];
                    int i = 0;
                    while(currentWord.TabWord[i] != '\0' && currentWord.TabWord[i] != ' '){
                        txt[i] = currentWord.TabWord[i];
                        (&currentWord)->TabWord[i] = '\0';
                        i++;
                    }
                    txt[i] = '\0';
                    
                    int valid = 0;
                    if (i >= 4) { 
                        if (txt[i-4] == '.' && 
                            txt[i-3] == 't' && 
                            txt[i-2] == 'x' && 
                            txt[i-1] == 't') {
                            valid = 1;
                        }
                    }
                    
                    if (valid) {
                        SAVE(txt);
                        break;
                    } else {
                        printf("File tidak terbaca! Nama file harus berakhiran .txt\n");
                    }
                } while (1);
            }
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);

        } else if(isEqual(command, "HELP") || isEqual(command, "4")){
            HELP(start, login);
            printf("Ketik apapun untuk kembali ke menu utama\n");
            printf(">>> ");
            STARTWORD2();

        } else {
            printf("Command tidak valid, silakan ulangi kembali!\n");
            MULAI();
        }
    } else {
        printf("\n");
        printf("=========================================================\n");
        printf("|                       MENU OPTIONS                   |\n");
        printf("=========================================================\n");
        printf("|  1. WORK                                             |\n");
        printf("|  2. WORK CHALLENGE                                   |\n");
        printf("|  3. STORE LIST                                       |\n");
        printf("|  4. STORE REQUEST                                    |\n");
        printf("|  5. STORE SUPPLY                                     |\n");
        printf("|  6. STORE REMOVE                                     |\n");
        printf("|  7. LOGOUT                                           |\n");
        printf("|  8. SAVE                                             |\n");
        printf("|  9. QUIT                                             |\n");
        printf("| 10. HELP                                             |\n");
        printf("=========================================================\n");
        printf(">>> ");
        STARTWORD2();

        char command[50];
        char command2[50];
        char txt[50];
        int i = 0, j = 0;
        boolean cek = false;

        while(currentWord.TabWord[i] != '\0'){
            if (currentWord.TabWord[i] != ' ' && !cek){
                command2[i] = currentWord.TabWord[i];
            }
            else if (currentWord.TabWord[i] == ' ' && !cek){
                command2[i] = '\0';
                cek = true;
            }
            else if (cek){
                txt[j] = currentWord.TabWord[i];
                j++;
            }
            command[i] = currentWord.TabWord[i];
            (&currentWord)->TabWord[i] = '\0';
            txt[j] = '\0';
            i++;
        }
        command[i] = '\0';
        (&currentWord)->TabWord[i] = '\0';


       if (isEqual(command, "WORK") || isEqual(command, "1")) {
            printf("\n");
            main_work();
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
       }
       
        else if(isEqual(command, "WORK CHALLENGE") || isEqual(command, "2")){
            printf("\n");
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            selectChallenge(); 
            printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
        }
        else if(isEqual(command, "STORE LIST") || isEqual(command, "3")){
            printf("\n");
            STORE_LIST();
        }
        else if(isEqual(command, "STORE REQUEST") || isEqual(command, "4")){
            printf("\n");
            STORE_REQUEST();
        }
        else if(isEqual(command, "STORE SUPPLY") || isEqual(command, "5")){
            printf("\n");
            STORE_SUPPLY();
        }
        else if(isEqual(command, "STORE REMOVE") || isEqual(command, "6")){
            printf("\n");
            STORE_REMOVE();
        } 

        else if(isEqual(command, "LOGOUT") || isEqual(command, "7")){
            LOGOUT();
        } else if(isEqual(command, "HELP") || isEqual(command, "10")){
            HELP(start, login);
            printf("Ketik apapun untuk kembali ke menu utama\n");
            printf(">>> ");
            STARTWORD2();
        }
        else if(isEqual(command2, "SAVE")){
            // Check if filename ends with .txt
            int i = 0;
            while(txt[i] != '\0' && i < 50) {
                i++;
            }
            
            int valid = 0;
            if (i >= 4) { 
                if (txt[i-4] == '.' && 
                    txt[i-3] == 't' && 
                    txt[i-2] == 'x' && 
                    txt[i-1] == 't') {
                    valid = 1;
                }
            }
            
            if (valid) {
                printf("%s\n", txt);
                SAVE(txt);
            } else {
                printf("File tidak terbaca! Nama file harus berakhiran .txt\n");
            }
        } 
        else if(isEqual(command, "QUIT") || isEqual(command, "9")){
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
                do {
                    printf("Masukkan nama file: ");
                    STARTWORD2();
                    char txt[50];
                    int i = 0;
                    while(currentWord.TabWord[i] != '\0' && currentWord.TabWord[i] != ' '){
                        txt[i] = currentWord.TabWord[i];
                        (&currentWord)->TabWord[i] = '\0';
                        i++;
                    }
                    txt[i] = '\0';
                    
                    int valid = 0;
                    if (i >= 4) {
                        if (txt[i-4] == '.' && 
                            txt[i-3] == 't' && 
                            txt[i-2] == 'x' && 
                            txt[i-1] == 't') {
                            valid = 1;
                        }
                    }
                    
                    if (valid) {
                        SAVE(txt);
                        break;
                    } else {
                        printf("File tidak terbaca! Nama file harus berakhiran .txt\n");
                    }
                } while (1);
            }
            printf("Aplikasi akan ditutup");
            exit(EXIT_SUCCESS);
        } else {
            printf("Command tidak valid, silakan ulangi kembali!\n");
        }
    }
    }
}