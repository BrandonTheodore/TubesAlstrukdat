#ifndef STORE_H
#define STORE_H

#define MAX_LEN 100
#define MAX_NAME_LENGTH 50
#define MAX_QUEUE_SIZE 10

// Definisi struktur Barang
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

// Definisi struktur User
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

// Definisi struktur Queue
