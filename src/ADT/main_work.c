#include "work.h"
#include <stdio.h>

int main() {
    JobList jobList;
    initializeJobs(&jobList);
    printf("ppppp");
    
    // Tampilkan saldo awal
    printf("Saldo awal Anda:..... rupiah\n"); //... memanggil nilai saldo yang tersave
    
    displayJobs(jobList);

    printf("\nMasukkan pekerjaan yang dipilih: ");
    
    // Menggunakan mesin kata untuk membaca input
    STARTWORD2();// note startwork () dan startwork2 berbeda
    
    Word inputJob = currentWord;
    Job* selectedJob = findJob(&jobList, inputJob);
    
    if (selectedJob != NULL) {
        doWork(selectedJob);
    } else {
        printf("Pekerjaan tidak ditemukan!\n");
    }
     
    return 0;
}



