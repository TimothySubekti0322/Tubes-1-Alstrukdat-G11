/* File : arraystatis.c
 * File C yang berisi implementasi fungsi dari file header ADT Array, arraystatis.h
*/

#include "arraystatis.h"
#include <stdlib.h>
#include <stdio.h>

/* KONSTRUKTOR 
 * I.S.	sembarang;
 * F.S.	Terbentuk DynArray kosong yang berukuran StartSize;
*/
StatArray CreateStatArray() {
	StatArray array;
    // Karena masih kosong, elemen efektif array bernilai 0
	array.Neff = 0; 
	return array;
}

/* DESTRUKTOR
 * I.S.	DynArray terdefinisi;
 * F.S.	DynArray->arrdin terdealokasikan;
*/
void DealokasiStatArray(StatArray *array) {
	free(array->Ar);
}

/* PRIMITIF LAINNYA */
/* Fungsi IsEmpty
 * Fungsi untuk mengetahui apakah array input kosong atau tidak.
 * Prekondisi : array sudah terdefinisi
*/
boolean IsEmptyStat(StatArray array) {
	return (array.Neff == 0);
}

/* Fungsi Length
 * Fungsi untuk mengetahui banyaknya elemen efektif dalam sebuah array, bernilai 0 jika kosong.
 * Prekondisi : array sudah terdefinisi
*/
int LengthStat(StatArray array) {
	return (array.Neff);
}

/* Fungsi Get
 * Fungsi untuk mengembalikan nilai elemen array yang ke-i (logical index).
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
ElType GetStat(StatArray array, IdxType i) {
	return (array.Ar[i]);
}


/* Fungsi InsertIn
 * Fungsi untuk memasukkan elemen baru pada indeks ke-i
 * Prekondisi : array tidak penuh, dan i berada di [0...Length(array))
*/
void InsertStat(StatArray *array, ElType elmt, IdxType i) {
	int index;
	index = LengthStat(*array);
	
	while (index > i) {
		array->Ar[index] = array->Ar[index - 1];
		index--;
	}
	array->Ar[i] = elmt;
	array->Neff++;
}

/* Fungsi InsertFirst
 * Fungsi untuk memasukkan elemen baru di awal array
 * Prekondisi : array sudah terdefinisi
*/
void InsertFStat(StatArray *array, ElType elmt) {
	InsertStat(array, elmt, 0);
}

/* Fungsi InsertLast
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertLStat(StatArray *array, ElType elmt) {
	InsertStat(array, elmt, LengthStat(*array));
}

/* Fungsi DeleteIn
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
void DeleteStat(StatArray *array, IdxType i) {
	while (i < LengthStat(*array)) {
		array->Ar[i] = array->Ar[i + 1];
		i++;
	}
	// Array sudah selesai digeser, elemen efektif berkurang satu
	array->Neff--;
}

/* Fungsi DeleteFirst
 * Fungsi untuk menghapus elemen di awal array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteFStat(StatArray *array) {
	DeleteStat(array, 0);
}

/* Fungsi DeleteLast
 * Fungsi untuk menghapus elemen di akhir array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteLStat(StatArray *array) {
	DeleteStat(array, LengthStat(*array) - 1);
}

/* Fungsi ShowDynArray
 * Fungsi untuk menampilkan array DynArray ke layar
 * Tampilan array memiliki format : [elemen-1, elemen-2, ..., elemen-terakhir]
 * Apabila array kosong, cukup menampilkan [] saja.
 * Tampilan array diakhiri dengan baris baru (newline)
 * Prekondisi : array sudah terdefinisi
*/
void ShowStatArray(StatArray array) {
	if (IsEmptyStat(array)) {
		printf("[]\n");
	} else { // array tidak kosong
		printf("[");
		int l;
		for (l = 0; l < array.Neff; l++) {
			printf("%d", array.Ar[l]);
			if (l < array.Neff - 1) {
				printf(", ");
			}
		}
		printf("]\n");
	}
}

/* Fungsi ReverseDynArray
 * Fungsi untuk mengubah urutan array menjadi terbalik (reverse)
 * Prekondisi : array sudah terdefinisi
*/
void ReverseStatArray(StatArray *array) {
	int i;
	for (i = 0; i < LengthStat(*array)/2; ++i) {
		ElType temp = array->Ar[i];
		array->Ar[i] = array->Ar[LengthStat(*array) - i - 1];
		array->Ar[LengthStat(*array) - i - 1] = temp;
	}
}

/* Fungsi CopyDynArray
 * Fungsi untuk menyalin suatu DynArray
 * Prekondisi : array sudah terdefinisi
*/
StatArray CopyStatArray(StatArray array) {
	StatArray newarr = CreateStatArray();
	int k;
	for (k = 0; k < array.Neff; k++) {
		InsertLStat(&newarr, array.Ar[k]);
	}
	return newarr;
}

/* Fungsi FindDynArray
 * Fungsi untuk melakukan search pada suatu DynArray
 * Indeks pertama yang ditemukan akan dikembalikan,
 * apabila tidak ditemukan maka akan mengembalikan -1.
 * Prekondisi : array sudah terdefinisi
*/
IdxType FindStatArray(StatArray array, ElType elmt) {
	boolean found = false;
	int LocationIdx = -1;
	int i = 0;
	while (i < array.Neff && !found) {
		if (array.Ar[i] == elmt) {
			found = true;
			LocationIdx = i;
		}
		i++;
	}
	return LocationIdx;
}
int main(){}