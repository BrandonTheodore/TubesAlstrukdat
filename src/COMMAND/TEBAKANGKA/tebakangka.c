#include "tebakangka.h"
User user;
int user_id;
void playGuessingGame() {
    //menghasilkan angka random
    srand(time(NULL));
    int targetNumber = rand() % 100 + 1; //membatasi agar range nilainya 1-100
    int guess, attempts = 0;
    int reward = REWARD_TA;
    boolean validInput;

    printf("\n                                 |*********!Selamat datang di permainan Tebak Angka!*********|\n");
    printf("                                 |********!Anda memiliki %d kesempatan untuk menebak!********|\n", MAX_ATTEMPTS_T);
    printf("                                 |Hadiah awal: %d rupiah (berkurang %d setiap tebakan salah)|\n\n", REWARD_TA, R_PENGURANGAN);

    while (attempts < MAX_ATTEMPTS_T) {
        printf("Kesempatan tersisa: %d\n", MAX_ATTEMPTS_T - attempts);
        printf("Hadiah saat ini: %d\n", reward);
        
        do {
            validInput = true;
            printf("Tebak angka (1-100): ");
            STARTWORD2();
            guess = wordToInt(currentWord);

            for (int i = 0; i < currentWord.Length; i++) {
                currentWord.TabWord[i] = '\0';
            }
            currentWord.Length = 0;

            if (guess < 1 || guess > 100) {
                printf("\n!Angka harus berada pada rentang 1-100!\n");
                validInput = false;
                continue;  
            }
        } while (!validInput);

        if (guess == targetNumber) {
            printf("\n---------------------------------!Selamat! Tebakanmu benar!--------------------------------------\n");
            printf("+%d rupiah telah ditambahkan ke akun anda.\n", reward);
            user.money += reward;
            L.A[user_id].money += reward;
            return;
        } else if (guess < targetNumber) {
            printf("\n!Tebakanmu lebih kecil!\n\n");
        } else {
            printf("\n!Tebakanmu lebih besar!\n\n");
        }

        reward -= R_PENGURANGAN;
        if (reward < 0) reward = 0;
        attempts++;
    }

    printf("\nMaaf, kesempatan anda habis. Angka yang benar adalah %d.\n", targetNumber);
}
