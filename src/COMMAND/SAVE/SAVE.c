#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "SAVE.h"

FILE *file;
ArrayDin AD;
List L;

void SAVE(char txt[50]){
    char path[100] = "../save/";
    int a = 8;
    int b = 0;
    while(a < 100){
        path[a] = txt[b];
        a++;
        b++;
    }
    path[a] = '\0';
    printf("%s\n", txt);
    printf("%s\n", path);
    file = fopen(path, "w");
    fprintf(file, "%d\n", AD.Neff);
    for(int i = 0; i < AD.Neff; i++){
        fprintf(file, "%d %s\n", AD.A[i].price, AD.A[i].name);
    }
    fprintf(file, "%d\n", L.Neff);
    for(int i = 0; i < L.Neff; i++){
        fprintf(file, "%d %s %s\n", L.A[i].money, L.A[i].name, L.A[i].password);
    }

    fclose(file);
    printf("File berhasil di simpan!\n");
}