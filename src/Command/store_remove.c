#include "store_remove.h"
#include <stdio.h>

void store_remove(List *storeInventory) {
    Word itemToRemove;
    boolean found = false;

    printf("Nama barang yang akan dihapus: ");
    STARTWORD(); // Membaca input nama barang
    itemToRemove = currentWord;

    for (IdxType i = FirstIdx(*storeInventory); i <= LastIdx(*storeInventory); i++) {
        if (isEqual(Get(*storeInventory, i).name, itemToRemove.TabWord)) {
            DeleteAt(storeInventory, i);
            printf("%s telah berhasil dihapus.\n", itemToRemove.TabWord);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", itemToRemove.TabWord);
    }
}
