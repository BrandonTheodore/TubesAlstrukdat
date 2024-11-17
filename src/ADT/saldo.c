#include "boolean.h"
#include "saldo.h"
#include "work.h"

void updateSaldoInFile(int userId, int additionalAmount) {
    FILE *file;
    SaldoData data;
    boolean found = false;
    
    file = fopen("data_saldo.txt", "rb");
    
    if (file == NULL) {
        file = fopen("data_saldo.txt", "wb");
        data.userId = userId;
        data.saldo = additionalAmount;
        fwrite(&data, sizeof(SaldoData), 1, file);
        fclose(file);
        return;
    }
    
    SaldoData allData[100];  
    int dataCount = 0;
    
    while (fread(&data, sizeof(SaldoData), 1, file) == 1) {
        if (data.userId == userId) {
            data.saldo += additionalAmount;
            found = true;
        }
        allData[dataCount++] = data;
    }
    fclose(file);
    
    if (!found) {
        data.userId = userId;
        data.saldo = additionalAmount;
        allData[dataCount++] = data;
    }
    
    file = fopen("data_saldo.txt", "wb");
    fwrite(allData, sizeof(SaldoData), dataCount, file);
    fclose(file);
}

int getCurrentSaldo(int userId) {
    FILE *file;
    SaldoData data;
    
    file = fopen("data_saldo.txt", "rb");
    if (file == NULL) {
        return 0;  
    }
    
    while (fread(&data, sizeof(SaldoData), 1, file) == 1) {
        if (data.userId == userId) {
            fclose(file);
            return data.saldo;
        }
    }
    
    fclose(file);
    return 0;  
}
