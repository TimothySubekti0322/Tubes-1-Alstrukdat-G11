/*
    * File stackstr.h
    * File header untuk deklarasi stack menggunakan tabel kontigu dan berukuran sama
    * TOP adalah alamat elemen puncak
    * Alokasi statik; isi stack berupa string 
*/

#ifndef STACK_STRING_H
#define STACK_STRING_H

#include "../../boolean.h" // File pendefinisian boolean secara manual

#define NIL -1
/* NIL adalah stack dengan elemen kosong. */
#define InitSize 100

typedef char* strtype;
typedef int address; // indeks tabel

typedef struct {
    strtype T[InitSize]; // Tabel untuk menyimpan elemen (string)
    address TOP; // Menyimpan alamat dari elemen puncak stack (TOP)
} StackStr;
/*
    * StackStr adalah kosong apabila alamat elemen puncaknya adalah NIL,
    * dalam kata lain, ketika S.TOP = NIL.
    * Apabila S adalah StackStr, berikut cara untuk mengakses StackStr:
    * S.TOP untuk mengakses alamat dari elemen puncak
    * S.T[S.TOP] untuk mengakses elemen puncak
*/

/* Pendefinisian fungsi makro untuk mempermudah pengaksesan Stack */
#define Top(S) (S).TOP
#define INFOTop(S) (S).T[(S).TOP]

/* *************** PROTOTYPE *************** */

/* ***** KONSTRUKTOR / KREATOR ***** */
void CreateEmptyStackStr (StackStr *S);
/*
    * I.S.  sembarang
    * F.S.  Menciptakan StackStr S yang kosong dan berkapasitas InitSize
    * yang memiliki indeks 0..InitSize - 1.
    * StackStr adalah kosong apabila TOP berNILai NIL.
*/

/* ********** PREDIKAT UNTUK MENGUJI KEADAAN STACKSTR ********** */
boolean IsStackStrEmpty (StackStr S);
/*
    * Mengirimkan true apabila StackStr kosong, yaitu saat TOP berNILai NIL.
    * Sebaliknya mengirimkan false.
*/
boolean IsStackStrFull (StackStr S);
/*
    * Mengirimkan true apabila StackStr penuh, yaitu saat TOP berNILai InitSize - 1.
    * Sebaliknya mengirimkan false.
*/

/* ********** PENAMBAHAN ELEMEN KE STACK ********** */
void PushStackStr (StackStr *S, strtype X);
/*
    * Menambahkan X sebagai elemen StackStr S.
    * I.S.  S mungkin kosong, tetapi tidak penuh.
    * F.S.  X menjadi TOP yang baru, TOP bertambah 1.
*/

/* ********** PENGHAPUSAN ELEMEN DARI STACK ********** */
void PopStackStr (StackStr *S, strtype *X);
/*
    * Menghapus X dari StackStr S.
    * I.S.  S tidak kosong.
    * F.S.  X adalah NILai elemen TOP yang lama, TOP berkurang 1.
*/

void ReverseStack (StackStr *S); 
/* Membalikan Urutan Stack
 * I.S. S sudah terdefinisi dan mungkin kosong,
 * F.S.	Urutan S Terbalik
*/

#endif