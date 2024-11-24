#include "work.h"
#include <stdio.h>

int main() {
    JobList jobList;
    initializeJobs(&jobList);
    
    // Tampilkan saldo awal
    
    displayJobs(jobList);

    printf("\nMasukkan pekerjaan yang dipilih: ");
    
    // Menggunakan mesin kata untuk membaca input
    STARTWORD2(); // note startwork() dan startwork2 berbeda
    
    Word inputJob = currentWord;
    
    // Mengatur ulang currentWord setelah membaca input
    for (int i = 0; i < currentWord.Length; i++) {
        currentWord.TabWord[i] = '\0';
    }
    currentWord.Length = 0;

    Job* selectedJob = findJob(&jobList, inputJob);
    
    if (selectedJob != NULL) {
        doWork(selectedJob);
    } else {
        printf("Pekerjaan tidak ditemukan!\n");
    }
     
    return 0;
}