#ifndef THANOI_H
#define THANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "../src/ADT/stack/stackint.h"
#include "../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../src/ADT/mesinkata/mesinkata.h"
#include "../src/boolean.h"
#include "../src/ADT/map/arrayofmap.h"
#include "../src/ADT/array/arraydinamikstr.h"
#include "../src/ADT/map/map.h"
#include "../src/console.h"


void CreateStackIntA(StackInt *S, int size);
/*
    I.S : Sembarang
    F.S : Membuat stack yang berisi angka 1 sampai 5 secara berurutan dengan angka 1
    adalah angka terakhir yang masuk ke dalam stack
*/

void displaystack(StackInt S,int size, int i);
/*
    I.S : Stack sudah terbentuk
    F.S : Menampilkan stack berupa "*" dengan jumlah sesuai nilai elemen yang sedang diakses
*/

void movepiring (char tujuan, boolean found);
/*
    I.S : sembarang
    F.S : Menampilkan perpindahan piring ke suatu tiang
*/

void displaytiang(StackInt A, StackInt B, StackInt C, int size);
/*
    I.S: Terdapat tiga stack yang terbentuk, stack mungkin kosong
    F.S: MEnampilkan tiang-tiang yang ada dalam permainan tower of hanoi
 */

boolean movepiringtotiang(StackInt *awal, StackInt *tujuan, boolean found);
/*
    I.S: Terdapat dua stack yang terbentuk, stack mungkin kosong
    F.S: Memindahkan piring teratas dari tiang menuju tiang yang lain
 */

void bikingaris(StackInt S, int size);
/*
    I.S : stack terdefinisi, stack mungkin kosong
    F.S : menampilkan --------
*/

void commandH (char *awal, char *tujuan, StackInt *A, StackInt *B, StackInt*C, boolean found, int size);
/*
    I.S : Terdapat tiga stack yang terbentuk, stack mungkin kosong
    F.S : Memindahkan piringan dari tiang awal ke tiang tujuan sesuai command masukan
*/

void spasitiang (int size);
/*
    Membuat sapasi antar tiang
*/

int hitungskor (int langkah, int size);
/*
    I.S : sembarang
    F.S : Mengeluarkan nilai yang didapat sesuai banyak langkah
*/

int langkahefektif (int size);
/*
    I.S : sembarang
    F.S : Mengembalikan langkah efektif dalam memainkan tower of hanoi 
          sesuai jumlah piring;
*/

void cheatsheet (int langkah);
/*
    Input : jumlah langkah
    Output : Langkah yang harus dilakukan
*/

boolean langkahbenar(int langkah,char awal, char tujuan);
/*
    Input : jumlah langkah, char awal, char tujuan
    Output : menghasilkan boolean apakah langkah sesuai dengan cheatsheet
*/

void towerhanoi(ArrayDyn ArrayGame, ArrayMap *MapGame);

void KataToInt(Word kata, int *hasil);
/*
    I.S : Kata dan hasil terdefinisi
    F.S : hasil merupakan integer dari element Kata
*/


#endif