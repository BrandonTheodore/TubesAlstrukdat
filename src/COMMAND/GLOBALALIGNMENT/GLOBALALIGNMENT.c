#include "globalAlignment.h"

void needleman_wunsch(char *seq1, char *seq2, int len1, int len2, int *final_score, char *aligned_seq1, char *aligned_seq2) {
    int i, j;
    int score_matrix[len1 + 1][len2 + 1];
    int traceback_matrix[len1 + 1][len2 + 1];

    for (i = 0; i <= len1; i++) {
        score_matrix[i][0] = i * GAP;
        traceback_matrix[i][0] = 1;
    }
    for (j = 0; j <= len2; j++) {
        score_matrix[0][j] = j * GAP;
        traceback_matrix[0][j] = 2; 
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int match_score = score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? MATCH : MISMATCH);
            int delete_score = score_matrix[i - 1][j] + GAP;
            int insert_score = score_matrix[i][j - 1] + GAP;

            if (match_score >= delete_score && match_score >= insert_score) {
                score_matrix[i][j] = match_score;
                traceback_matrix[i][j] = 0; 
            } else if (delete_score >= match_score && delete_score >= insert_score) {
                score_matrix[i][j] = delete_score;
                traceback_matrix[i][j] = 1; 
            } else {
                score_matrix[i][j] = insert_score;
                traceback_matrix[i][j] = 2; 
            }
        }
    }

    int aligned_len = 0;
    i = len1;
    j = len2;
    while (i > 0 || j > 0) {
        if (traceback_matrix[i][j] == 0) { 
            aligned_seq1[aligned_len] = seq1[i - 1];
            aligned_seq2[aligned_len] = seq2[j - 1];
            i--;
            j--;
        } else if (traceback_matrix[i][j] == 1) { 
            aligned_seq1[aligned_len] = seq1[i - 1];
            aligned_seq2[aligned_len] = '-';
            i--;
        } else { // Left
            aligned_seq1[aligned_len] = '-';
            aligned_seq2[aligned_len] = seq2[j - 1];
            j--;
        }
        aligned_len++;
    }

    for (i = 0; i < aligned_len / 2; i++) {
        char temp = aligned_seq1[i];
        aligned_seq1[i] = aligned_seq1[aligned_len - i - 1];
        aligned_seq1[aligned_len - i - 1] = temp;

        temp = aligned_seq2[i];
        aligned_seq2[i] = aligned_seq2[aligned_len - i - 1];
        aligned_seq2[aligned_len - i - 1] = temp;
    }
    aligned_seq1[aligned_len] = '\0';
    aligned_seq2[aligned_len] = '\0';

    *final_score = score_matrix[len1][len2];
}

void check_leakage() {
    char seq1[51], seq2[51];
    int len1, len2;

    printf("Masukkan sekuens referensi: ");
    STARTWORD2();
    for (int i = 0; i < currentWord.Length; i++) {
        seq1[i] = currentWord.TabWord[i];
    }
    len1 = currentWord.Length;
    seq1[len1] = '\0';

    printf("Masukkan sekuens query: ");
    STARTWORD2();
    for (int i = 0; i < currentWord.Length; i++) {
        seq2[i] = currentWord.TabWord[i];
    }
    len2 = currentWord.Length;
    seq2[len2] = '\0';

    int final_score;
    char aligned_seq1[101], aligned_seq2[101];
    needleman_wunsch(seq1, seq2, len1, len2, &final_score, aligned_seq1, aligned_seq2);

    int max_length = len1 > len2 ? len1 : len2;
    double threshold = 0.8 * max_length;

    printf("Skor: %d\n", final_score);
    printf("Sekuens yang telah disejajarkan:\n");
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);

    if (final_score > threshold) {
        printf("\nNawh! Ada kebocoran...\n");
    } else {
        printf("\nWoah! Tidak ada kebocoran\n");
    }
}