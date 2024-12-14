#include <stdio.h>
#include "list.h"

List MakeList(){
    List L;
    for (int i = 0; i < MaxEl; i++){
		for(int j = 0; j < MaxEl; j++){
        	L.A[i].name[j] = Mark;
			L.A[i].password[j] = Mark;
		}
		L.A[i].money = 0;
    }
	(&L)->Neff = 0;
    return L;
}

/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return L.Neff == 0;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
// char Get(List L, int i){
//     return(L.A[i]);
// }
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
// void Set(List *L, int i, char v){
//     L->A[i] = v; 
// }
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    return L.Neff;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
int FirstIdx(List L){
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

int LastIdx(List L){
    return L.Neff - 1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, int i){
    return (i >= 0 && i < MaxEl);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, int i){
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, char X[MaxEl], int* idx){
	boolean cek = false;
    for(int i = 0; i <= LastIdx(L); i++){
		cek = true;
		for(int j = 0; L.A[i].name[j] != Mark; j++){
			if(L.A[i].name[j] != X[j]){
				cek = false;
			}
        }
		if(cek){
			*idx = i;
			return cek;
		}
    }
    return cek;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

// void InsertFirst(List *L, char X){
//     for(int i = Length(*L); i > 0; i--){
//         L->A[i] = L->A[i-1];
//     }
//     L->A[0] = X;
// }
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

// void InsertAt(List *L, char X, int i){
//     for(int j = Length(*L); j > i; j--){
//         L->A[j] = L->A[j-1];
//     }
//     L->A[i] = X;
// }
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, char X[MaxEl], char Y[MaxEl], int money){
	int i = 0;
	while(X[i] != '\0'){
		L->A[Length(*L)].name[i] = X[i];
		i++;
	}
	L->A[Length(*L)].name[i] = '\0';

	int j = 0;
	while(Y[j] != '\0'){
		L->A[Length(*L)].password[j] = Y[j];
		j++;
	}
	L->A[Length(*L)].password[j] = '\0';
	L->A[Length(*L)].money = money;
	L->Neff++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

// void DeleteFirst(List *L){
//     for(int i = 0; i < Length(*L); i++){
//         L->A[i] = L->A[i+1];
//     }
// }
// /* I.S. L terdefinisi, tidak kosong. */
// /* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

// void DeleteAt(List *L, int i){
//     for(int j = i; j < Length(*L); j++){
//         L->A[i] = L->A[i+1];
//     }
// }
// /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
// /* F.S. Elemen L pada indeks ke-i dihapus dari L. */

// void DeleteLast(List *L){
//     L->A[LastIdx(*L)] = Mark;
// }
// /* I.S. L terdefinisi, tidak kosong. */
// /* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

// List Concat(List L1, List L2){
//     List L3 = L1;
//     int j = 0;
//     for(int i = Length(L1); i <= (LastIdx(L1) + LastIdx(L2) + 1); i++ ){
//         L3.A[i] = L2.A[j];
//         j++;
//     }
//     return L3;
// }
