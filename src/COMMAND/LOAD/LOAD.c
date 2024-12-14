#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "LOAD.h"

FILE* file;
boolean load;
boolean start;
ArrayDin AD;
List L;

void LOAD(char txt[50]){
    L = MakeList();
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
        printf("File %s berhasil dibaca!\n", txt); start = true;
        printf("\n");
        load = true;
        int line;
        fscanf(file, "%d", &line);
        for(int i = 0; i < line; i++){
            int harga;
            char barang[50];
            fscanf(file, "%d %s", &harga, barang);
            InsertLastDin(&AD, barang, harga);
        }
        int line1;
        fscanf(file, "%d", &line1);
        printf("%d\n", line1);
        for(int i = 0; i < line1; i++){
            int money;
            char name[50];
            char pass[50];
            fscanf(file, "%d %s %s", &money, name, pass);
            printf("%d %s %s\n", money, name, pass);
            InsertLast(&L, name, pass, money);
        }
        for(int i = 0; i < 2; i++){
            printf("%d %s %s\n", L.A[i].money, L.A[i].name, L.A[i].password);
        }
        printf("\n");
    }
}