#include "store_remove.h"
#include <stdio.h>

ArrayDin AD;

void STORE_REMOVE() {
    boolean found = false;

    printf("Nama barang yang akan dihapus: ");
    STARTWORD2();
    char command[50];
    int i = 0;
    while(currentWord.TabWord[i] != '\0'){
        command[i] = currentWord.TabWord[i];
        (&currentWord)->TabWord[i] = '\0';
        i++;
    }
    command[i] = '\0';
    (&currentWord)->TabWord[i] = '\0';

    for (int i = 0; i < AD.Neff ; i++) {
        if (isEqual(command, AD.A[i].name)){
            DeleteAtDin(&AD, i);
            printf("%s telah berhasil dihapus.\n", command);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", command);
    }
}
