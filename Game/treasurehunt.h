#include <stdio.h>
#include "../src/console.h"
#include "../src/ADT/tree/tree.h"

//colors
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define reset "\e[0m"

void ReadStory(BinTree Story);
/*Melakukan pembacaaan cerita pada Tree*/

void ProgressStory(BinTree Story,int *choice,int *score);
/*Melakukan penlanjutan story melalui choice dan penambahan score jika mencapai ending baik.*/

void treasure_hunt(ArrayDyn ArrayGame, ArrayMap *MapGame);
/*Memainkan game treasure hunt di mana diberikan dua pilihan tiap menemukan halangan
dan memberikan score jika mencapai ending baik.*/