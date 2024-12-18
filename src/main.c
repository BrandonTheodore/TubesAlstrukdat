#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/master_header_adt.h"
#include "COMMAND/master_header_command.h"

boolean start;
boolean login;
boolean load;
int user_id;
User user;

int main()

{
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
    
    while(true)
    {    
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
        } 
        else if (!login && start)
        {
            printf("\n");
            printf("===================================\n");
            printf("|           MENU OPTIONS          |\n");
            printf("===================================\n");
            printf("|  1. REGISTER                    |\n");
            printf("|  2. LOGIN                       |\n");
            printf("|  3. PROFILE                     |\n");
            printf("|  4. QUIT                        |\n");
            printf("|  5. HELP                        |\n");
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
            else if (isEqual(command, "PROFILE") || isEqual(command, "3")) {
                PROFILE();
            }
            else if(isEqual(command, "QUIT") || isEqual(command, "4")){
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

            } else if(isEqual(command, "HELP") || isEqual(command, "5")){
                HELP(start, login);
                printf("Ketik apapun untuk kembali ke menu utama\n");
                printf(">>> ");
                STARTWORD2();

            } else {
                printf("Command tidak valid, silakan ulangi kembali!\n");
                MULAI();
            }
        } 

        else 
        {
            printf("\n");
            printf("=========================================================\n");
            printf("|                       MENU OPTIONS                      |\n");
            printf("=========================================================\n");
            printf("|  1. WORK                                               |\n");
            printf("|  2. WORK CHALLENGE                                     |\n");
            printf("|  3. STORE LIST                                         |\n");
            printf("|  4. STORE REQUEST                                      |\n");
            printf("|  5. STORE SUPPLY                                       |\n");
            printf("|  6. STORE REMOVE                                       |\n");
            printf("|  7. CART ADD                                           |\n");
            printf("|  8. CART REMOVE                                        |\n");
            printf("|  9. CART SHOW                                          |\n");
            printf("| 10. CART PAY                                           |\n");
            printf("| 11. PROFILE                                            |\n");
            printf("| 12. WISHLIST ADD                                       |\n");
            printf("| 13. WISHLIST REMOVE 1                                  |\n");
            printf("| 14. WISHLIST REMOVE 2                                  |\n");
            printf("| 15. WISHLIST CLEAR                                     |\n");
            printf("| 16. WISHLIST SHOW                                      |\n");
            printf("| 17. WISHLIST SWAP                                      |\n");
            printf("| 18. HISTORY                                            |\n");
            printf("| 19. LOGOUT                                             |\n");
            printf("| 20. SAVE                                               |\n");
            printf("| 21. QUIT                                               |\n");
            printf("| 22. HELP                                               |\n");
            printf("===========================================================\n");
            printf(">>> ");
            STARTWORD2();

            char command[100],command2[100], command3[100];
            int index=0;
            int index2=0;
            int index3=0;
            while (currentWord.TabWord[index3] != '\0') {
                command3[index3] = currentWord.TabWord[index3];
                index3++;
            }
            command3[index3] = '\0';

            while (1) {
                if (index==index2)
                {
                    command[index]=currentWord.TabWord[index];
                    command2[index2]=currentWord.TabWord[index];
                    index++; 
                    index2++;
                }
                if (currentWord.TabWord[index]=='\0') break;
                if (currentWord.TabWord[index]==' ') index--;
                else if (index2>index)
                {
                    command2[index2]=currentWord.TabWord[index2];
                    index2++;
                    if (currentWord.TabWord[index2]==' ') break;
                    if (currentWord.TabWord[index2]=='\0') break;
                }
            }

            if (index<index2) index++;
            command[index]='\0'; 
            command2[index2]='\0';
            index++; 
            index2++;

            if (isEqual(command, "WORK") || isEqual(command, "1")) {
                printf("\n");
                main_work();
                printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            }
        
            else if(isEqual(command2, "WORK CHALLENGE") || isEqual(command, "2")){
                printf("\n");
                printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
                selectChallenge(); 
                printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            }
            else if(isEqual(command2, "STORE LIST") || isEqual(command, "3")){
                printf("\n");
                STORE_LIST();
            }
            else if(isEqual(command2, "STORE REQUEST") || isEqual(command, "4")){
                printf("\n");
                STORE_REQUEST();
            }
            else if(isEqual(command2, "STORE SUPPLY") || isEqual(command, "5")){
                printf("\n");
                STORE_SUPPLY();
            }
            else if(isEqual(command2, "STORE REMOVE") || isEqual(command, "6")){
                printf("\n");
                STORE_REMOVE();
            }
            else if (isEqual(command2, "CART ADD")) 
            {
                printf("\n");
                char name[100],temp[100]; 
                int jumlah,index3=index2,space=0;

                while (currentWord.TabWord[index2]!= '\0')
                {
                    if (currentWord.TabWord[index2] ==' ') space++;
                    index2++;
                }
                index2=index3; 
                index3=0;

                while (space!=0)
                {
                    name[index3++] = currentWord.TabWord[index2++];
                    if (currentWord.TabWord[index2]==' ') space--;
                    if (currentWord.TabWord[index2]=='\0') break;
                }
                
                name[index3]='\0'; index2++; index3=0;
                while (currentWord.TabWord[index2]!= '\0')
                {
                    temp[index3++] = currentWord.TabWord[index2++];
                }
                temp[index3]='\0'; 
                stringtoint(temp,&jumlah);
                CART_ADD(name,jumlah);
            }

            else if (isEqual(command2, "CART REMOVE")) {
                printf("\n");
                char name[100],temp[100]; 
                int jumlah,index3=index2,space=0;
                printf("%s",command2);

                while (currentWord.TabWord[index2]!= '\0')
                {
                    if (currentWord.TabWord[index2] ==' ') space++;
                    index2++;
                }
                index2=index3; 
                index3=0;

                while (space!=0)
                {
                    name[index3++] = currentWord.TabWord[index2++];
                    if (currentWord.TabWord[index2]==' ') space--;
                    if (currentWord.TabWord[index2]=='\0') break;
                }
                
                name[index3]='\0'; index2++; index3=0;
                while (currentWord.TabWord[index2]!= '\0')
                {
                    temp[index3++] = currentWord.TabWord[index2++];
                }
                temp[index3]='\0'; 
                stringtoint(temp,&jumlah);
                CART_REMOVE(name, jumlah);
            }
            
            else if(isEqual(command2, "CART SHOW") || isEqual(command, "9")){
                printf("\n");
                CART_SHOW();
            }
            else if(isEqual(command2, "CART PAY") || isEqual(command, "10")){
                printf("\n");
                CART_PAY();
            }
            else if(isEqual(command2, "PROFILE") || isEqual(command, "11")){
                printf("\n");
                PROFILE();
            }
            else if(isEqual(command2, "WISHLIST ADD") || isEqual(command, "12")){
                printf("\n");
                WISHLIST_ADD();
            }
            else if(isEqual(command3, "WISHLIST REMOVE") || isEqual(command, "14")){
                printf("\n");
                WISHLIST_REMOVE_2();
            }
            else if(isEqual(command2, "WISHLIST REMOVE") || isEqual(command, "13")){
                printf("\n");
                int i,index3=0;char temp[100];
                while (currentWord.TabWord[index2]!='\0')
                {
                    temp[index3++]=currentWord.TabWord[index2++];
                }
                temp[index3]='\0';
                stringtoint(temp,&i);

                WISHLIST_REMOVE_1(i);
            }
            else if(isEqual(command2, "WISHLIST CLEAR") || isEqual(command, "15")){
                printf("\n");
                WISHLIST_CLEAR();
            }
            else if(isEqual(command2, "WISHLIST SHOW") || isEqual(command, "16")){
                printf("\n");
                WISHLIST_SHOW();
            }
            else if(isEqual(command2, "WISHLIST SWAP") || isEqual(command, "17")){
                printf("\n");
                int i,j;char temp[100]; int index3=0;
                while (currentWord.TabWord[index2]!=' ')
                {
                    temp[index3++]=currentWord.TabWord[index2++];
                }
                temp[index3]='\0'; stringtoint(temp,&i); index2++;
                index3=0;
                while (currentWord.TabWord[index2]!='\0')
                {
                    temp[index3++]=currentWord.TabWord[index2++];
                }
                temp[index3]='\0'; stringtoint(temp,&j);
                WISHLIST_SWAP(i,j);
            }
            else if(isEqual(command, "HISTORY")){
                printf("\n");
                int i,index3=0;char temp[100];
                while (currentWord.TabWord[index2]!='\0')
                {
                    temp[index3++]=currentWord.TabWord[index2++];
                }
                temp[index3]='\0';
                stringtoint(temp,&i);
                HISTORY(i);

            } 
            else if(isEqual(command, "LOGOUT") || isEqual(command, "19")){
                LOGOUT();
            } else if(isEqual(command, "HELP") || isEqual(command, "22")){
                HELP(start, login);
                printf("Ketik apapun untuk kembali ke menu utama\n");
                printf(">>> ");
                STARTWORD2();
            }
            else if(isEqual(command2, "SAVE")){
                char txt[50];
                int i = 0;
                while(currentWord.TabWord[index2] != '\0' && i < 50) {
                    txt[i] = currentWord.TabWord[index2];
                    i++;
                    index2++;
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
                    printf("%s\n", txt);
                    SAVE(txt);
                } else {
                    printf("File tidak terbaca! Nama file harus berakhiran .txt\n");
                }
            } 
            else if(isEqual(command, "QUIT") || isEqual(command, "21"))
            {
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
                
                if(isEqual(command, "Y") || isEqual(command, "y")){
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
            } 
            
            else
            {
                printf("Command tidak valid, silakan ulangi kembali!\n");
            }
            RESETWORD();
        }
    }
    return 0;
}



