#include <stdio.h>
#include "cart_show.h"

void CART_SHOW() {
    User *user = &userList.A[IDX];

    if (IsEmptyMap(user->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    int totalCost = 0;
    printf("Berikut adalah isi keranjangmu.\n");
    printf("Kuantitas  Nama    Total\n");

    for (int i = 0; i < user->keranjang.Count; i++) {
        char itemName[MAX_LEN];  
        strcopy(user->keranjang.Elements[i].Key, itemName);
        int quantity = user->keranjang.Elements[i].Value;
        int idx = SearchArrayDin(AD, itemName);
        if (idx != -1) {  
            int price = AD.A[idx].price;
            int itemTotal = quantity * price;
            
            printf("%-10d %-7s %d\n", quantity, itemName, itemTotal);
            totalCost += itemTotal;
        }
    }

    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalCost);
}