#include "ADT/arraydinamik.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkatav2.h"
#include "stdlib.h"
#include <stdio.h>


void STARTGAME(DynArray* gamesBNMO){
    STARTWORD("config.txt");
    int jumlahGame;
    jumlahGame = atoi(currentWord.TabWord);
    ADVWORD();
    
    int i;
    i = 0;
    while (currentChar != MARK ){

        int i = 0;
        
        while (i < jumlahGame){
            char *namaGame;
            namaGame = (char*) malloc(currentWord.Length * sizeof (char));

            int k = 0;
            while (k < currentWord.Length){
                namaGame[k] = currentWord.TabWord[k];
                k = k+1;
            }
            InsertLast(gamesBNMO, namaGame);
            i = i +1;
            ADVWORD();
        }

    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void QUIT(boolean EndGame){
    EndGame = true;
}

int main(){
    DynArray games;
    STARTGAME(&games);
    ShowDynArray(games);
}