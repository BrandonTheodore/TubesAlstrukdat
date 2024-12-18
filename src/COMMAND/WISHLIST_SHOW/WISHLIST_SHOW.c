#include <stdio.h>
#include "wishlist_show.h"

void WISHLIST_SHOW() {
    User *user = &userList.A[IDX];

    if (IsEmptyLinier(user->wishlist)) {
        printf("Wishlist kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi wishlist-mu:\n");
    
    address_list P = First(user->wishlist);
    int count = 1;
    
    while (P != NilList) {
        printf("%d. %s\n", count, Info(P));
        P = Next(P);
        count++;
    }
}