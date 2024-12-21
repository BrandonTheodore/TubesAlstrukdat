#include <stdio.h>
#include "history.h"

void HISTORY(int n) {
    User *user = &userList.A[IDX];

    if (IsEmptyStack(user->riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");
    
    Stack tempStack = user->riwayat_pembelian;
    while (!IsEmptyStack(tempStack)) {
        infotypeStack purchase;
        purchase.namaBarang = (char*)malloc((strlength(InfoTop(tempStack).namaBarang) + 1) * sizeof(char));
        PopStack(&tempStack, &purchase);
        printf("Barang: %s, Harga: %d\n", purchase.namaBarang, purchase.totalHarga);
    }
}