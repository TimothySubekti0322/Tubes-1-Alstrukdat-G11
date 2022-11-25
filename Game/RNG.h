/* File: RNG.h */
/* Definisi Games RNG */

#ifndef RNG_H
#define RNG_H

#include "../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../src/ADT/mesinkata/mesinkata.h"
#include "../src/ADT/map/arrayofmap.h"
#include "../src/ADT/array/arraydinamikstr.h"

void gameRNG(ArrayDyn ArrayGame, ArrayMap *MapGame); 
/* Game RNG
   Game menebak suatu Angka Acak X yang berada para rentang 1 - 10. . Di setiap giliran, user diberi 
   kesempatan menebak angka X dan program akan memberi  tahu apakah tebakan pemain dibandingkan 
   terhadap X lebih besar atau lebih kecil User memiliki kesempatan untuk menebak sebanyak 10 kali
   Permainan berakhir jika pemain menebak angka X dengan benar. Skor game akan muncul di akhir Game 
   berdasarkan seberapa cepat pemain menebak X.*/

#endif