#include "quantum.h"

void playQuantumWordle() {
    srand(time(NULL));

    const char* secretWordOptions[] = {
        "ADIEU", "OMBRE", "PLUCK", "SERIN", "TRULY", 
        "LUCKY", "SLICK", "LEAKY", "BUILD", "APPLE"
    };
    int numSecretWords = 10;
    
    Word secretWords[QUANTUM_WORDS];
    for (int i = 0; i < QUANTUM_WORDS; i++) {
        int randomIndex;
        boolean unique;
        do {
            unique = true;
            randomIndex = rand() % numSecretWords;
            
            for (int j = 0; j < i; j++) {
                if (secretWords[j].TabWord[0] == secretWordOptions[randomIndex][0] &&
                    secretWords[j].Length == 5) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        
        secretWords[i].Length = 5;
        for (int j = 0; j < 5; j++) {
            secretWords[i].TabWord[j] = secretWordOptions[randomIndex][j];
        }
    }

    Word results[MAX_QUANTUM_ATTEMPTS][QUANTUM_WORDS];
    int attempts = 0;
    boolean wins[QUANTUM_WORDS] = {false};
    boolean allWins = false;

    printf("\nWELCOME TO QUANTUM W0RDL3, YOU HAVE 9 CHANCES TO ANSWER 4 DIFFERENT WORDS!\n\n");
    
    for (int i = 0; i < MAX_QUANTUM_ATTEMPTS; i++) {
        printf("_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _\n");
    }
    printf("\n");

    while (attempts < MAX_QUANTUM_ATTEMPTS && !allWins) {
        Word guesses[QUANTUM_WORDS];
        boolean validInput = true;
        
        do {
            validInput = true;
    
            for (int i = 0; i < QUANTUM_WORDS; i++) {
                printf("Masukkan kata ke-%d: ", i+1);
                readGuess(&guesses[i]);
        
            for (int j = 0; j < guesses[i].Length; j++) {
                if (guesses[i].TabWord[j] >= 'a' && guesses[i].TabWord[j] <= 'z') {
                    guesses[i].TabWord[j] = guesses[i].TabWord[j] - 'a' + 'A';
                }
            }

            if (!isValidWord(guesses[i])) {
                printf("Kata ke-%d tidak valid! Harus terdiri dari 5 huruf.\n", i+1);
                validInput = false;
                break;
            }
        }
    } while (!validInput);


        for (int i = 0; i < QUANTUM_WORDS; i++) {
            if (!wins[i]) {
                Word result;
                compareGuess(guesses[i], secretWords[i], &result);
                results[attempts][i] = result;

                if (isWordEqual(guesses[i], secretWords[i])) {
                    wins[i] = true;
                }
            } else {
                results[attempts][i] = results[attempts-1][i];
            }
        }

        attempts++;

        printf("\nHasil:\n");
        for (int i = 0; i < attempts; i++) {
            for (int j = 0; j < QUANTUM_WORDS; j++) {
                for (int k = 0; k < results[i][j].Length; k++) {
                    printf("%c ", results[i][j].TabWord[k]);
                }
                printf("  ");
            }
            printf("\n");
        }

        for (int i = attempts; i < MAX_QUANTUM_ATTEMPTS; i++) {
            printf("_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _\n");
        }
        printf("\n");

        allWins = true;
        for (int i = 0; i < QUANTUM_WORDS; i++) {
            if (!wins[i]) {
                allWins = false;
                break;
            }
        }
    }

    if (allWins) {
        printf("Selamat, Anda menang! Anda berhasil menebak semua kata!\n");
        printf("+3000 rupiah telah ditambahkan ke akun Anda.\n");
        global_Saldo += 3000;
    } else {
        printf("Boo! Anda kalah.\n");
        printf("Kata yang benar adalah:\n");
        for (int i = 0; i < QUANTUM_WORDS; i++) {
            for (int j = 0; j < secretWords[i].Length; j++) {
                printf("%c", secretWords[i].TabWord[j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}
