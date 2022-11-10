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
 * F.S.	Terbentuk ArrayDyn kosong yang berukuran StartSize;
*/
ArrayDyn CreateStrArrayDyn();

/* DESTRUKTOR
 * I.S.	ArrayDyn terdefinisi;
 * F.S.	ArrayDyn->arr terdealokasikan;
*/
void DealokasiStrArrayDyn(ArrayDyn *array);

/* PRIMITIF LAINNYA */
/* Fungsi IsStrEmpty
 * Fungsi untuk mengetahui apakah array input kosong atau tidak.
 * Prekondisi : array sudah terdefinisi
*/
boolean IsStrEmpty(ArrayDyn array);

/* Fungsi StrLength
 * Fungsi untuk mengetahui banyaknya elemen efektif dalam sebuah array,
 * bernilai 0 jika kosong.
 * Prekondisi : array sudah terdefinisi
*/
int StrLength(ArrayDyn array);

/* Fungsi GetStr
 * Fungsi untuk mengembalikan nilai elemen array yang ke-i (logical index).
 * Prekondisi : array tidak kosong, dan i berada di [0...Length(array))
*/
TypeEl GetStr(ArrayDyn array, TypeIdx i);

/* Fungsi GetStrCapacity
 * Fungsi untuk mengembalikan kapasitas dari array yang tersedia.
 * Prekondisi : array sudah terdefinisi
*/
int GetStrCapacity(ArrayDyn array);

/* Fungsi InsertStrIn
 * Fungsi untuk memasukkan elemen baru pada indeks ke-i
 * Prekondisi : array sudah terdefinisi,
 * 				dan i berada di [0...Length(array))
*/
void InsertStrIn(ArrayDyn *array, TypeEl elmt, TypeIdx i);

/* Fungsi InsertStrFirst
 * Fungsi untuk memasukkan elemen baru di awal array
 * Prekondisi : array sudah terdefinisi
*/
void InsertStrFirst(ArrayDyn *array, TypeEl elmt);

/* Fungsi InsertStrLast
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertStrLast(ArrayDyn *array, TypeEl elmt);

/* Fungsi DeleteStrIn
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array sudah terdefinisi dan tidak kosong,
 * 				dan i berada di [0...Length(array))
*/
void DeleteStrIn(ArrayDyn *array, TypeIdx i);

/* Fungsi DeleteStrFirst
 * Fungsi untuk menghapus elemen di awal array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteStrFirst(ArrayDyn *array);

/* Fungsi DeleteStrLast
 * Fungsi untuk menghapus elemen di akhir array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteStrLast(ArrayDyn *array);

/* Fungsi ShowStrArrayDyn
 * Fungsi untuk menampilkan ArrayDyn ke layar
 * Tampilan array memiliki format : [elemen-1, elemen-2, ..., elemen-terakhir]
 * yang diakhiri dengan baris baru (newline)
 * Prekondisi : array sudah terdefinisi
*/
void ShowStrArrayDyn(ArrayDyn array);

/* Fungsi ReverseStrArrayDyn
 * Fungsi untuk mengubah urutan array menjadi terbalik (reverse)
 * Prekondisi : array sudah terdefinisi
*/
void ReverseStrArrayDyn(ArrayDyn *array);

/* Fungsi CopyStrArrayDyn
 * Fungsi untuk menyalin suatu ArrayDyn
 * Prekondisi : array sudah terdefinisi
*/
ArrayDyn CopyStrArrayDyn(ArrayDyn array);

/* Fungsi FindStrArrayDyn
 * Fungsi untuk melakukan search pada suatu ArrayDyn
 * Indeks pertama yang ditemukan akan dikembalikan,
 * apabila tidak ditemukan maka akan mengembalikan -1.
 * Prekondisi : array sudah terdefinisi
*/
TypeIdx FindStrArrayDyn(ArrayDyn array, TypeEl elmt);

#endif
