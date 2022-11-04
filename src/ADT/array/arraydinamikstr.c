/* File : arraydinamikstr.c
 * File C yang berisi implementasi fungsi dari file header ADT Array
 * versi string, arraydinamikstr.h
*/

#include "arraydinamik.h"
#include <stdlib.h>
#include <stdio.h>

/* KONSTRUKTOR 
 * I.S.	sembarang;
 * F.S.	Terbentuk DynArray kosong yang berukuran StartSize;
*/
DynArray CreateDynArray() {
	DynArray array;
	// Alokasi elemen array secara dinamik menggunakan malloc
	array.Ar = (ElType*) malloc (StartSize * sizeof(ElType));
	array.Kapasitas = StartSize; // Kapasitas array diset sebesar StartSize
	array.Neff = 0; // Karena masih kosong, elemen efektif array bernilai 0
	return array;
}

/* DESTRUKTOR
 * I.S.	DynArray terdefinisi;
 * F.S.	DynArray->arrdin terdealokasikan;
*/
void DealokasiDynArray(DynArray *array) {
	free(array->Ar);
}

/* PRIMITIF LAINNYA */
/* Fungsi IsEmpty
 * Fungsi untuk mengetahui apakah array input kosong atau tidak.
 * Prekondisi : array sudah terdefinisi
*/
boolean IsEmpty(DynArray array) {
	return (array.Neff == 0);
}

/* Fungsi Length
 * Fungsi untuk mengetahui banyaknya elemen efektif dalam sebuah array, bernilai 0 jika kosong.
 * Prekondisi : array sudah terdefinisi
*/
int Length(DynArray array) {
	return (array.Neff);
}

/* Fungsi Get
 * Fungsi untuk mengembalikan nilai elemen array yang ke-i (logical index).
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
ElType Get(DynArray array, IdxType i) {
	return (array.Ar[i]);
}

/* Fungsi GetCapacity
 * Fungsi untuk mengembalikan kapasitas dari array yang tersedia.
 * Prekondisi : array sudah terdefinisi
*/
int GetCapacity(DynArray array) {
	return (array.Kapasitas);
}

/* Fungsi InsertIn
 * Fungsi untuk memasukkan elemen baru pada indeks ke-i
 * Prekondisi : array tidak penuh, dan i berada di [0...Length(array))
*/
void InsertIn(DynArray *array, ElType elmt, IdxType i) {
	int index;
	index = Length(*array);
	
	if (Length(*array) == GetCapacity(*array)) { // Array sudah penuh
	// Array perlu dialokasikan kembali agar lebih besar
		ElType *temparr = (ElType*) malloc (2 * StartSize * sizeof(ElType));
		int j;
		for (j = 0; j < Length(*array); j++) {
			temparr[j] = Get(*array, j);
		}
		array->Ar = temparr;
		array->Kapasitas = 2 * StartSize;
	}
	// Array sudah dialokasikan kembali dengan ukuran 2 kali semula
	
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
void InsertFirst(DynArray *array, ElType elmt) {
	InsertIn(array, elmt, 0);
}

/* Fungsi InsertLast
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertLast(DynArray *array, ElType elmt) {
	InsertIn(array, elmt, Length(*array));
}

/* Fungsi DeleteIn
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
void DeleteIn(DynArray *array, IdxType i) {
	while (i < Length(*array)) {
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
void DeleteFirst(DynArray *array) {
	DeleteIn(array, 0);
}

/* Fungsi DeleteLast
 * Fungsi untuk menghapus elemen di akhir array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteLast(DynArray *array) {
	DeleteIn(array, Length(*array) - 1);
}

/* Fungsi ShowDynArray
 * Fungsi untuk menampilkan array DynArray ke layar
 * Tampilan array memiliki format : [elemen-1, elemen-2, ..., elemen-terakhir]
 * Apabila array kosong, cukup menampilkan [] saja.
 * Tampilan array diakhiri dengan baris baru (newline)
 * Prekondisi : array sudah terdefinisi
*/
void ShowDynArray(DynArray array) {
	if (IsEmpty(array)) {
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
void ReverseDynArray(DynArray *array) {
	int i;
	for (i = 0; i < Length(*array)/2; ++i) {
		ElType temp = array->Ar[i];
		array->Ar[i] = array->Ar[Length(*array) - i - 1];
		array->Ar[Length(*array) - i - 1] = temp;
	}
}

/* Fungsi CopyDynArray
 * Fungsi untuk menyalin suatu DynArray
 * Prekondisi : array sudah terdefinisi
*/
DynArray CopyDynArray(DynArray array) {
	DynArray newarr = CreateDynArray();
	int k;
	for (k = 0; k < array.Neff; k++) {
		InsertLast(&newarr, array.Ar[k]);
	}
	return newarr;
}

/* Fungsi FindDynArray
 * Fungsi untuk melakukan search pada suatu DynArray
 * Indeks pertama yang ditemukan akan dikembalikan,
 * apabila tidak ditemukan maka akan mengembalikan -1.
 * Prekondisi : array sudah terdefinisi
*/
IdxType FindDynArray(DynArray array, ElType elmt) {
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
