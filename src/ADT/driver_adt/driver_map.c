#include <stdio.h>
#include "../master_header_adt.h"

void printMap(Map M) {
    printf("Isi Map:\n");
    if (IsEmptyMap(M)) {
        printf("Map kosong\n");
    } else {
        for (int i = 0; i < M.Count; i++) {
            printf("%s: %d\n", M.Elements[i].Key, M.Elements[i].Value);
        }
    }
    printf("Jumlah elemen: %d\n\n", M.Count);
}

int main() {
    Map M;
    
    printf("1. Tes CreateEmptyMap dan IsEmptyMap:\n");
    CreateEmptyMap(&M);
    if (IsEmptyMap(M)) {
        printf("Map berhasil dibuat dan kosong\n\n");
    }

    printf("2. Tes InsertMap:\n");
    InsertMap(&M, "AK47", 5000);
    InsertMap(&M, "Shotgun", 7000);
    InsertMap(&M, "Pistol", 3000);
    printMap(M);

    printf("3. Tes IsMemberMap:\n");
    printf("Apakah ada AK47? %s\n", IsMemberMap(M, "AK47") ? "Ya" : "Tidak");
    printf("Apakah ada RPG? %s\n\n", IsMemberMap(M, "RPG") ? "Ya" : "Tidak");

    printf("4. Tes idxMap:\n");
    printf("Index dari AK47: %d\n", idxMap(M, "AK47"));
    printf("Index dari Shotgun: %d\n", idxMap(M, "Shotgun"));
    printf("Index dari RPG: %d\n\n", idxMap(M, "RPG"));

    printf("5. Tes idxMaxValueMap:\n");
    printf("Index dengan nilai tertinggi: %d\n", idxMaxValueMap(M));
    printf("Item termahal: %s dengan harga %d\n\n", 
           M.Elements[idxMaxValueMap(M)].Key, 
           M.Elements[idxMaxValueMap(M)].Value);

    printf("6. Tes DeleteMap:\n");
    printf("Menghapus AK47...\n");
    DeleteMap(&M, "AK47");
    printMap(M);

    printf("7. Tes Insert sampai penuh:\n");
    for(int i = 0; i < MaxEl; i++) {
        char key[10];
        sprintf(key, "Item%d", i);
        InsertMap(&M, key, i * 1000);
    }
    printMap(M);

    return 0;
}