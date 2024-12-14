#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    printf("Masukkan sebuah kalimat (akhiri dengan titik) :\n");
    START();

    printf("Karakter yang terbaca:\n");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");

    printf("\nPembacaan selesai\n");

    return 0;
}
