#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    Listlinier L;
    infotypelist val;

    printf("1. Tes CreateEmptyLinier dan IsEmptyLinier:\n");
    CreateEmptyLinier(&L);
    if (IsEmptyLinier(L)) {
        printf("List kosong berhasil dibuat\n\n");
    }

    printf("2. Tes InsVLastLinier:\n");
    InsVLastLinier(&L, "AK47");
    InsVLastLinier(&L, "Shotgun");
    InsVLastLinier(&L, "Pistol");
    printf("List setelah insert:\n");
    PrintInfoLinier(L);
    printf("\n");

    printf("3. Tes InsVFirstLinier:\n");
    InsVFirstLinier(&L, "RPG");
    printf("List setelah insert di awal:\n");
    PrintInfoLinier(L);
    printf("\n");

    printf("4. Tes SearchLinier:\n");
    address_list found = SearchLinier(L, "Shotgun");
    if (found != NilList) {
        printf("Shotgun ditemukan\n");
    } else {
        printf("Shotgun tidak ditemukan\n");
    }
    printf("\n");

    printf("5. Tes DelVFirstLinier:\n");
    DelVFirstLinier(&L, &val);
    printf("Item yang dihapus: %s\n", val);
    printf("List setelah melakukan DelVFirstLinier:\n");
    PrintInfoLinier(L);
    printf("\n");

    printf("6. Tes NbElmtLinier:\n");
    printf("Jumlah elemen: %d\n\n", NbElmtLinier(L));

    printf("7. Tes InversLinier:\n");
    InversLinier(&L);
    printf("List setelah dilakukan invers:\n");
    PrintInfoLinier(L);
    printf("\n");

    // Cleanup - deallocate memory
    while (!IsEmptyLinier(L)) {
        DelVFirstLinier(&L, &val);
    }

    return 0;
}