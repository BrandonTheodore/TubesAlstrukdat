#include <stdio.h>
#include "wishlist_swap.h"

void WISHLIST_SWAP(int i, int j) {
    User *user = &userList.A[IDX];

    if (NbElmtLinier(user->wishlist) < 2) {
        printf("Gagal menukar posisi! Wishlist memiliki kurang dari 2 item.\n");
        return;
    }

    if (i < 1 || i > NbElmtLinier(user->wishlist) || j < 1 || j > NbElmtLinier(user->wishlist)) {
        printf("Posisi tidak valid!\n");
        return;
    }

    address_list P = First(user->wishlist);
    address_list Q = First(user->wishlist);

    for (int idx = 1; idx < i; idx++) {
        P = Next(P);
    }
    
    for (int idx = 1; idx < j; idx++) {
        Q = Next(Q);
    }

    char tempItem[MAX_LEN];
    strcopy(tempItem, Info(P));
    strcopy(Info(P), Info(Q));
    strcopy(Info(Q), tempItem);

    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", Info(Q), Info(P));
}