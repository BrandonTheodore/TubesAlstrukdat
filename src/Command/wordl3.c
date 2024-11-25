#include "wordl3.h"
User user;
boolean isWordEqual3(Word word1, Word word2) {
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

boolean isValidWord(Word guess) {
    // Cek panjang kata
    if (guess.Length != 5) {
        return false;
    }

    // Cek apakah semua karakter adalah huruf besar
    for (int i = 0; i < guess.Length; i++) {
        if (guess.TabWord[i] < 'A' || guess.TabWord[i] > 'Z') {
            return false;
        }
    }

    return true;
}

void readGuess(Word *guess) {
  STARTWORD2();
  *guess = currentWord;

    for (int i = 0; i < currentWord.Length; i++) {
        currentWord.TabWord[i] = '\0';
    }
    currentWord.Length = 0;
}

void compareGuess(Word guess, Word secretWord, Word *result) {
  result->Length = 0;
  for (int i = 0; i < guess.Length; i++) {
      char guessChar = guess.TabWord[i];
      boolean found = false;
      boolean correctPosition = false;

      if (guessChar == secretWord.TabWord[i]) {
          correctPosition = true;
      } else {
          for (int j = 0; j < secretWord.Length; j++) {
              if (guessChar == secretWord.TabWord[j]) {
                  found = true;
                  break;
              }
          }
      }

      if (correctPosition) {
          result->TabWord[result->Length++] = guessChar;
      } else if (found) {
          result->TabWord[result->Length++] = guessChar;
          result->TabWord[result->Length++] = '*';
      } else {
          result->TabWord[result->Length++] = guessChar;
          result->TabWord[result->Length++] = '%';
      }
  }
}

void displayPreviousGuesses(Word results[], int attempts) {
  printf("Hasil:\n");
  for (int i = 0; i < attempts; i++) {
      for (int j = 0; j < results[i].Length; j++) {
          printf("%c ", results[i].TabWord[j]);
      }
      printf("\n");
  }
  for (int i = attempts; i < MAX_ATTEMPTS_W; i++) {
      printf("_ _ _ _ _\n");
  }
}

void playWordle() { 
    srand(time(NULL));

    // Pilih kata rahasia secara acak dari daftar kata yang sudah ditentukan
    const char* secretWordOptions[] = {
        "ADIEU", "OMBRE", "PLUCK", "SERIN", "TRULY", 
        "LUCKY", "SLICK", "LEAKY", "BUILD", "APPLE"
    };
    int numSecretWords = 10;
    
    int randomIndex = rand() % numSecretWords;
    Word secretWord;
    secretWord.Length = 5;
    for (int i = 0; i < 5; i++) {
        secretWord.TabWord[i] = secretWordOptions[randomIndex][i];
    }

    Word results[MAX_ATTEMPTS_W];
    int attempts = 0;
    boolean win = false;

    printf("\nWELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n\n");
    for (int i = 0; i < MAX_ATTEMPTS_W; i++) {
        printf("_ _ _ _ _\n");
    }
    printf("\n");

    while (attempts < MAX_ATTEMPTS_W && !win) {
        Word guess;
        printf("Masukan kata tebakan Anda: ");
        readGuess(&guess);

        // Konversi kata ke huruf besar
        for (int i = 0; i < guess.Length; i++) {
            if (guess.TabWord[i] >= 'a' && guess.TabWord[i] <= 'z') {
                guess.TabWord[i] = guess.TabWord[i] - 'a' + 'A';
            }
        }

        if (!isValidWord(guess)) {
            printf("Kata tidak valid! Harus terdiri dari 5 huruf.\n\n");
            continue;
        }

        Word result;
        compareGuess(guess, secretWord, &result);
        results[attempts] = result;
        attempts++;

        displayPreviousGuesses(results, attempts);
        printf("\n");

        if (isWordEqual3(guess, secretWord)) {
            win = true;
            printf("Selamat, Anda menang!\n");
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            user.money += 1500;
        }
    }

    if (!win) {
        printf("Boo! Anda kalah.\n");
        printf("Kata yang benar adalah: ");
        for (int i = 0; i < secretWord.Length; i++) {
            printf("%c", secretWord.TabWord[i]);
        }
        printf("\n");
    }
}