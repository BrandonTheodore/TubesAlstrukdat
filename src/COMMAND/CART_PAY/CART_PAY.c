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
            for (int i = 0; i < user->keranjang.Count; i++) {
                char itemName[100]; strcopy(user->keranjang.Elements[i].Key, itemName);
                int quantity = user->keranjang.Elements[i].Value;
                int price = AD.A[SearchArrayDin(AD, itemName)].price;
                int itemTotal = quantity * price;
                
                // Add to purchase history
                
                infotypeStack purchase;
                purchase.namaBarang= (char*)malloc((strlength(itemName) + 1) * sizeof(char));
                strcopy(itemName, purchase.namaBarang);
                purchase.totalHarga = itemTotal;
                PushStack(&user->riwayat_pembelian, purchase);
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