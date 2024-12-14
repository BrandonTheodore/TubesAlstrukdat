#include <stdio.h>
#include "../master_header_adt.h"

void printkata(Word word) {
    for (int i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

int main() {

    printf("Masukkan beberapa kata (akhiri dengan titik):\n");
    STARTWORD();

    printf("\nKata-kata yang terbaca:\n");
    while (!isEndWord()) {
        printf("- ");
        printkata(currentWord);
        printf(" panjang: %d\n", currentWord.Length);
        ADVWORD();
    }

    printf("\nTest isEqual :\n");
    char str1[] = "halo";
    char str2[] = "tes";
    char str3[] = "world";

    printf("\"halo\" dan \"tes\":\n");
    if (isEqual(str1, str2)) {
        printf("sama\n");
    } else {
        printf("beda\n");
    }

    printf("\n\"halo\" dan \"world\":\n");
    if (isEqual(str1, str3)) {
        printf("sama\n");
    } else {
        printf("beda\n");
    }


    printf("\nTest len :\n");
    printf("len(\"halo\"): %d\n", len(str1));

    printf("\n Test STARTWORD2 :\n");
    printf("\nMasukkan kalimat:\n");
    STARTWORD2();
    printf("kata yang terbaca: ");
    printkata(currentWord);
    printf("\n");

    printf("\nTest wordToInt :\n");
    Word numWord;
    numWord.Length = 3;
    numWord.TabWord[0] = '1';
    numWord.TabWord[1] = '2';
    numWord.TabWord[2] = '3';
    printf("wordToInt untuk \"123\": %d\n", wordToInt(numWord));

    return 0;
}
