#include <stdio.h>
#include "help.h"

void HELP(boolean start, boolean login) {
    if (!start) {
        printf("+--------------------------------------------------------------------+\n");
        printf("|                SELAMAT DATANG DI BANTUAN WELCOME MENU              |\n");
        printf("+--------------------------------------------------------------------+\n");
        printf("| 1. {START} -> Untuk masuk sesi baru                                |\n");
        printf("| 2. {LOAD}  -> Untuk memulai sesi berdasarkan file konfigurasi      |\n");
        printf("| 3. {QUIT}  -> Untuk keluar dari program                            |\n");
        printf("+--------------------------------------------------------------------+\n");
    } else if (!login) {
        printf("+----------------------------------------------------------------------------+\n");
        printf("|                    SELAMAT DATANG DI BANTUAN LOGIN MENU                    |\n");
        printf("+----------------------------------------------------------------------------+\n");
        printf("| 1. {REGISTER} -> Untuk mendaftarkan akun baru                              |\n");
        printf("| 2. {LOGIN}    -> Untuk masuk ke dalam akun yang sudah terdaftar dan memulai|\n");
        printf("|                sesi                                                        |\n");
        printf("| 3. {PROFILE}  -> Untuk melihat dan mengubah profil pengguna                |\n");
        printf("| 4. {QUIT}     -> Untuk keluar dari program                                 |\n");
        printf("+----------------------------------------------------------------------------+\n");
    } else {
        printf("+----------------------------------------------------------------------------+\n");
        printf("|                      SELAMAT DATANG DI BANTUAN PURRMART                    |\n");
        printf("+----------------------------------------------------------------------------+\n");
        printf("| 1.  {WORK}              -> Untuk bekerja                                   |\n");
        printf("| 2.  {WORK CHALLENGE}    -> Untuk mengerjakan challenge                     |\n");
        printf("| 3.  {STORE LIST}        -> Untuk melihat barang - barang di toko           |\n");
        printf("| 4.  {STORE REQUEST}     -> Untuk meminta penambahan barang                 |\n");
        printf("| 5.  {STORE SUPPLY}      -> Untuk menambahkan barang dari permintaan        |\n");
        printf("| 6.  {STORE REMOVE}      -> Untuk menghapus barang                          |\n");
        printf("| 7.  {CART ADD}          -> Untuk menambah barang ke keranjang              |\n");
        printf("| 8.  {CART REMOVE}       -> Untuk menghapus barang dari keranjang           |\n");
        printf("| 9.  {CART SHOW}         -> Untuk menampilkan isi keranjang                 |\n");
        printf("| 10. {CART PAY}          -> Untuk membayar barang di keranjang              |\n");
        printf("| 11. {PROFILE}           -> Untuk melihat dan mengubah profil               |\n");
        printf("| 12. {WISHLIST ADD}      -> Untuk menambah barang ke wishlist               |\n");
        printf("| 13. {WISHLIST REMOVE 1} -> Untuk menghapus barang ke-i dari wishlist       |\n");
        printf("| 14. {WISHLIST REMOVE 2} -> Untuk menghapus barang berdasarkan nama         |\n");
        printf("| 15. {WISHLIST CLEAR}    -> Untuk mengosongkan wishlist                     |\n");
        printf("| 16. {WISHLIST SHOW}     -> Untuk menampilkan isi wishlist                  |\n");
        printf("| 17. {WISHLIST SWAP}     -> Untuk menukar posisi barang di wishlist         |\n");
        printf("| 18. {HISTORY}           -> Untuk melihat riwayat pembelian                 |\n");
        printf("| 19. {OPTIMASIRUTE}      -> Optimasi Rute Ekspedisi untuk pengiriman barang |\n");
        printf("|                            menggunakan algoritma yang efisien agar semua   |\n");
        printf("|                            titik dapat dikunjungi dengan jarak minimum.    |\n");
        printf("| 20. {GLOBALALIGNMENT}   -> Deteksi Kebocoran Senjata Biologis dengan       |\n");
        printf("|                            algoritma Needleman-Wunsch untuk mencocokkan    |\n");
        printf("|                            sekuens DNA dari lingkungan dengan data DNA.    |\n");
        printf("| 21. {LOGOUT}            -> Untuk keluar dari sesi                          |\n");
        printf("| 22. {SAVE}              -> Untuk menyimpan state ke dalam file             |\n");
        printf("| 23. {QUIT}              -> Untuk keluar dari program                       |\n");
        printf("+----------------------------------------------------------------------------+\n");
        }
    } 


