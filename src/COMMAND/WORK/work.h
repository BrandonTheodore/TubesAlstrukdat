#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../master_header_command.h"
#include "../../ADT/master_header_adt.h"

typedef struct {
    Word name;
    int income;
    int duration;
} Job;

typedef struct {
    Job jobs[5];
    int count;
} JobList;

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

void main_work();

#endif

