/* File : arraydinamik.h
 * File Header berisi definisi ADT Array yang menggunakan alokasi dinamik
 * Array bersifat rata kiri
*/

#ifndef __STATIC_ARRAY__
#define __STATIC_ARRAY__

/* Definisi Boolean */
#define boolean unsigned char
#define true 1
#define false 0

#define Size 100

typedef int IdxType;
typedef int ElType;
typedef struct {
	ElType Ar[100];
	int Neff;
} StatArray;

/* KONSTRUKTOR 
 * I.S.	sembarang;
 * F.S.	Terbentuk StatArray kosong;
*/
StatArray CreateStatArray();

/* DESTRUKTOR
 * I.S.	StatArray terdefinisi;
 * F.S.	StatArray->arr terdealokasikan;
*/
void DealokasiStatArray(StatArray *array);

/* PRIMITIF LAINNYA */
/* Fungsi IsEmptyStat
 * Fungsi untuk mengetahui apakah array input kosong atau tidak.
 * Prekondisi : array sudah terdefinisi
*/
boolean IsEmptyStat(StatArray array);

/* Fungsi LengthStat
 * Fungsi untuk mengetahui banyaknya elemen efektif dalam sebuah array,
 * bernilai 0 jika kosong.
 * Prekondisi : array sudah terdefinisi
*/
int LengthStat(StatArray array);

/* Fungsi GetStat
 * Fungsi untuk mengembalikan nilai elemen array yang ke-i (logical index).
 * Prekondisi : array tidak kosong, dan i berada di [0...LengthStat(array))
*/
ElType GetStat(StatArray array, IdxType i);


/* Fungsi InsertStat
 * Fungsi untuk memasukkan elemen baru pada indeks ke-i
 * Prekondisi : array sudah terdefinisi,
 * 				dan i berada di [0...LengthStat(array))
*/
void InsertStat(StatArray *array, ElType elmt, IdxType i);

/* Fungsi InsertFStat
 * Fungsi untuk memasukkan elemen baru di awal array
 * Prekondisi : array sudah terdefinisi
*/
void InsertFStat(StatArray *array, ElType elmt);

/* Fungsi InsertLStat
 * Fungsi untuk memasukkan elemen baru di akhir array
 * Prekondisi : array sudah terdefinisi
*/
void InsertLStat(StatArray *array, ElType elmt);

/* Fungsi DeleteStat
 * Fungsi untuk menghapus elemen pada indeks ke-i
 * Prekondisi : array sudah terdefinisi dan tidak kosong,
 * 				dan i berada di [0...LengthStat(array))
*/
void DeleteStat(StatArray *array, IdxType i);

/* Fungsi DeleteFStat
 * Fungsi untuk menghapus elemen di awal array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteFStat(StatArray *array);

/* Fungsi DeleteLStat
 * Fungsi untuk menghapus elemen di akhir array
 * Prekondisi : array sudah terdefinisi dan tidak kosong
*/
void DeleteLStat(StatArray *array);

/* Fungsi ShowStatArray
 * Fungsi untuk menampilkan StatArray ke layar
 * Tampilan array memiliki format : [elemen-1, elemen-2, ..., elemen-terakhir]
 * yang diakhiri dengan baris baru (newline)
 * Prekondisi : array sudah terdefinisi
*/
void ShowStatArray(StatArray array);

/* Fungsi ReverseStatArray
 * Fungsi untuk mengubah urutan array menjadi terbalik (reverse)
 * Prekondisi : array sudah terdefinisi
*/
void ReverseStatArray(StatArray *array);

/* Fungsi CopyStatArray
 * Fungsi untuk menyalin suatu StatArray
 * Prekondisi : array sudah terdefinisi
*/
StatArray CopyStatArray(StatArray array);

/* Fungsi FindStatArray
 * Fungsi untuk melakukan search pada suatu StatArray
 * Indeks pertama yang ditemukan akan dikembalikan,
 * apabila tidak ditemukan maka akan mengembalikan -1.
 * Prekondisi : array sudah terdefinisi
*/
IdxType FindStatArray(StatArray array, ElType elmt);

#endif
