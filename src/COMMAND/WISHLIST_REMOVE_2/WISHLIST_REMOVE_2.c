#include <stdio.h>
#include "wishlist_remove_2.h"

void WISHLIST_REMOVE_2() {
    User *user = &userList.A[IDX];

    if (IsEmptyLinier(user->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    printf("Masukkan nama barang yang akan dihapus : ");
    RESETWORD();
    STARTWORD2();
    
    char itemName[MAX_LEN];
    strcopy(currentWord.TabWord, itemName);

    address_list P = SearchLinier(user->wishlist, itemName);
    if (P == NilList) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", itemName);
        return;
    }

    if (P == First(user->wishlist)) {
        DelFirstLinier(&user->wishlist, &P);
    } else {
        address_list Prec = First(user->wishlist);
        while (Next(Prec) != P) {
            Prec = Next(Prec);
        }
        DelAfterLinier(&user->wishlist, &P, Prec);
    }

    printf("%s berhasil dihapus dari WISHLIST!\n", itemName);
}