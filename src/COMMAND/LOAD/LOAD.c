#include <stdio.h>
#include <stdlib.h>
#include "LOAD.h"

boolean load;
boolean start;
ArrayDin AD;
List userList;

void LOAD(char txt[50]){
    userList = MakeList();
    AD = MakeArrayDin();
    char path[100] = "../save/";
    int i = 0;
    while(path[i] != '\0') i++;
    int j = 0;
    while(txt[j] != '\0' && i < 100){
        path[i++] = txt[j++];
    }
    path[i] = '\0';
    printf("%s\n", path);
    start_files(path);
    if(!load){
        printf("File gagal dibaca!\n");
        return;
    } else {
        printf("File %s berhasil dibaca!\n", txt); 
        start = true;
        load = true;

        int itemCount;
        baca_line();
        itemCount = wordToInt(currentWord);
        for(int i = 0; i < itemCount; i++){
            char name[MAX_LEN];
            int price;

            // Read price
            baca_line();
            int j = 0; Word temp; temp.Length = 0;
            while (currentWord.TabWord[j] != ' ' && currentWord.TabWord[j] != '\0') {
                temp.TabWord[j] = currentWord.TabWord[j];
                j++; temp.Length++;
            }
            temp.TabWord[j] = '\0';

            price = wordToInt(temp);

            j++;
            int k = 0;
            while(currentWord.TabWord[j] != '\n' && currentWord.TabWord[j] != '\0'){
                name[k] = currentWord.TabWord[j];
                j++; k++;
            }
            name[k] = '\0';

            InsertLastDin(&AD, name, price);
        }

        // Read users
        int userCount;
        baca_line();
        userCount = wordToInt(currentWord);
        for(int i = 0; i < userCount; i++){
            User newUser; Word temp; temp.Length = 0;

            // Read user money
            baca_line();
            int j = 0;
            while (currentWord.TabWord[j] != ' ' && currentWord.TabWord[j] != '\0'){
                temp.TabWord[j] = currentWord.TabWord[j];
                j++; temp.Length++;
            }
            temp.TabWord[j] = '\0';
            
            newUser.money = wordToInt(temp);
            j++;

            // Read user name
            int k = 0;
            while (currentWord.TabWord[j] != ' ' && currentWord.TabWord[j] != '\0'){
                newUser.name[k] = currentWord.TabWord[j];
                j++; k++;
            }
            newUser.name[k] = '\0';
            j++;

            // Read user password
            k = 0;
            while (currentWord.TabWord[j] != ' ' && currentWord.TabWord[j] != '\0'){
                newUser.password[k] = currentWord.TabWord[j];
                j++; k++;
            }
            newUser.password[k] = '\0';
            j++;

            k=0;
            while(currentWord.TabWord[j] != '\n' && currentWord.TabWord[j] != '\0'){
                newUser.nickname[k] = currentWord.TabWord[j];
                j++; k++;
            }
            newUser.nickname[k] = '\0';

            baca_line();
            newUser.umur = wordToInt(currentWord);

            /* Initialize user's structures */
            CreateEmptyMap(&newUser.keranjang);
            CreateEmptyStack(&newUser.riwayat_pembelian);
            CreateEmptyLinier(&newUser.wishlist);

            // Read purchase history
            int historyCount;
            baca_line();
            historyCount = wordToInt(currentWord);
            for(int j = 0; j < historyCount; j++){
                Word temp; temp.Length = 0;
                int totalHarga;
                char itemName[MAX_LEN];

                // Read total price
                baca_line();
                int k = 0;
                while (currentWord.TabWord[k] != ' ' && currentWord.TabWord[k] != '\0'){
                    temp.TabWord[k] = currentWord.TabWord[k];
                    k++; temp.Length++;
                }
                temp.TabWord[k] = '\0';
                totalHarga = wordToInt(temp);
                k++;

                // Read item name
                int l = 0;
                while (currentWord.TabWord[k] != '\n' && currentWord.TabWord[k] != '\0'){
                    itemName[l] = currentWord.TabWord[k];
                    k++; l++;
                }
                itemName[l] = '\0';

                // Add to purchase history
                infotypeStack tempStack;
                tempStack.totalHarga = totalHarga;
                tempStack.namaBarang = (char*) malloc(MAX_LEN * sizeof(char));
                strcopy(itemName, tempStack.namaBarang);
                PushStack(&newUser.riwayat_pembelian, tempStack);
            }

            // Read wishlist
            int wishlistCount;
            baca_line();
            wishlistCount = wordToInt(currentWord);
            for(int j = 0; j < wishlistCount; j++){
                char itemName[MAX_LEN];
                baca_line();
                strcopy(currentWord.TabWord, itemName);
                InsVLastLinier(&newUser.wishlist, itemName);
            }

            InsertLast(&userList, newUser);
        }
    }
}
