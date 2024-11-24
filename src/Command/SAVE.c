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
    file = fopen(path, "w");
    fprintf("%d\n", AD.Neff);
    for(int i = 0; i < AD.Neff; i++){
        fprintf("%d %s\n", AD.A[i].price, AD.A[i].name);
    }
    fprintf("%d", L.Neff);
    for(int i = 0; i < L.Neff; i++){
        fprintf("%d %s %s\n", L.A[i].money, L.A[i].name, L.A[i].password);
    }

    fclose(path);
}