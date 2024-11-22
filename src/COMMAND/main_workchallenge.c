#include <stdio.h>
#include "saldo.h"
#include "work_challenge.h"

int main() {
    // Tampilkan saldo awal
    printf("\nSaldo Anda: %d rupiah\n\n", getCurrentSaldo(1));
    
    // Tampilkan dan jalankan challenge
    selectChallenge();
    
    return 0;
}
