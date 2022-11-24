/* File: mole.h */
/* Definisi Games mole */

#ifndef mole_H
#define mole_H

#include "../src/boolean.h"
#include "../src/ADT/array/arraydinamikstr.h"
#include "../src/console.h"
#include "../src/ADT/queue/queue.h"
#include "../src/ADT/mesinkata/mesinkata.h"
#include "../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../src/ADT/queue/queuestr.h" // Somehow diminta??????
#include "../Game/dinerdash.h"
#include "../Game/RNG.h"
#include "../src/ADT/map/map.h"

typedef struct{
    ArrayDyn a;
    ArrayDyn b;
    ArrayDyn c;
    ArrayDyn d;
    ArrayDyn e;
} Board;

Board CreateBoard();
/* Membuat sebuah papan kosong yang berisi O
I.S. sembarang
F.S. Papan terdefinisi dan direturn*/

void randomnumber(int *x,int *y);
/* Membuat random number dari range 1-5 dan dimasukkan dalan x dan y
I.S. x dan y terdefinisi
F.S. x dan y diubah dengan angka random*/

void UbahBoard(Board *papan,int x,int y);
/* Mengubah suatu block pada papan dengan X yang berarti terisi
I.S. Papan terdefinisi, Papan bisa saja berisi O semua
F.S. Grid papan berubah menjadi X sesuai input x dan y, papan akhir
bisa saja penuh dengan x*/

boolean IsValid(char *coordinates);
/* Memberikan status true jika input valid yaitu 1 <= x <= 5 dan 1<= y <= 5
 I.S. coordinates terdefinisi, sudah diinput user.
 F.S. Mengembalikan true atau false jika coordinates sudah valid*/

boolean IsBlankGrid(Board papan,int x,int y);
/* Mengecek apabila grid pada papan kosong dan berisi O pada x dan y yang diinput
I.S. papan terdefinisi, x dan y terdefinisi
F.S. Mengembalikan pengecekan jika grid pada papan masih kosong*/

int xcoor(char *coordinates);
/* Mengembalikan koordinat x pada coordinates.
I.S. coordinates terdefinisi
F.S. Direturn x pada koordinat*/

int ycoor(char *coordinates);
/* Mengembalikan koordinat y pada coordinates.
I.S. coordinates terdefinisi
F.S. Direturn y pada koordinat*/

void PrintPapan(Board papan);
/* Memprint papan yang sedang dijalani
I.S. papan terdefinisi
F.S. Ditampilkan papan pada layar*/

void mole(ArrayDyn ArrayGame, ArrayMap *MapGame);
/* Bermain game mole dimana player harus mencari mole yang tersembunyi pada papan 5x5
Input yang salah akan terisi akan menjadi "X". Inputan hanya bisa "menggali" grid kosong
Skor yang didapatkan berdasarkan seberapa cepat pemain menemukan mole.*/
#endif