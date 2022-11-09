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

typedef struct{
        int indeks[10];
        int durasi[10];
        int count;
} masaksaji;

typedef struct{
    Queue indeks;
    int durasi[25];
    int ketahanan[25];
    int harga[25];
} customers;


void IsMemberMasakSaji(masaksaji m,int custnumber,boolean *found,int *indeks);
/*Mengecek jika sutu custnumber merupakan member dari masak atau saji dan 
meletakkan status dari hasil pencarian di found dan indeks ditemukannya di indeks*/

void masaksajiempty(masaksaji *m);
   /*Inisialisasi struct masak atau saji yang kosong*/


int strlength(char *sentence);
/*Mencari panjang dari sebuah string, merupakan pengganti dari strlen*/

boolean serves(char *command);
/*Mengecek apabila command berisi petunjuk untuk serve*/

boolean cooks(char *command);
/*Mengecek apabila command berisi petunjuk untuk cook*/

boolean skip(char *command);
/*Mengecek apabila command berisi petunjuk untuk skip*/

int custnumbers(char *command);
/*Mencari indeks customer yang akan di cook atau serve dari command*/

void DeleteMasakSaji(masaksaji *m,int indeks);
/*Melakukan penghapusan suatu indeks pada struct masak atau saji*/

void tambahturn(masaksaji *masak, masaksaji *saji,customers *orders);
/*Melakukan penambahan turn dengan menambah satu customer, mengurangi durasi memasak
dan mengurangi ketahanan saji, lalu memindahkan makanan pada struct masak dengan durasi 0 
dan menghilangkan makanan pada struct saji dengan ketahanan 0*/

void dinnerdash();
/*Memulai game dinerdash yang awalnya menampilkan isi antrian,makanan yang dimasak, makanan yang dapat disaji
lalu meminta command dan memproses COOK dan SERVE berdasarkan primitif primitif pada dinner dash*/
#endif