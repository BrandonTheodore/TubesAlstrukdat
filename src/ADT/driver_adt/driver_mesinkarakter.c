#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    // Reset initial state
    reset();
    
    // Tes START and basic character reading
    printf("1. Tes pembacaan karakter standard:\n");
    printf("Masukkan kalimat (akhiri dengan titik): ");
    START();
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    reset(); // Reset after Tes
    printf("\n\n");

    // Tes start_files
    printf("2. Tes pembacaan file:\n");
    start_files("Tes.txt");
    printf("Isi file:\n");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    reset(); // Reset after file read
    printf("\n\n");

    // Tes reset
    printf("3. Tes reset file pointer:\n");
    start_files("Tes.txt");
    printf("Membaca file lagi setelah reset:\n");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    reset(); // Reset after Tes
    printf("\n\n");

    // Tes IgnoreCRLF
    printf("4. Tes IgnoreCRLF:\n");
    printf("Masukkan text dengan enter: \n");
    START();
    IgnoreCRLF();
    printf("Karakter setelah CRLF: %c\n", GetCC());
    reset(); // Final reset

    printf("\nSemua Tes selesai!\n");
    return 0;
}