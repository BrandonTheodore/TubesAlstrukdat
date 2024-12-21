#include <stdio.h>
#include "history.h"

void HISTORY(int n) {
    User *user = &userList.A[IDX];
    if (IsEmptyStack(user->riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    if (n == -1) {
        printf("Masukkan jumlah riwayat yang ingin dilihat!\n");
        return;
    }

    printf("Riwayat pembelian barang: %d\n",n);
    
    Stack tempStack = user->riwayat_pembelian;
    Stack dummy;
    CreateEmptyStack(&dummy);
    
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
        PopStack(&tempStack, &purchase);
        printf("%d. %s (Rp. %d)\n", count, purchase.namaBarang, purchase.totalHarga);
        PushStack(&dummy, purchase);
        count++;
    }
    while (!IsEmptyStack(dummy)) {
        infotypeStack purchase;
        PopStack(&dummy, &purchase);
        PushStack(&user->riwayat_pembelian, purchase);
    }
}