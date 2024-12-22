#include <stdio.h>
#include "../master_header_adt.h"

void printkata(Word word) {
    for (int i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

int main() {
    // Reset global state at start
    RESETWORD();

    // Test stringtoint
    printf("1. Test stringtoint:\n");
    char str_num[] = "12345";
    int result;
    stringtoint(str_num, &result);
    printf("String \"%s\" ke integer: %d\n\n", str_num, result);

    // Test strlength
    printf("2. Test strlength:\n");
    char test_str[] = "Hello World";
    printf("Panjang string \"%s\": %d\n\n", test_str, strlength(test_str));

    // Test isNumber
    printf("3. Test isNumber:\n");
    Word num_word, text_word;
    num_word.Length = 3;
    num_word.TabWord[0] = '1';
    num_word.TabWord[1] = '2';
    num_word.TabWord[2] = '3';
    
    text_word.Length = 4;
    text_word.TabWord[0] = 't';
    text_word.TabWord[1] = 'e';
    text_word.TabWord[2] = 's';
    text_word.TabWord[3] = 't';
    
    printf("\"123\" adalah angka? %s\n", isNumber(num_word) ? "Ya" : "Tidak");
    printf("\"test\" adalah angka? %s\n\n", isNumber(text_word) ? "Ya" : "Tidak");

    // Test angka
    printf("4. Test angka:\n");
    char num_str[] = "12345";
    char alpha_str[] = "abc123";
    printf("\"%s\" hanya angka? %s\n", num_str, angka(num_str) ? "Ya" : "Tidak");
    printf("\"%s\" hanya angka? %s\n\n", alpha_str, angka(alpha_str) ? "Ya" : "Tidak");

    // Test strcopy
    printf("5. Test strcopy:\n");
    char src[] = "Hello";
    char dst[100];
    strcopy(src, dst);
    printf("Source: %s\n", src);
    printf("Destination: %s\n\n", dst);

    // Test wordToInt
    printf("6. Test wordToInt:\n");
    printf("Word \"123\" ke integer: %d\n\n", wordToInt(num_word));

    // Reset global state before exit
    RESETWORD();
    printf("=== Test Selesai ===\n");
    return 0;
}