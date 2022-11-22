/* 
    * File stackstr.c
    * File berisi implementasi fungsi dari file header stackstr.h 
*/

#include "stackstr.h"

/* ***** KONSTRUKTOR / KREATOR ***** */
void CreateEmptyStackStr(StackStr *S)
{
    S->TOP = Nil;
}
/*
 * I.S.  sembarang
 * F.S.  Menciptakan StackStr S yang kosong dan berkapasitas InitSize
 * yang memiliki indeks 0..InitSize - 1.
 * StackStr adalah kosong apabila TOP bernilai Nil.
 */

/* ********** PREDIKAT UNTUK MENGUJI KEADAAN STACKSTR ********** */
boolean IsStackStrEmpty(StackStr S)
{
    return (Top(S) == Nil);
}
/*
 * Mengirimkan true apabila StackStr kosong, yaitu saat TOP bernilai Nil.
 * Sebaliknya mengirimkan false.
 */
boolean IsStackStrFull(StackStr S)
{
    return (Top(S) == InitSize - 1);
}
/*
 * Mengirimkan true apabila StackStr penuh, yaitu saat TOP bernilai InitSize - 1.
 * Sebaliknya mengirimkan false.
 */

/* ********** PENAMBAHAN ELEMEN KE STACK ********** */
void PushStackStr(StackStr *S, strtype X)
{
    Top(*S)++;
    INFOTop(*S) = X;
}
/*
 * Menambahkan X sebagai elemen StackStr S.
 * I.S.  S mungkin kosong, tetapi tidak penuh.
 * F.S.  X menjadi TOP yang baru, TOP bertambah 1.
 */

/* ********** PENGHAPUSAN ELEMEN DARI STACK ********** */
void PopStackStr(StackStr *S, strtype *X)
{
    (*X) = INFOTop(*S);
    Top(*S)--;
}
/*
 * Menghapus X dari StackStr S.
 * I.S.  S tidak kosong.
 * F.S.  X adalah nilai elemen TOP yang lama, TOP berkurang 1.
 */