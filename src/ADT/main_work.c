
#include "work.h"

int main() {
    JobList jobList;
    initializeJobs(&jobList);
    
    // Tampilkan saldo awal
    int currentSaldo = getCurrentSaldo(1);  // userId = 1
    printf("Saldo awal Anda: %d rupiah\n", currentSaldo);
    
    displayJobs(jobList);

    printf("\nMasukkan pekerjaan yang dipilih: ");
    
    // Menggunakan mesin kata untuk membaca input
    STARTWORD2();// note startwork () dan startwork2 berbeda
    Word inputJob = currentWord;

    Job* selectedJob = findJob(&jobList, inputJob);
    
    if (selectedJob != NULL) {
        doWork(selectedJob);
        printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob->income);
        currentSaldo = getCurrentSaldo(1);
        printf("Saldo Anda sekarang: %d rupiah\n", currentSaldo);
    } else {
        printf("Pekerjaan tidak ditemukan!\n");
    }
     
    return 0;
}



