#include "tebakangka.h"

void playGuessingGame() {
    int currentSaldo = getCurrentSaldo(1); // mengambil saldo dari array untuk pengguna id 1 (sesuiakan dengan fungsi di savenya)
    if (currentSaldo < TA_COST) {
        printf("Maaf, saldo Anda tidak cukup untuk bermain. Biaya permainan: %d rupiah\n", TA_COST);
        return;
    }
    
    // Kurangi saldo untuk biaya bermain
    updateSaldoInFile(1, -TA_COST);// sesuaikan dengan fungsi di savenya
    printf("\n----------------------------------Biaya permainan %d rupiah telah dipotong dari saldo Anda--------------------------------------\n",TA_COST);
    
    //menghasilkan angka random
    srand(time(NULL));
    int targetNumber = rand() % 100 + 1; //membatasi agar range nilainya 1-100

    int guess, attempts = 0;
    int reward = REWARD_TA;

    printf("\n                                 |*********!Selamat datang di permainan Tebak Angka!*********|\n");
    printf("                                 |********!Anda memiliki %d kesempatan untuk menebak!********|\n", MAX_ATTEMPTS_T);
    printf("                                 |Hadiah awal: %d rupiah (berkurang %d setiap tebakan salah)|\n\n",REWARD_TA, R_PENGURANGAN);

    while (attempts < MAX_ATTEMPTS_T) {
        printf("Kesempatan tersisa: %d\n", MAX_ATTEMPTS_T - attempts);
        printf("Hadiah saat ini: %d\n", reward);
        printf("Tebak angka (1-100): ");
        
        // Baca tebakan menggunakan mesin kata
        STARTWORD2();
        guess = wordToInt(currentWord);
        
        attempts++;

        if (guess == targetNumber) {
            printf("\n---------------------------------!Selamat! Tebakanmu benar!--------------------------------------\n");
            printf("+%d rupiah telah ditambahkan ke akun anda.\n", reward);
            updateSaldoInFile(1, reward); //sesuaikan dengan fungsi savenya
            printf("Saldo Anda sekarang: %d rupiah\n", getCurrentSaldo(1)); // sesuaikan dengan fungsi di savenya
            return;
        } else if (guess < targetNumber) {
            printf("\n!Tebakanmu lebih kecil!\n\n");
        } else {
            printf("\n!Tebakanmu lebih besar!\n\n");
        }

        reward -= R_PENGURANGAN;
        if (reward < 0) reward = 0;
    }

    printf("\nMaaf, kesempatan anda habis. Angka yang benar adalah %d.\n", targetNumber);
    printf("Saldo Anda sekarang: %d rupiah\n", getCurrentSaldo(1));// sesuaikan dengan fungsi di save
}
