#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "RNG.h"
#include "../src/console.h"

void gameRNG(ArrayDyn ArrayGame, ArrayMap *MapGame)  
{  
    srand(time(NULL));
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka X yang rentangnya berada diantara 1 - 100.\n");
    printf("Kamu mempunyai 10 kesempatan untuk menebak angka X ini\n");
    int MaxTry = 10;
    int tebakan;
    int skor = 0;
    int Target = rand() % 100 + 1;
    printf("Need Answer ? [Y/N] : ");
    INPUT();
    if (CWord.TabWord[0] == 'Y')
    {
        printf("%d\n",Target); //Cheat Code - Buat Tahu Jawabannya :)
    }
    //printf("%d\n",Target); //Cheat Code - Buat Tahu Jawabannya :)
    printf("Tebakan : ");
    INPUT();
    WordToInt(CWord,&tebakan);
    int nTebakan = 1;
    while((tebakan != Target) && (nTebakan <= MaxTry)){
        if(tebakan < Target){
            printf("Lebih Besar\n");
        }
        else if(tebakan > Target){
            printf("Lebih Kecil\n");
        }
        tebakan = 0;
        printf("Tebakan : ");
        INPUT();
        WordToInt(CWord,&tebakan);
        nTebakan++;
    }
    if(nTebakan == MaxTry+1){
        printf("GAME OVER!\n");
    }
    else{
        printf("YA , X Adalah %d\n" , Target);
    }
    skor = MaxTry - nTebakan + 1;
    printf("skor = %d\n" , skor);
    //return skor;
    int index = FindStrArrayDyn(ArrayGame,"RNG");
    InsertScoreBoard(&MapGame->ElArrMap[index], skor);
}