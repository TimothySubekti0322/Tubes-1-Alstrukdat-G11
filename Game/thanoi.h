#ifndef THANOI_H
#define THANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "../src/ADT/stack/stackint.h"
#include "../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../src/ADT/mesinkata/mesinkata.h"
#include "../src/boolean.h"

void CreateStackIntA(StackInt *S);
/*
    I.S : Sembarang
    F.S : Membuat stack yang berisi angka 1 sampai 5 secara berurutan dengan angka 1
    adalah angka terakhir yang masuk ke dalam stack
*/

void displaystack(StackInt *S,int i);
/*
    I.S : Stack sudah terbentuk
    F.S : Menampilkan stack berupa "*" dengan jumlah sesuai nilai elemen yang sedang diakses
*/

void movepiring (char tujuan, boolean found);
/*
    I.S : sembarang
    F.S : Menampilkan perpindahan piring ke suatu tiang
*/

void displaytiang(StackInt A, StackInt B, StackInt C);
/*
    I.S: Terdapat tiga stack yang terbentuk, stack mungkin kosong
    F.S: MEnampilkan tiang-tiang yang ada dalam permainan tower of hanoi
 */

boolean movepiringtotiang(StackInt *awal, StackInt *tujuan, boolean found);
/*
    I.S: Terdapat dua stack yang terbentuk, stack mungkin kosong
    F.S: Memindahkan piring teratas dari tiang menuju tiang yang lain
 */

void commandH (char *awal, char *tujuan, StackInt *A, StackInt *B, StackInt*C, boolean found);
/*
    I.S : Terdapat tiga stack yang terbentuk, stack mungkin kosong
    F.S : Memindahkan piringan dari tiang awal ke tiang tujuan sesuai command masukan
*/

void loopHanoi (int *length, StackInt *A, StackInt *B, StackInt*C, boolean found);
/*
    I.S : Terdapat tiga stack yang terbentuk, stack mungkin kosong
    F.S : Melakukan loop untuk memainkan game
*/


#endif