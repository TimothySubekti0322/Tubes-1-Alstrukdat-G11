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

typedef struct{
    ArrayDyn a;
    ArrayDyn b;
    ArrayDyn c;
    ArrayDyn d;
    ArrayDyn e;
} Board;

Board CreateBoard();

void randomnumber(int *x,int *y);

void UbahBoard(Board *papan,int x,int y);

boolean IsValid(char *coordinates);

boolean IsBlankGrid(Board papan,int x,int y);

int xcoor(char *coordinates);

int ycoor(char *coordinates);

void PrintPapan(Board papan);

void mole();

#endif