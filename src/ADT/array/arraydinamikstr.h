/* File : arraydinamikstr.h
 * File Header berisi definisi ADT Array yang menggunakan alokasi dinamik
 * Array bersifat rata kiri ; elemennya adalah string (char*)
*/

#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__

/* Definisi Boolean */
#define boolean unsigned char
#define true 1
#define false 0

#define StartSize 100

typedef int IdxType;
typedef char *ElType;
typedef struct {
	ElType *Ar;
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
ElType Get(ArrayDyn array, IdxType i);

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
void InsertIn(ArrayDyn *array, ElType elmt, IdxType i);

/* Fungsi InsertFirst
 * Fungsi untuk memasukkan elemen baru di awal array
 * Prekondisi : array sudah terdefinisi
*/
void InsertFirst(ArrayDyn *array, ElType elmt);

/* Fungsi InsertLast
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertLast(ArrayDyn *array, ElType elmt);

/* Fungsi DeleteIn
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array sudah terdefinisi dan tidak kosong,
 * 				dan i berada di [0...Length(array))
*/
void DeleteIn(ArrayDyn *array, IdxType i);

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
IdxType FindArrayDyn(ArrayDyn array, ElType elmt);

#endif
