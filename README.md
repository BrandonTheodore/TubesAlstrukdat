# Tugas Besar IF2111 - Algoritma dan Struktur Data STI

## Deskripsi

> Repository ini ditujukan untuk memenuhi Tugas Besar Algoritma dan Struktur Data STI IF2111 tahun ajaran 2024/2025

PURRMART adalah sebuah aplikasi yang dapat mensimulasikan aktivitas beli barang pada e-commerce. PURRMART memiliki beberapa fitur utama, yaitu:
- Menampilkan barang toko
- Meminta dan menyuplai barang baru ke toko
- Menyimpan dan membeli barang dalam keranjang
- Menampilkan barang yang sudah dibeli
- Membuat dan menghapus wishlist
- Bekerja untuk menghasilkan uang

## Anggota Kelompok

**Kelompok 6 Kelas K-02 :**

| NIM          | Nama                       |
| ---          | ---                        |
| 18223020     | Brandon Theodore Ferrinov  |
| 18223034     | Ratukhansa Salsabila       |
| 18223042     | Darryl Rayhananta Adenan   |
| 18223086     | Raditya Zaki Athaya        |
| 18223096     | Matthew Sebastian Kurniawan|

## Setup program
Pastikan di komputer anda dapat menjalankan fungsi ```make```.  
- Untuk OS Unix (Linux) lakukan :
    ```
    sudo apt install make
    ```
- Untuk OS Windows dapat menonton video dibawah :
https://www.youtube.com/watch?v=a3ejgWLqelQ

!jika tidak bisa! 
- Ketik "mingw32-make" pada terminal bin, setelah itu akan muncul file purrmart.exe
- jalankan program dengan ketik "./PURRMART" 

{Cara Menjalankan gcc Secara Manual}
- Navigasi ke Direktori src
- Kompilasi Program Menggunakan gcc =
gcc -o purrmart2 main.c ADT/dynamiclist/dynamiclist.c ADT/List/List.c ADT/mesinkarakter/mesinkarakter.c ADT/mesinkata/mesinkata.c ADT/queue/queue.c ADT/map/map.c ADT/stack/stack.c ADT/listlinier/listlinier.c COMMAND/LOGIN/LOGIN.c COMMAND/HELP/HELP.c COMMAND/LOAD/LOAD.c COMMAND/LOGOUT/LOGOUT.c COMMAND/QUANTUM/quantum.c COMMAND/REGISTER/REGISTER.c COMMAND/SAVE/SAVE.c COMMAND/START/START.c COMMAND/STORE_LIST/store_list.c COMMAND/STORE_REMOVE/store_remove.c COMMAND/STORE_REQUEST/store_request.c COMMAND/STORE_SUPPLY/store_supply.c COMMAND/CART_ADD/cart_add.c COMMAND/CART_SHOW/cart_show.c COMMAND/CART_REMOVE/cart_remove.c COMMAND/CART_PAY/cart_pay.c COMMAND/PROFILE/profile.c COMMAND/WISHLIST_ADD/wishlist_add.c COMMAND/WISHLIST_REMOVE_1/wishlist_remove_1.c COMMAND/WISHLIST_REMOVE_2/wishlist_remove_2.c COMMAND/WISHLIST_CLEAR/wishlist_clear.c COMMAND/WISHLIST_SHOW/wishlist_show.c COMMAND/WISHLIST_SWAP/wishlist_swap.c COMMAND/HISTORY/history.c COMMAND/WORK_CHALLENGE/work_challenge.c COMMAND/WORK/work.c COMMAND/TEBAKANGKA/tebakangka.c COMMAND/WORDL3/wordl3.c asciart/asciiart.c
- Jalankan Program dengan .\purrmart2.exe atau ./purrmart2