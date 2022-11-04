#include <stdio.h>
#include <stdlib.h>
#include "console.h"


void STARTBNMO(DynArray *gamesBNMO){
     STARTFILE("config.txt");
    int jumlahGame;
    jumlahGame = atoi(CWord.TabWord);
    ADVLINEFILE();

    int i;
    i = 0;
    while (CC != MARK ){

        int i = 0;
        
        while (i < jumlahGame){
            char *namaGame;
            namaGame = (char*) malloc(CWord.Length * sizeof (char));

            int k = 0;
            while (k < CWord.Length){
                namaGame[k] = CWord.TabWord[k];
                k = k+1;
            }
            InsertLast(gamesBNMO, namaGame);
            i = i +1;
            ADVLINEFILE();
        }

    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}