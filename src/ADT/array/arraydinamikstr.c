/* File : arraydinamikstr.c
 * File C yang berisi implementasi fungsi dari file header ADT Array
 * versi string, arraydinamikstr.h
*/

#include "arraydinamikstr.h"
#include <stdlib.h>
#include <stdio.h>

/* KONSTRUKTOR 
 * I.S.	sembarang;
 * F.S.	Terbentuk DynArray kosong yang berukuran StartSize;
*/
ArrayDyn CreateStrArrayDyn() {
	ArrayDyn array;
	// Alokasi elemen array secara dinamik menggunakan malloc
	array.Ar = (TypeEl*) malloc (StartSize * sizeof(TypeEl));
	array.Kapasitas = StartSize; // Kapasitas array diset sebesar StartSize
	array.Neff = 0; // Karena masih kosong, elemen efektif array bernilai 0
	return array;
}

/* DESTRUKTOR
 * I.S.	DynArray terdefinisi;
 * F.S.	DynArray->arrdin terdealokasikan;
*/
void DealokasiStrArrayDyn(ArrayDyn *array) {
	free(array->Ar);
}

/* PRIMITIF LAINNYA */
/* Fungsi IsEmpty
 * Fungsi untuk mengetahui apakah array input kosong atau tidak.
 * Prekondisi : array sudah terdefinisi
*/
boolean IsStrEmpty(ArrayDyn array) {
	return (array.Neff == 0);
}

/* Fungsi Length
 * Fungsi untuk mengetahui banyaknya elemen efektif dalam sebuah array, bernilai 0 jika kosong.
 * Prekondisi : array sudah terdefinisi
*/
int StrLength(ArrayDyn array) {
	return (array.Neff);
}

/* Fungsi Get
 * Fungsi untuk mengembalikan nilai elemen array yang ke-i (logical index).
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
TypeEl GetStr(ArrayDyn array, TypeIdx i) {
	return (array.Ar[i]);
}

/* Fungsi GetCapacity
 * Fungsi untuk mengembalikan kapasitas dari array yang tersedia.
 * Prekondisi : array sudah terdefinisi
*/
int GetStrCapacity(ArrayDyn array) {
	return (array.Kapasitas);
}

/* Fungsi InsertIn
 * Fungsi untuk memasukkan elemen baru pada indeks ke-i
 * Prekondisi : array tidak penuh, dan i berada di [0...Length(array))
*/
void InsertStrIn(ArrayDyn *array, TypeEl elmt, TypeIdx i) {
	int index;
	index = StrLength(*array);
	
	if (StrLength(*array) == GetStrCapacity(*array)) { // Array sudah penuh
	// Array perlu dialokasikan kembali agar lebih besar
		TypeEl *temparr = (TypeEl*) malloc (2 * StartSize * sizeof(TypeEl));
		int j;
		for (j = 0; j < StrLength(*array); j++) {
			temparr[j] = GetStr(*array, j);
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
void InsertStrFirst(ArrayDyn *array, TypeEl elmt) {
	InsertStrIn(array, elmt, 0);
}

/* Fungsi InsertLast
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertStrLast(ArrayDyn *array, TypeEl elmt) {
	InsertStrIn(array, elmt, StrLength(*array));
}

/* Fungsi DeleteIn
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
void DeleteStrIn(ArrayDyn *array, TypeIdx i) {
	while (i < StrLength(*array)) {
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
void DeleteStrFirst(ArrayDyn *array) {
	DeleteStrIn(array, 0);
}

/* Fungsi DeleteLast
 * Fungsi untuk menghapus elemen di akhir array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteStrLast(ArrayDyn *array) {
	DeleteStrIn(array, StrLength(*array) - 1);
}

/* Fungsi ShowDynArray
 * Fungsi untuk menampilkan array DynArray ke layar
 * Tampilan array memiliki format : [elemen-1, elemen-2, ..., elemen-terakhir]
 * Apabila array kosong, cukup menampilkan [] saja.
 * Tampilan array diakhiri dengan baris baru (newline)
 * Prekondisi : array sudah terdefinisi
*/
void ShowStrArrayDyn(ArrayDyn array) {
	if (IsStrEmpty(array)) {
		printf("[]\n");
	} else { // array tidak kosong
		printf("[");
		int l;
		for (l = 0; l < array.Neff; l++) {
			printf("%s", array.Ar[l]);
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
void ReverseStrArrayDyn(ArrayDyn *array) {
	int i;
	for (i = 0; i < StrLength(*array)/2; ++i) {
		TypeEl temp = array->Ar[i];
		array->Ar[i] = array->Ar[StrLength(*array) - i - 1];
		array->Ar[StrLength(*array) - i - 1] = temp;
	}
}

/* Fungsi CopyDynArray
 * Fungsi untuk menyalin suatu DynArray
 * Prekondisi : array sudah terdefinisi
*/
ArrayDyn CopyStrArrayDyn(ArrayDyn array) {
	ArrayDyn newarr = CreateStrArrayDyn();
	int k;
	for (k = 0; k < array.Neff; k++) {
		InsertStrLast(&newarr, array.Ar[k]);
	}
	return newarr;
}

/* Fungsi FindDynArray
 * Fungsi untuk melakukan search pada suatu DynArray
 * Indeks pertama yang ditemukan akan dikembalikan,
 * apabila tidak ditemukan maka akan mengembalikan -1.
 * Prekondisi : array sudah terdefinisi
*/
TypeIdx FindStrArrayDyn(ArrayDyn array, TypeEl elmt) {
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
