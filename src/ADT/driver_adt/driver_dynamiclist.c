#include <stdio.h>
#include <stdlib.h>
#include "../master_header_adt.h"

void printarr(ArrayDin array) {
    printf("isi array: [");
    for (int i = 0; i < array.Neff; i++) {
        printf("(%s, %d)", array.A[i].name, array.A[i].price);
        if (i < array.Neff - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Length: %d, Capacity: %d\n", array.Neff, array.Capacity);
}

int main() {
    ArrayDin arr = MakeArrayDin();
    
    printf("1. Tes MakeArrayDin dan IsEmptyDin:\n");
    printf("1. Testing MakeArrayDin and IsEmptyDin:\n");

    if (IsEmptyDin(arr)) {
        printf("array kosong\n");
    } 
    else {
        printf("array tidak kosong\n");
    }

    
    printf("\n2. Tes InsertLastDin:\n");
    InsertLastDin(&arr, "jeruk", 100);
    InsertLastDin(&arr, "apel", 150);
    InsertLastDin(&arr, "mangga", 200);
    printarr(arr);
    
    printf("\n3. Tes InsertFirstDin:\n");
    InsertFirstDin(&arr, "tess", 180);
    printarr(arr);
    
    printf("\n4. Tes InsertAtDin:\n");
    InsertAtDin(&arr, "hai", 120, 2);
    printarr(arr);
    
    printf("\n5. Tes SearchArrayDin:\n");
    int index = SearchArrayDin(arr, "mangga");
    printf("indeks dari mangga: %d\n", index);
    
    printf("\n6. Tes DeleteLastDin:\n");
    DeleteLastDin(&arr);
    printarr(arr);
    
    printf("\n7. Tes DeleteFirstDin:\n");
    DeleteFirstDin(&arr);
    printarr(arr);
    
    printf("\n8. Tes DeleteAtDin:\n");
    DeleteAtDin(&arr, 1);
    printarr(arr);
    
    printf("\n9. Tes LengthDin dan GetCapacityDin:\n");
    printf("Length: %d, Capacity: %d\n", LengthDin(arr), GetCapacityDin(arr));
    
    printf("\n10. Tes DeallocateArrayDin:\n");
    DeallocateArrayDin(&arr);
    printf("Array berhasil terdealokasi\n");
    
    return 0;
}
