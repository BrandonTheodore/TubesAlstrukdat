#include <stdio.h>
#include "profile.h"

void PROFILE() {
    if (!login) {
        printf("Error: Anda belum login! Silahkan login terlebih dahulu.\n");
        return;
    }

    User *user = &userList.A[IDX];  

    printf("..................................................\n");
    printf("..................................................\n");
    printf("..................................................\n");
    printf(".........................,........................\n");
    printf("...................*************..................\n");
    printf(".................****************,................\n");
    printf("................*******************...............\n");
    printf("................******************* ..............\n");
    printf("................*******************...............\n");
    printf(".................*****************................\n");
    printf("..................**************,.................\n");
    printf(".....................,*******,....................\n");
    printf("...................,***********,..................\n");
    printf(".............*************************............\n");
    printf("..........*******************************.........\n");
    printf("........***********************************.......\n");
    printf("......,*************************************,.....\n");
    printf("......,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.....\n");
    printf("\n");
    printf("  _____  _____   ____  ______ _____ _      ______ \n");
    printf(" |  __ \\|  __ \\ / __ \\|  ____|_   _| |    |  ____|\n");
    printf(" | |__) | |__) | |  | | |__    | | | |    | |__   \n");
    printf(" |  ___/|  _  /| |  | |  __|   | | | |    |  __|  \n");
    printf(" | |    | | \\ \\| |__| | |     _| |_| |____| |____ \n");
    printf(" |_|    |_|  \\_\\\\____/|_|    |_____|______|______|\n");
    printf("                                                  \n");
    printf("                                                  \n");
    printf(">> PROFILE\n");
    printf("Nama  : %s\n", user->name);
    printf("Nickname : %s\n", user->nickname);
    printf("Umur  : %d\n", user->umur);
    printf("Saldo : %d\n", user->money);
    printf("..................................................\n");

    printf("\nApakah Anda ingin mengedit profile Anda? (y/n): ");
    RESETWORD();
    STARTWORD2(); 
    char choice = currentWord.TabWord[0];

    if (choice == 'y' || choice == 'Y') {
        printf("Apa yang ingin Anda edit?\n");
        printf("1. Nickname\n");
        printf("2. Umur\n");
        printf("3. Username\n");
        printf(">>> ");
        RESETWORD();
        STARTWORD2(); 

        if (currentWord.Length == 0) {
            printf("Pilihan tidak valid.\n");
            return;
        }
        else if (isEqual(currentWord.TabWord, "Nickname") || isEqual(currentWord.TabWord, "1")) {
            printf("Masukkan nickname baru: ");
            RESETWORD();
            STARTWORD2();

            if (currentWord.Length == 0 || currentWord.Length >= MAX_LEN) {
                printf("Nickname tidak valid.\n");
                return;
            }
            
            int i = 0;
            while (i < currentWord.Length && i < MAX_LEN - 1) {
                user->nickname[i] = currentWord.TabWord[i];
                i++;
            }
            user->nickname[i] = '\0';
            printf("Nickname Anda berhasil diperbarui menjadi: %s\n", user->nickname);
        }
        else if (isEqual(currentWord.TabWord, "Umur") || isEqual(currentWord.TabWord, "2")) {
            printf("Masukkan umur baru: ");
            RESETWORD();
            STARTWORD2();
            if (currentWord.Length == 0 || !isNumber(currentWord)) {
                printf("Umur tidak valid.\n");
                return;
            }
            user->umur = wordToInt(currentWord);
            printf("Umur Anda berhasil diperbarui menjadi: %d\n", user->umur);
        }
        else if (isEqual(currentWord.TabWord, "Username") || isEqual(currentWord.TabWord, "3")) {
            printf("Masukkan Username baru: ");
            RESETWORD();
            STARTWORD2();
            if (currentWord.Length == 0 || currentWord.Length >= MAX_LEN) {
                printf("Username tidak valid.\n");
                return;
            }
            int i = 0;
            while (i < currentWord.Length && i < MAX_LEN - 1) {
                user->name[i] = currentWord.TabWord[i];
                i++;
            }
            user->name[i] = '\0';
            printf("Nama Anda berhasil diperbarui menjadi: %s\n", user->name);
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
        RESETWORD(); 
    }
    else if (choice == 'n' || choice == 'N') {
        return;
    }
    else {
        printf("Pilihan tidak valid.\n");
    }
}