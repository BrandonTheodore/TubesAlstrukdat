#include <stdio.h>
#include "../master_header_adt.h"

int main() {
    // Reset initial state
    reset();
    
    // Test START and basic character reading
    printf("1. Test pembacaan karakter standard:\n");
    printf("Masukkan kalimat (akhiri dengan titik): ");
    START();
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    reset(); // Reset after test
    printf("\n\n");

    // Test start_files
    printf("2. Test pembacaan file:\n");
    start_files("test.txt");
    printf("Isi file:\n");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    reset(); // Reset after file read
    printf("\n\n");

    // Test reset
    printf("3. Test reset file pointer:\n");
    start_files("test.txt");
    printf("Membaca file lagi setelah reset:\n");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    reset(); // Reset after test
    printf("\n\n");

    // Test IgnoreCRLF
    printf("4. Test IgnoreCRLF:\n");
    printf("Masukkan text dengan enter: \n");
    START();
    IgnoreCRLF();
    printf("Karakter setelah CRLF: %c\n", GetCC());
    reset(); // Final reset

    printf("\nSemua test selesai!\n");
    return 0;
}