#include "store_list.h"
#include <stdio.h>

ArrayDin AD;

void STORE_LIST() {
    if (AD.Neff == 0) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        
        for (int i = 0; i < AD.Neff; i++) {
            printf("%s\n", AD.A[i].name);            
        }
    }
}