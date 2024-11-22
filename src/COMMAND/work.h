#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/list.h"

typedef struct {
    Word name;
    int income;
    int duration;
} Job;

typedef struct {
    Job jobs[5];
    int count;
} JobList;

//variabel global saldo untuk work
extern int global_Saldo_work;

// Inisialisasi daftar pekerjaan
void initializeJobs(JobList *jobList);

// penyocokan 2 kata
boolean isWordSimilar(Word a, Word b) ;

// Menampilkan daftar pekerjaan
void displayJobs(JobList jobList);

// Mencari pekerjaan berdasarkan nama
Job* findJob(JobList *jobList, Word jobName);

// Melakukan pekerjaan
void doWork(Job *selectedJob);

// Membandingkan 2 kata
boolean isWordEqual(Word a, Word b);

// Mengkonversi Word ke string untuk ditampilakn
void wordToString(Word word, char* str);

#endif

