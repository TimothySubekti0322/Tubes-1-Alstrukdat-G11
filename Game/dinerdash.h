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

void gameRNG();
/* Game RNG
   Game menebak suatu Angka Acak X yang berada para rentang 1 - 10. . Di setiap giliran, user diberi 
   kesempatan menebak angka X dan program akan memberi  tahu apakah tebakan pemain dibandingkan 
   terhadap X lebih besar atau lebih kecil User memiliki kesempatan untuk menebak sebanyak 10 kali
   Permainan berakhir jika pemain menebak angka X dengan benar. Skor game akan muncul di akhir Game 
   berdasarkan seberapa cepat pemain menebak X.*/

#endif