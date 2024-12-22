#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    Listlinier L;
    infotypelist val;

    printf("1. Test CreateEmptyLinier dan IsEmptyLinier:\n");
    CreateEmptyLinier(&L);
    if (IsEmptyLinier(L)) {
        printf("List berhasil dibuat dan kosong\n\n");
    }

    printf("2. Test InsVLastLinier:\n");
    InsVLastLinier(&L, "AK47");
    InsVLastLinier(&L, "Shotgun");
    InsVLastLinier(&L, "Pistol");
    printf("List setelah insert:\n");
    PrintInfoLinier(L);
    printf("\n");

    printf("3. Test InsVFirstLinier:\n");
    InsVFirstLinier(&L, "RPG");
    printf("List setelah insert di awal:\n");
    PrintInfoLinier(L);
    printf("\n");

    printf("4. Test SearchLinier:\n");
    address_list found = SearchLinier(L, "Shotgun");
    if (found != NilList) {
        printf("Shotgun ditemukan\n");
    } else {
        printf("Shotgun tidak ditemukan\n");
    }
    printf("\n");

    printf("5. Test DelVFirstLinier:\n");
    DelVFirstLinier(&L, &val);
    printf("Item yang dihapus: %s\n", val);
    printf("List setelah delete:\n");
    PrintInfoLinier(L);
    printf("\n");

    printf("6. Test NbElmtLinier:\n");
    printf("Jumlah elemen: %d\n\n", NbElmtLinier(L));

    printf("7. Test InversLinier:\n");
    InversLinier(&L);
    printf("List setelah dibalik:\n");
    PrintInfoLinier(L);
    printf("\n");

    // Cleanup - deallocate memory
    while (!IsEmptyLinier(L)) {
        DelVFirstLinier(&L, &val);
    }

    return 0;
}