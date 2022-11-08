#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "RNG.h"

void gameRNG()  
{  
    srand(time(NULL));
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka X yang rentangnya berada diantara 1 - 10.\n");
    int MaxTry = 10;
    int tebakan;
    int skor = 0;
    int Target = rand() % 10 + 1;
    printf("%d\n",Target); //Cheat Code - Buat Tahu Jawabannya :)
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
    if(nTebakan == MaxTry){
        printf("GAME OVER!\n");
    }
    else{
        printf("YA , X Adalah %d\n" , Target);
    }
    skor = MaxTry - nTebakan + 1;
    printf("skor = %d" , skor);
    //return skor;
}

/*TEST CASE*/

// int main(){
//     gameRNG();
//     return 0;
// }