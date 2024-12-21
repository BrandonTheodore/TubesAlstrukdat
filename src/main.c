#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/master_header_adt.h"
#include "COMMAND/master_header_command.h"
#include "asciart/asciiart.h"

boolean start;
boolean login;
boolean load;
int user_id;
User user;

void clear_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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
                clear_terminal();
                MULAI();
            
            } else if (isEqual(command, "LOAD")) {
                clear_terminal();
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
                clear_terminal();
                ascii_quit();
                printf("Aplikasi akan ditutup");
                exit(EXIT_SUCCESS);
            } else if(isEqual(command, "HELP") || isEqual(command, "4")){
                clear_terminal();
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
            while(currentWord.TabWord[i] != '\0'){
                command[i] = currentWord.TabWord[i];
                i++;
            }
            command[i] = '\0';
            if(isEqual(command, "REGISTER") || isEqual(command, "1")){
                clear_terminal();
                asci_register();
                REGISTER();
            } else if (isEqual(command, "LOGIN") || isEqual(command, "2")) {
                clear_terminal();  
                asci_login();
                LOGIN();
            } 
            else if (isEqual(command, "PROFILE") || isEqual(command, "3")) {
                clear_terminal();
                PROFILE();
            }
            else if(isEqual(command, "QUIT") || isEqual(command, "4")){
                clear_terminal();
                ascii_quit();
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
                clear_terminal();   
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
            printf("|                       MENU OPTIONS                     |\n");
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
            printf("| 13. WISHLIST REMOVE                                    |\n");
            printf("| 14. WISHLIST CLEAR                                     |\n");
            printf("| 15. WISHLIST SHOW                                      |\n");
            printf("| 16. WISHLIST SWAP                                      |\n");
            printf("| 17. HISTORY                                            |\n");
            printf("| 18. LOGOUT                                             |\n");
            printf("| 19. SAVE                                               |\n");
            printf("| 20. QUIT                                               |\n");
            printf("| 21. HELP                                               |\n");
            printf("==========================================================\n");
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
                clear_terminal();
                printf("\n");
                ascii_work();
                main_work();
                printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            }
        
            else if(isEqual(command2, "WORK CHALLENGE") || isEqual(command, "2")){
                clear_terminal();
                printf("\n");
                ascii_workchallenge();
                printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
                selectChallenge(); 
                printf("saldo anda sekarang adalah: %d rupiah\n",user.money);
            }
            else if(isEqual(command2, "STORE LIST") || isEqual(command, "3")){
                clear_terminal();
                printf("\n");
                ascii_storelist();
                STORE_LIST();
            }
            else if(isEqual(command2, "STORE REQUEST") || isEqual(command, "4")){
                clear_terminal();
                printf("\n");
                ascii_storerequest();
                STORE_REQUEST();
            }
            else if(isEqual(command2, "STORE SUPPLY") || isEqual(command, "5")){
                clear_terminal();
                printf("\n");
                ascii_storesupply();
                STORE_SUPPLY();
            }
            else if(isEqual(command2, "STORE REMOVE") || isEqual(command, "6")){
                clear_terminal();
                printf("\n");
                ascii_storeremove();
                STORE_REMOVE();
            }
            else if (isEqual(command2, "CART ADD")) 
            {
                clear_terminal();
                printf("\n");
                ascii_cartadd();
                char name[100], temp[100]; 
                int jumlah = -1, index3 = index2, space = 0;
                boolean isNumeric = true;

                while (currentWord.TabWord[index2] != '\0') {
                    if (currentWord.TabWord[index2] == ' ') space++;
                    index2++;
                }
                index2 = index3;
                index3 = 0;

                while (space > 1) {
                    name[index3++] = currentWord.TabWord[index2++];
                    if (currentWord.TabWord[index2] == ' ') space--;
                }
                
                if (space == 1) {
                    while (currentWord.TabWord[index2] != ' ') {
                        name[index3++] = currentWord.TabWord[index2++];
                    }
                    index2++; 
                    
                    int tempIndex = 0;
                    while (currentWord.TabWord[index2] != '\0') {
                        if (currentWord.TabWord[index2] < '0' || currentWord.TabWord[index2] > '9') {
                            isNumeric = false;
                            name[index3++] = ' ';
                            while (currentWord.TabWord[index2] != '\0') {
                                name[index3++] = currentWord.TabWord[index2++];
                            }
                            break;
                        }
                        temp[tempIndex++] = currentWord.TabWord[index2++];
                    }
                    temp[tempIndex] = '\0';
                    
                    if (isNumeric && tempIndex > 0) {
                        name[index3] = '\0';
                        stringtoint(temp, &jumlah);
                    } else {
                        name[index3] = '\0';
                        jumlah = -1;
                    }
                } else {
                    while (currentWord.TabWord[index2] != '\0') {
                        name[index3++] = currentWord.TabWord[index2++];
                    }
                    name[index3] = '\0';
                    jumlah = -1;
                }
                
                CART_ADD(name, jumlah);
            }

            else if (isEqual(command2, "CART REMOVE")) {
                clear_terminal();
                printf("\n");
                ascii_cartremove();
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
                CART_REMOVE(name, jumlah);
            }
            
            else if(isEqual(command2, "CART SHOW") || isEqual(command, "9")){
                clear_terminal();
                printf("\n");
                ascii_cartshow();
                CART_SHOW();
            }
            else if(isEqual(command2, "CART PAY") || isEqual(command, "10")){
                clear_terminal();  
                printf("\n");
                ascii_cartpay();
                CART_PAY();
            }
            else if(isEqual(command2, "PROFILE") || isEqual(command, "11")){
                clear_terminal();
                printf("\n");
                ascii_profile();
                PROFILE();
            }
            else if(isEqual(command2, "WISHLIST ADD") || isEqual(command, "12")){
                clear_terminal();
                printf("\n");
                ascii_wishlistadd();
                WISHLIST_ADD();
            }
            else if(isEqual(command3, "WISHLIST REMOVE")){
                clear_terminal();
                printf("\n");
                ascii_wishlistremove();
                WISHLIST_REMOVE_2();
            }
            else if(isEqual(command2, "WISHLIST REMOVE")){
                clear_terminal();
                printf("\n");
                ascii_wishlistremove();
                int i,index3=0;char temp[100];
                while (currentWord.TabWord[index2]!='\0')
                {
                    temp[index3++]=currentWord.TabWord[index2++];
                }
                temp[index3]='\0';
                stringtoint(temp,&i);

                WISHLIST_REMOVE_1(i);
            }
            else if(isEqual(command2, "WISHLIST CLEAR") || isEqual(command, "14")){
                clear_terminal();
                printf("\n");
                ascii_wishlistclear();
                WISHLIST_CLEAR();
            }
            else if(isEqual(command2, "WISHLIST SHOW") || isEqual(command, "15")){
                clear_terminal();
                printf("\n");
                ascii_wishlistshow();
                WISHLIST_SHOW();
            }
            else if(isEqual(command2, "WISHLIST SWAP")){
                clear_terminal();
                printf("\n");
                ascii_wishlistswap();
                int i, j;
                char temp[100]; 
                int index3 = 0;
                index2 = 0; // Reset index2

                // Skip "WISHLIST" and "SWAP"
                while (currentWord.TabWord[index2] != '\0' && currentWord.TabWord[index2] != ' ') {
                    index2++;
                }
                while (currentWord.TabWord[index2] == ' ') {
                    index2++;
                }
                while (currentWord.TabWord[index2] != '\0' && currentWord.TabWord[index2] != ' ') {
                    index2++;
                }
                while (currentWord.TabWord[index2] == ' ') {
                    index2++;
                }

                // Get first number
                while (currentWord.TabWord[index2] >= '0' && currentWord.TabWord[index2] <= '9') {
                    temp[index3++] = currentWord.TabWord[index2++];
                }
                temp[index3] = '\0';
                stringtoint(temp, &i);

                // Skip spaces between numbers
                while (currentWord.TabWord[index2] == ' ') {
                    index2++;
                }

                // Get second number
                index3 = 0;
                while (currentWord.TabWord[index2] >= '0' && currentWord.TabWord[index2] <= '9') {
                    temp[index3++] = currentWord.TabWord[index2++];
                }
                temp[index3] = '\0';
                stringtoint(temp, &j);

                printf("Swapping positions %d and %d\n", i, j);
                WISHLIST_SWAP(i, j);
            }
            else if(isEqual(command, "HISTORY")){
                clear_terminal();
                printf("\n");
                ascii_history();

                char temp[100];
                int i = -1;
                int index3 = 0;
                index2 =0;

                while (currentWord.TabWord[index2] != '\0' && currentWord.TabWord[index2] != ' ') {
                    index2++;
                }

                while (currentWord.TabWord[index2] == ' ') {
                    index2++;
                }

                while (currentWord.TabWord[index2] != '\0') {
                    if (currentWord.TabWord[index2] >= '0' && currentWord.TabWord[index2] <= '9') {
                        temp[index3++] = currentWord.TabWord[index2];
                    }
                    index2++;
                }

                if (index3 > 0) {
                    temp[index3] = '\0';
                    stringtoint(temp, &i);
                }

                HISTORY(i);
            }
            else if(isEqual(command, "LOGOUT") || isEqual(command, "18")){
                clear_terminal();
                printf("\n");
                ascii_logout();
                LOGOUT();
            } else if(isEqual(command, "HELP") || isEqual(command, "21")){
                clear_terminal();
                printf("\n");
                HELP(start, login);
                printf("Ketik apapun untuk kembali ke menu utama\n");
                printf(">>> ");
                STARTWORD2();
            }
            else if(isEqual(command, "SAVE")){
                clear_terminal();
                printf("\n");
                ascii_save();
                char txt[50];
                int i = 0;
                while(currentWord.TabWord[index] != '\0' && i < 50) {
                    txt[i] = currentWord.TabWord[index];
                    i++;
                    index++;
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
            else if(isEqual(command, "QUIT") || isEqual(command, "20")){
            clear_terminal();
            printf("\n");
            ascii_quit();
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
            
            else{
                printf("Command tidak valid, silakan ulangi kembali!\n");
            }
        }
    }
    return 0;
}



