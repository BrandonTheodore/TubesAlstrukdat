#include <stdio.h>
#include "cart_pay.h"

void CART_PAY() {
    User *user = &userList.A[IDX];

    if (IsEmptyMap(user->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    int totalCost = 0;
    int maxItemTotal = 0;
    char maxItemName[MAX_LEN];
    
    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("Kuantitas  Nama    Total\n");

    for (int i = 0; i < user->keranjang.Count; i++) {
        char* itemName = user->keranjang.Elements[i].Key;
        int quantity = user->keranjang.Elements[i].Value;
        int price = AD.A[SearchArrayDin(AD, itemName)].price;
        int itemTotal = quantity * price;
        
        printf("%-10d %-7s %d\n", quantity, itemName, itemTotal);
        totalCost += itemTotal;
        
        if (itemTotal > maxItemTotal || 
            (itemTotal == maxItemTotal && isEqual(itemName, maxItemName) > 0)) {
            maxItemTotal = itemTotal;
            strcopy(itemName, maxItemName);
        }
    }

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalCost);
    RESETWORD();
    STARTWORD2();

    if (isEqual(currentWord.TabWord, "Ya")) {
        if (user->money >= totalCost) {
            user->money -= totalCost;

            int m = idxMaxValueMap(user->keranjang);
            infotypeStack purchase;
            char b[MAX_LEN];
            strcopy(user->keranjang.Elements[m].Key, b);
            purchase.namaBarang = (char*)malloc((strlength(b) + 1) * sizeof(char));
            strcopy(user->keranjang.Elements[m].Key, purchase.namaBarang);
            purchase.totalHarga = user->keranjang.Elements[m].Value * AD.A[SearchArrayDin(AD,b)].price;
            PushStack(&user->riwayat_pembelian, purchase);


            for (int i = 0; i < user->keranjang.Count; i++) {
                char itemName[100]; strcopy(user->keranjang.Elements[i].Key, itemName);
                int quantity = user->keranjang.Elements[i].Value;
                int price = AD.A[SearchArrayDin(AD, itemName)].price;
                int itemTotal = quantity * price;
            }
            CreateEmptyMap(&user->keranjang);
            printf("\nSelamat kamu telah membeli barang-barang tersebut!\n");
        } else {
            printf("\nUang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", user->money);
        }
    } else if (isEqual(currentWord.TabWord, "Tidak")) {
        return;
    } else {
        printf("Input tidak valid.\n");
    }
}