#include "help.h"
#include <stdio.h>

void HELP(boolean start, boolean login) {
    if (!start) {
        printf("===SELAMAT DATANG DI BANTUAN WELCOME MENU===\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. QUIT -> Untuk keluar dari program\n");
        printf("============================================\n");
    } else if (!login) {
        printf("===SELAMAT DATANG DI BANTUAN LOGIN MENU===\n");
        printf("1. REGISTER -> Untuk mendaftarkan akun baru\n");
        printf("2. LOGIN -> Untuk masuk ke dalam akun yang sudah terdaftar dan memulai sesi\n");
        printf("3. QUIT -> Untuk keluar dari program\n");
        printf("============================================\n");
    } else {
        printf("===SELAMAT DATANG DI BANTUAN PURRMART===\n");
        printf("1. WORK -> Untuk bekerja\n");
        printf("2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("3. STORE LIST -> Untuk melihat barang - barang di toko\n");
        printf("4. STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("6. STORE REMOVE -> Untuk menghapus barang\n");
        printf("7. LOGOUT -> Untuk keluar dari sesi\n");
        printf("8. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("9. QUIT -> Untuk keluar dari program\n");
        printf("============================================\n");
    }
} 