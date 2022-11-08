/* File : arraydinamikstr.h
 * File Header berisi definisi ADT Array yang menggunakan alokasi dinamik
 * Array bersifat rata kiri ; elemennya adalah string (char*)
*/

#ifndef __ARRAY_STR_DYNAMIC__
#define __ARRAY_STR_DYNAMIC__

/* Definisi Boolean */
#define boolean unsigned char
#define true 1
#define false 0

#define StartSize 100

typedef int TypeIdx;
typedef char *TypeEl;
typedef struct {
	TypeEl *Ar;
	int Kapasitas;
	int Neff;
} ArrayDyn;

/* KONSTRUKTOR 
 * I.S.	sembarang;
 * F.S.	Terbentuk DynArray kosong yang berukuran StartSize;
*/
ArrayDyn CreateArrayDyn();

/* DESTRUKTOR
 * I.S.	DynArray terdefinisi;
 * F.S.	DynArray->arrdin terdealokasikan;
*/
void DealokasiArrayDyn(ArrayDyn *array);

/* PRIMITIF LAINNYA */
/* Fungsi IsEmpty
 * Fungsi untuk mengetahui apakah array input kosong atau tidak.
 * Prekondisi : array sudah terdefinisi
*/
boolean IsEmpty(ArrayDyn array);

/* Fungsi Length
 * Fungsi untuk mengetahui banyaknya elemen efektif dalam sebuah array,
 * bernilai 0 jika kosong.
 * Prekondisi : array sudah terdefinisi
*/
int Length(ArrayDyn array);

/* Fungsi Get
 * Fungsi untuk mengembalikan nilai elemen array yang ke-i (logical index).
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
TypeEl Get(ArrayDyn array, TypeIdx i);

/* Fungsi GetCapacity
 * Fungsi untuk mengembalikan kapasitas dari array yang tersedia.
 * Prekondisi : array sudah terdefinisi
*/
int GetCapacity(ArrayDyn array);

/* Fungsi InsertIn
 * Fungsi untuk memasukkan elemen baru pada indeks ke-i
 * Prekondisi : array sudah terdefinisi,
 * 				dan i berada di [0...Length(array))
*/
void InsertIn(ArrayDyn *array, TypeEl elmt, TypeIdx i);

/* Fungsi InsertFirst
 * Fungsi untuk memasukkan elemen baru di awal array
 * Prekondisi : array sudah terdefinisi
*/
void InsertFirst(ArrayDyn *array, TypeEl elmt);

/* Fungsi InsertLast
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertLast(ArrayDyn *array, TypeEl elmt);

/* Fungsi DeleteIn
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array sudah terdefinisi dan tidak kosong,
 * 				dan i berada di [0...Length(array))
*/
void DeleteIn(ArrayDyn *array, TypeIdx i);

/* Fungsi DeleteFirst
 * Fungsi untuk menghapus elemen di awal array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteFirst(ArrayDyn *array);

/* Fungsi DeleteLast
 * Fungsi untuk menghapus elemen di akhir array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteLast(ArrayDyn *array);

/* Fungsi ShowDynArray
 * Fungsi untuk menampilkan DynArray ke layar
 * Tampilan array memiliki format : [elemen-1, elemen-2, ..., elemen-terakhir]
 * yang diakhiri dengan baris baru (newline)
 * Prekondisi : array sudah terdefinisi
*/
void ShowArrayDyn(ArrayDyn array);

/* Fungsi ReverseDynArray
 * Fungsi untuk mengubah urutan array menjadi terbalik (reverse)
 * Prekondisi : array sudah terdefinisi
*/
void ReverseArrayDyn(ArrayDyn *array);

/* Fungsi CopyDynArray
 * Fungsi untuk menyalin suatu DynArray
 * Prekondisi : array sudah terdefinisi
*/
ArrayDyn CopyArrayDyn(ArrayDyn array);

/* Fungsi FindDynArray
 * Fungsi untuk melakukan search pada suatu DynArray
 * Indeks pertama yang ditemukan akan dikembalikan,
 * apabila tidak ditemukan maka akan mengembalikan -1.
 * Prekondisi : array sudah terdefinisi
*/
TypeIdx FindArrayDyn(ArrayDyn array, TypeEl elmt);

#endif
