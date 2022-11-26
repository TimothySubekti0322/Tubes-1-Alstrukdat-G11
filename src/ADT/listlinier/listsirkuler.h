/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan addresslist adalah pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../../boolean.h"

#define NilList NULL

typedef int infotype;
typedef struct tElmtlist *addresslist;
typedef struct tElmtlist
{
    infotype info;
    addresslist next;
} ElmtList;
typedef struct
{
    addresslist First;
} List;

/* Definisi list : */
/* List kosong : First(L) = NilList */
/* Setiap elemen dengan addresslist P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addresslistnya Last, maka Next(Last)=First(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList(List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList(List *L);
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addresslist Alokasi(infotype X);
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak NilList, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
void Dealokasi(addresslist P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addresslist Search(List L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addresslist elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */

/****************** PRIMITIF BERDASARKAN NilListAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilListai X jika alokasi berhasil */
void InsVLast(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilListai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast(List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, addresslist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addresslist P sebagai elemen pertama */
void InsertLast(List *L, addresslist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter(List *L, addresslist P, addresslist Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, addresslist *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast(List *L, addresslist *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter(List *L, addresslist *Pdel, addresslist Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP(List *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddresslist P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilListai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif