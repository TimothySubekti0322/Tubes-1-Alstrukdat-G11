/*
 * File stackint.h
 * File header untuk deklarasi stack menggunakan tabel kontigu dan berukuran sama
 * TOP adalah alamat elemen puncak
 * Alokasi statik; isi stack berupa integer
 */

#ifndef STACK_INTEGER_H
#define STACK_INTEGER_H

#include "../../boolean.h" // File pendefinisian boolean secara manual

#define NIL -1
/* NIL adalah stack dengan elemen kosong. */
#define IntStartSize 100

typedef int infotype;
typedef int address; // indeks tabel

typedef struct
{
    infotype T[IntStartSize]; // Tabel untuk menyimpan elemen (integer)
    address TOP;         // Menyimpan alamat dari elemen puncak stack (TOP)
} StackInt;
/*
 * StackStr adalah kosong apabila alamat elemen puncaknya adalah NIL,
 * dalam kata lain, ketika S.TOP = NIL.
 * Apabila S adalah StackStr, berikut cara untuk mengakses StackStr:
 * S.TOP untuk mengakses alamat dari elemen puncak
 * S.T[S.TOP] untuk mengakses elemen puncak
*/

/* Pendefinisian fungsi makro untuk mempermudah pengaksesan Stack */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* *************** PROTOTYPE *************** */

/* ***** KONSTRUKTOR / KREATOR ***** */
void CreateEmptyStackInt(StackInt *S);
/*
 * I.S.  sembarang
 * F.S.  Menciptakan StackStr S yang kosong dan berkapasitas IntStartSize
 * yang memiliki indeks 0..IntStartSize - 1.
 * StackStr adalah kosong apabila TOP berNILai NIL.
*/

/* ********** PREDIKAT UNTUK MENGUJI KEADAAN STACKSTR ********** */
boolean IsStackIntEmpty(StackInt S);
/*
 * Mengirimkan true apabila StackStr kosong, yaitu saat TOP berNILai NIL.
 * Sebaliknya mengirimkan false.
*/
boolean IsStackIntFull(StackInt S);
/*
 * Mengirimkan true apabila StackStr penuh, yaitu saat TOP berNILai IntStartSize - 1.
 * Sebaliknya mengirimkan false.
*/

/* ********** PENAMBAHAN ELEMEN KE STACK ********** */
void PushStackInt(StackInt *S, infotype X);
/*
 * Menambahkan X sebagai elemen StackStr S.
 * I.S.  S mungkin kosong, tetapi tidak penuh.
 * F.S.  X menjadi TOP yang baru, TOP bertambah 1.
*/

/* ********** PENGHAPUSAN ELEMEN DARI STACK ********** */
void PopStackInt(StackInt *S, infotype *X);
/*
 * Menghapus X dari StackStr S.
 * I.S.  S tidak kosong.
 * F.S.  X adalah NILai elemen TOP yang lama, TOP berkurang 1.
*/

int LengthStackInt(StackInt S);
/*
 * Mengirimkan banyaknya elemen StackStr S.
 * Mengirimkan 0 jika StackStr kosong.
*/

#endif