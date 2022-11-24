/* File: dinerdash.h */
/* Definisi Games dinerdash */

#ifndef dinerdash_H
#define dinerdash_H

#include "../src/boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "math.h"
#include "../src/ADT/queue/queue.h"
#include "../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../src/ADT/mesinkata/mesinkata.h"
#include "../src/ADT/array/arraystatis.h"
#include "../src/ADT/map/map.h"
#include "../src/ADT/map/arrayofmap.h"

typedef struct{
        StatArray indeks;
        StatArray durasi;
        int count;
} masaksaji;
// Berfungsi sebagai penyimpan makanan dalam proses pemasakan dan penyajian

typedef struct{
    Queue indeks;
    StatArray durasi;
    StatArray ketahanan;
    StatArray harga;
} customers;
// Berfungsi sebagai penyimpan customer dalam queue dan info infonya

void IsMemberMasakSaji(masaksaji m,int custnumber,boolean *found,int *indeks);
/*Mengecek jika sutu custnumber merupakan member dari masak atau saji dan 
meletakkan status dari hasil pencarian di found dan indeks ditemukannya di indeks
I.S. masaksaji m terdefinisi, custnumber sudah diinput dan found dan indeks terdefinisi
sebagai penampung hasil
F.S. found jika ditemukan custnumber pada masak atau saji, indeks ditemukannya 
custnumber dikembalikan pada parameter indeks */

void masaksajiempty(masaksaji *m);
/*Inisialisasi struct masak atau saji yang kosong
I.S. m terdefinisi
F.S. dibuat masaksaji m yang kosong*/


int strlength(char *sentence);
/*Mencari panjang dari sebuah string, merupakan pengganti dari strlen
 I.S. sentence terdefinisi, sentence bisa saja kosong
 F.S. direturn panjang dari sentence*/

boolean serves(char *command);
/*Mengecek apabila command berisi petunjuk untuk serve
I.S. command terdefinisi, bisa saja kosong
F.S. dikembalikan status jika command berisi perintah untuk melakukan serve*/

boolean cooks(char *command);
/*Mengecek apabila command berisi petunjuk untuk cook
I.S. command terdefinisi, bisa saja kosong
F.S. dikembalikan status jika command berisi perintah untuk melakukan cook*/

boolean skip(char *command);
/*Mengecek apabila command berisi petunjuk untuk skip
I.S. command terdefinisi, bisa saja kosong
F.S. dikembalikan status jika command berisi perintah untuk melakukan skip*/

int custnumbers(char *command);
/*Mencari indeks customer yang akan di cook atau serve dari command
I.S. command terdefinisi, bisa saja kosong
F.S. Dikembalikan indeks dari customer dari command*/

void DeleteMasakSaji(masaksaji *m,int indeks);
/*Melakukan penghapusan suatu indeks pada struct masak atau saji
I.S. m terdefinisi, m tidak kosong, indeks sudah diinput
F.S. Dihapus info makanan yang dimasak pada indeks di masaksaji*/

void tambahturn(masaksaji *masak, masaksaji *saji,customers *orders);
/*Melakukan penambahan turn dengan menambah satu customer, mengurangi durasi memasak
dan mengurangi ketahanan saji, lalu memindahkan makanan pada struct masak dengan durasi 0 
dan menghilangkan makanan pada struct saji dengan ketahanan 0
I.S. Game sudah dimulai, masak, saji, dan orders terdefinisi.
F.S. Dilakukan operasi penambahan turn, durasi memasak dikurangi 1, customer ditambah,
ketahanan saji dikurangi satu, dan memindahkan makanan dari masak ke saji jika durasi sudah 0 dan 
makanan dihilangkan jika ketahanan sudah 0*/

void dinnerdash(ArrayDyn ArrayGame, ArrayMap *MapGame);
/*Memulai game dinerdash yang awalnya menampilkan isi antrian,makanan yang dimasak, makanan yang dapat disaji
lalu meminta command dan memproses COOK dan SERVE berdasarkan primitif primitif pada dinner dash*/
#endif