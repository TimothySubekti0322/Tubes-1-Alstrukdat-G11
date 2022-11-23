#ifndef THANOI_H
#define THANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "../src/ADT/stack/stackint.h"
#include "../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../src/ADT/mesinkata/mesinkata.h"

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

void movepiring (char tujuan);
/*
    I.S : sembarang
    F.S : Menampilkan perpindahan piring ke suatu tiang
*/

void displaytiang(StackInt A, StackInt B, StackInt C);
/*
    I.S: Terdapat tiga stack yang terbentuk, stack mungkin kosong
    F.S: MEnampilkan tiang-tiang yang ada dalam permainan tower of hanoi
 */

void movepiringtotiang(StackInt *awal, StackInt *tujuan);
/*
    I.S: Terdapat dua stack yang terbentuk, stack mungkin kosong
    F.S: Memindahkan piring teratas dari tiang menuju tiang yang lain
 */

void memilih (char pilih, StackInt *A, StackInt *B, StackInt*C);
/*
    I.S : Stack sudah terdefinisi stack bisa kosong
    F.S : Melakukan pemindahan tiang sesuai dengan input
*/

#endif