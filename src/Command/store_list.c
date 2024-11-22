#include "store_list.h"
#include <stdio.h>

void store_list(List *itemList) {
    int len = Length(*itemList);
    
    if (len == 0) {
        printf("TOKO KOSONG\n");
    } else {
        int seen[MaxEl] = {0};  
        printf("List barang yang ada di toko:\n");
        
        for (int i = FirstIdx(*itemList); i <= LastIdx(*itemList); i++) {
            ElType item = Get(*itemList, i);
            
            if (!seen[item]) {
                printf("- %d\n", item);  
                seen[item] = 1;  
            }
        }
    }
}