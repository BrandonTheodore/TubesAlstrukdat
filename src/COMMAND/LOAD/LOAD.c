#include <stdio.h>
#include <stdlib.h>
#include "LOAD.h"

FILE* file;
boolean load;
boolean start;
ArrayDin AD;
List userList;

void LOAD(char txt[50]){
    userList = MakeList();
    AD = MakeArrayDin();
    char path[100] = "../save/";
    int i = 0;
    int j = 0;
    while(i < 100){
        if(path[i] == '\0'){
            path[i] = txt[j];
            j++;
        }
        i++;
    }
    path[i] = '\0';
    printf("%s\n", path);
    file = fopen(path, "r");
    if(file == NULL){
        printf("File gagal dibaca!\n");
        load = false;
    } else {
        printf("File %s berhasil dibaca!\n", txt); 
        start = true;
        load = true;

        // Read store items
        int itemCount;
        fscanf(file, "%d", &itemCount);
        for(int i = 0; i < itemCount; i++){
            int price;
            char name[MAX_LEN];
            fscanf(file, "%d %s", &price, name);
            InsertLastDin(&AD, name, price);
        }

        // Read users
        int userCount;
        fscanf(file, "%d", &userCount);
        for(int i = 0; i < userCount; i++){
            User newUser;
            fscanf(file, "%d %s %s", 
                &newUser.money,
                newUser.name, 
                newUser.password
            );
            
            // Initialize user's structures
            CreateEmptyMap(&newUser.keranjang);
            CreateEmptyStack(&newUser.riwayat_pembelian);
            CreateEmptyLinier(&newUser.wishlist);
            
            // Read purchase history if any
            int historyCount;
            fscanf(file, "%d", &historyCount);
            for(int j = 0; j < historyCount; j++){
                char itemName[MAX_LEN];
                int quantity;
                fscanf(file, "%d %s", &quantity, itemName);
                infotypeStack temp;
                temp.totalHarga = quantity;
                temp.namaBarang = (char*) malloc(MAX_LEN * sizeof(char));
                strcopy(itemName, temp.namaBarang);
                PushStack(&newUser.riwayat_pembelian, temp);
            }
            
            // Read wishlist if any
            int wishlistCount;
            fscanf(file, "%d", &wishlistCount);
            for(int j = 0; j < wishlistCount; j++){
                char itemName[MAX_LEN];
                fscanf(file, "%s", itemName);
                InsVLastLinier(&newUser.wishlist, itemName);
            }

            InsertLast(&userList, newUser);
        }
        fclose(file);
    }
}