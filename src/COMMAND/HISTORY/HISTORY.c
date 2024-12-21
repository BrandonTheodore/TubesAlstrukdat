#include <stdio.h>
#include "history.h"

void HISTORY(int n) {
    User *user = &userList.A[IDX];

    // Check empty stack
    if (IsEmptyStack(user->riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    if (n == -1) {
        printf("Masukkan jumlah riwayat yang ingin dilihat!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");
    
    Stack tempStack = user->riwayat_pembelian;
    int ukuran = 0;
    Stack tempCount = tempStack;
    while (!IsEmptyStack(tempCount)) {
        infotypeStack temp;
        PopStack(&tempCount, &temp);
        ukuran++;
    }

    int tampilan;
    if (n > ukuran) {
        tampilan = ukuran;
    } else {
        tampilan = n;
    }
    
    int count = 1;
    while (!IsEmptyStack(tempStack) && count <= tampilan) {
        infotypeStack purchase;
        purchase.namaBarang = (char*)malloc((strlength(InfoTop(tempStack).namaBarang) + 1) * sizeof(char));
        PopStack(&tempStack, &purchase);
        printf("%d. %s\n", count, purchase.namaBarang);
        free(purchase.namaBarang);
        count++;
    }
}