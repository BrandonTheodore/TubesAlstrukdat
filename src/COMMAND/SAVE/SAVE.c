#include <stdio.h>
#include <stdlib.h>
#include "SAVE.h"

FILE *file;
extern ArrayDin AD;
extern List userList;

void SAVE(char txt[50]) {
    char path[100] = "../save/";
    int a = 8;
    int b = 0;
    while(a < 100) {
        path[a] = txt[b];
        a++;
        b++;
    }
    path[a] = '\0';
    
    file = fopen(path, "w");
    
    // Save store items
    fprintf(file, "%d\n", AD.Neff);
    for(int i = 0; i < AD.Neff; i++) {
        fprintf(file, "%d %s\n", AD.A[i].price, AD.A[i].name);
    }
    
    // Save users
    fprintf(file, "%d\n", userList.Neff);
    for(int i = 0; i < userList.Neff; i++) {
        // Save user basic info
        fprintf(file, "\n%s %s %d %s %d\n", 
            userList.A[i].name,
            userList.A[i].password,
            userList.A[i].money,
            userList.A[i].nickname,
            userList.A[i].umur
        );
        
        // Save purchase history
        fprintf(file, "%d\n", userList.A[i].riwayat_pembelian.Top + 1);
        for(int j = 0; j < userList.A[i].riwayat_pembelian.Top+1; j++) {
            fprintf(file, "%s %d\n",
                userList.A[i].riwayat_pembelian.T[j].namaBarang,
                userList.A[i].riwayat_pembelian.T[j].totalHarga);
        }
        
        // Save wishlist
        int wishlistCount = NbElmtLinier(userList.A[i].wishlist);
        fprintf(file, "%d\n", wishlistCount);
        address_list P = First(userList.A[i].wishlist);
        while(P != NilList) {
            fprintf(file, "%s\n", Info(P));
            P = Next(P);
        }
    }
    
    fclose(file);
    printf("File berhasil disimpan!\n");
}