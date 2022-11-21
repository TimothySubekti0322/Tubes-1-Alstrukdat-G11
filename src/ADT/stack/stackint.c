/*
 * File stackint.c
 * File berisi implementasi fungsi dari file header stackint.h
 */

#include "stackint.h"

/* ***** KONSTRUKTOR / KREATOR ***** */
void CreateEmptyStackInt(StackInt *S)
{
    S->TOP = Nil;
}
/*
 * I.S.  sembarang
 * F.S.  Menciptakan StackInt S yang kosong dan berkapasitas InitSize
 * yang memiliki indeks 0..InitSize - 1.
 * StackInt adalah kosong apabila TOP bernilai Nil.
 */

/* ********** PREDIKAT UNTUK MENGUJI KEADAAN StackInt ********** */
boolean IsStackIntEmpty(StackInt S)
{
    return (Top(S) == Nil);
}
/*
 * Mengirimkan true apabila StackInt kosong, yaitu saat TOP bernilai Nil.
 * Sebaliknya mengirimkan false.
 */
boolean IsStackIntFull(StackInt S)
{
    return (Top(S) == IntStartSize - 1);
}
/*
 * Mengirimkan true apabila StackInt penuh, yaitu saat TOP bernilai InitSize - 1.
 * Sebaliknya mengirimkan false.
 */

/* ********** PENAMBAHAN ELEMEN KE STACK ********** */
void PushStackInt(StackInt *S, infotype X)
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/*
 * Menambahkan X sebagai elemen StackInt S.
 * I.S.  S mungkin kosong, tetapi tidak penuh.
 * F.S.  X menjadi TOP yang baru, TOP bertambah 1.
 */

/* ********** PENGHAPUSAN ELEMEN DARI STACK ********** */
void PopStackInt(StackInt *S, infotype *X)
{
    (*X) = InfoTop(*S);
    Top(*S)--;
}
/*
 * Menghapus X dari StackInt S.
 * I.S.  S tidak kosong.
 * F.S.  X adalah nilai elemen TOP yang lama, TOP berkurang 1.
 */