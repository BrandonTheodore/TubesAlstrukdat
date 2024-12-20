#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreCRLF()
{
    /* Mengabaikan satu atau beberapa '\n'
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ '\n' atau currentChar = MARK */
    while (currentChar == '\n')
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

boolean isEqual(char x[100], char y[100]){
    boolean cek = true;
    if(len(x) != len(y)){
        cek = false;
        return cek;
    } else {
        for(int i = 0; x[i] != '\0'; i++){
            if(x[i] != y[i]){
                cek = false;
            }
        }
        return cek;
    }
}

void STARTWORD2() {
    RESETWORD();
    START(); 
    IgnoreBlanks();  
    
    currentWord.Length = 0;
    
    while (currentChar != MARK && currentChar != '\n') {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();  
    }
    
    endWord = (currentChar == MARK);
}

int len(char x[100]){
    int i = 0;
    while(x[i] != '\0'){
        i++;
    }
    return i;
}

int wordToInt(Word word) {
    int result = 0;
    for (int i = 0; i < word.Length; i++) {
        if (word.TabWord[i] >= '0' && word.TabWord[i] <= '9') {
            result = result * 10 + (word.TabWord[i] - '0');
        }
    }
    return result;
}

void strcopy(char src[100], char dst[100]){
    int i = 0;
    while(src[i] != '\0'){
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void RESETWORD() {
    currentWord.Length = 0;
    for(int i = 0; i < MAX_LEN; i++) {
        currentWord.TabWord[i] = '\0';
    }
}

boolean isNumber(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') {
            return false;
        }
    }
    return true;
}

void stringtoint(char *str, int *result) {
    *result = 0;
    int i = 0;
    while (str[i] != '\0') {
        *result = (*result * 10) + (str[i] - '0');
        i++;
    }
}

int strlength(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void baca_line() {
    IgnoreCRLF();
    int i = 0;
    while(currentChar != '\n'){
        currentWord.TabWord[i] = currentChar;
        adv_baris();
        i++;
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;
}

void ADVWORD2() {
    IgnoreBlanks();
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();  
    }
    endWord = (currentChar == MARK);
}



