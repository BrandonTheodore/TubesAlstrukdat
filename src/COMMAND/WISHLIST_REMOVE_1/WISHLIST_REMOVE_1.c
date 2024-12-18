#include <stdio.h>
#include "wishlist_remove_1.h"

void WISHLIST_REMOVE_1(int pos) {
    User *user = &userList.A[IDX];

    // Check if wishlist is empty
    if (IsEmptyLinier(user->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Check if position is valid
    if (pos < 1 || pos > NbElmtLinier(user->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", pos);
        return;
    }

    // Delete item at position
    address_list P = First(user->wishlist);
    if (pos == 1) {
        DelFirstLinier(&user->wishlist, &P);
    } else {
        address_list Prec = First(user->wishlist);
        for (int i = 1; i < pos-1; i++) {
            Prec = Next(Prec);
        }
        DelAfterLinier(&user->wishlist, &P, Prec);
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", pos);
}