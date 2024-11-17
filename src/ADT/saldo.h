typedef struct {
    int userId;
    int saldo;
} SaldoData;

// mengupdate saldo 
void updateSaldoInFile(int userId, int additionalAmount);

//mengabil saldo pengguna
int getCurrentSaldo(int userId);


