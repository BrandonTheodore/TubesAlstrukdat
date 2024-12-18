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
        char* itemName;
        strcopy(user->keranjang.Elements[i].Key, itemName);
        int quantity = user->keranjang.Elements[i].Value;
        int price = AD.A[SearchArrayDin(AD, itemName)].price;
        int itemTotal = quantity * price;
        
        printf("%-10d %-7s %d\n", quantity, itemName, itemTotal);
        totalCost += itemTotal;
    }

    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalCost);
}