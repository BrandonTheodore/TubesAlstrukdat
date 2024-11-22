#include "work.h"

char katakecil(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

void initializeJobs(JobList *jobList) {

    Word job1 = {"Evil Lab Assistant", 17};
    jobList->jobs[0].name = job1;
    jobList->jobs[0].income = 100;
    jobList->jobs[0].duration = 14;
    
    Word job2 = {"OWCA Hiring Manager", 17};
    jobList->jobs[1].name = job2;
    jobList->jobs[1].income = 4200;
    jobList->jobs[1].duration = 21;

    Word job3 = {"Cikapundunginator Caretaker", 25};
    jobList->jobs[2].name = job3;
    jobList->jobs[2].income = 7000;
    jobList->jobs[2].duration = 30;

    Word job4 = {"Mewing Specialist", 16};
    jobList->jobs[3].name = job4;
    jobList->jobs[3].income = 10000;
    jobList->jobs[3].duration = 22;

    Word job5 = {"Inator Connoisseur", 18};
    jobList->jobs[4].name = job5;
    jobList->jobs[4].income = 997;
    jobList->jobs[4].duration = 15;

    jobList->count = 5;
}

boolean isWordSimilar(Word word1, Word word2) {
    if (word1.Length != word2.Length) {
        return false;
    }
    
    for (int i = 0; i < word1.Length; i++) {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

Job* findJob(JobList *jobList, Word jobName) {
    for (int i = 0; i < jobList->count; i++) {
        if (isWordEqual(jobList->jobs[i].name, jobName)) {
            return &jobList->jobs[i];
        }
    }
    printf("Pekerjaan tidak ditemukan! Pastikan nama pekerjaan sesuai dengan yang tertera di daftar.\n");
    return NULL;
}

void wordToString(Word word, char* str) {
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
}

boolean isWordEqual(Word a, Word b) {
    if (a.Length != b.Length) {
        return false;
    }
    
    for (int i = 0; i < a.Length; i++) {
        if (katakecil(a.TabWord[i]) != katakecil(b.TabWord[i])) {
            return false;
        }
    }
    return true;
}


void displayJobs(JobList jobList) {
    printf("Daftar pekerjaan:\n");
    char jobName[50];
    for (int i = 0; i < jobList.count; i++) {
        wordToString(jobList.jobs[i].name, jobName);
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", 
               i + 1, 
               jobName,
               jobList.jobs[i].income, 
               jobList.jobs[i].duration);
    }
    printf("\nCatatan: Masukkan nama pekerjaan persis seperti yang tertulis di atas\n");
}

void doWork(Job *selectedJob) {
    char jobName[50];
    wordToString(selectedJob->name, jobName);
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", jobName);
    
    clock_t start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < selectedJob->duration) {
    }
    
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", 
           selectedJob->income);
    
}
