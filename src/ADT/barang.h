// barang.h
#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 100

// Struktur Barang
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

// Fungsi untuk menginisialisasi data barang
void InitBarang(Barang *barang, char *name, int price);

// Fungsi untuk menyalin nama barang (jika diperlukan)
void CopyBarangName(Barang *barang, char *name);

#endif
