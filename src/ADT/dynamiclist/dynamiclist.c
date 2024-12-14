#include <stdio.h>
#include <stdlib.h>
#include "dynamiclist.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (Barang *) malloc(InitialSize * sizeof(Barang));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyDin(ArrayDin array) {
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthDin(ArrayDin array) {
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
// char Get(ArrayDin array, int i) {
//     return array.A[i];
// }

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityDin(ArrayDin array) {
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertAtDin(ArrayDin *array, char el[50], int price, int i) {
    int length = LengthDin(*array);
    int capacity = GetCapacityDin(*array);

    Barang b;
    int x = 0;
    while(el[x] != '\0'){
        b.name[x] = el[x];
        x++;
    }
    b.name[x] = '\0';
    b.price = price;

    if (length == capacity) {
        int desiredCapacity = capacity + 1;
        Barang *arr = (Barang *) malloc(desiredCapacity * sizeof(Barang));
        for (int a = 0; a < length; a++){
            arr[a] = array->A[a];
            
        }
        free(array->A);
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = b;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastDin(ArrayDin *array, char el[50], int price) {
    int insertAt = LengthDin(*array);
    InsertAtDin(array, el, price, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstDin(ArrayDin *array, char el[50], int price) {
    InsertAtDin(array, el, price, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtDin(ArrayDin *array, int i) {
    int length = LengthDin(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLastDin(ArrayDin *array) {
    int deleteAt = LengthDin(*array) - 1;
    DeleteAtDin(array, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirstDin(ArrayDin *array) {
    DeleteAtDin(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
// void PrintArrayDin(ArrayDin array) {
//     if (IsEmpty(array)) {
//         printf("[]\n");
//     } else {
//         printf("[");
//         for (int i = 0; i < array.Neff; i++) {
//             printf("%d", array.A[i]);
//             if (i < array.Neff - 1) {
//                 printf(", ");
//             }
//         }
//         printf("]\n");
//     }
// }

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
// void ReverseArrayDin(ArrayDin *array) {
//     int length = Length(*array);
//     for (int i = 0; i < length / 2; i++) {
//         char temp = array->A[i];
//         array->A[i] = array->A[length - i - 1];
//         array->A[length - i - 1] = temp;
//     }
// }

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
// ArrayDin CopyArrayDin(ArrayDin array) {
//     ArrayDin copy = MakeArrayDin();
//     for (int i = 0; i < array.Neff; i++) {
//         InsertLastDin(&copy, array.A[i]);
//     }
//     return copy;
// }

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
int SearchArrayDin(ArrayDin array, char el[50]) {
    for (int i = 0; i < array.Neff; i++) {
        if (isEqual(el, array.A[i].name)) {
            return i;
        }
    }
    return -1;
}