#include <stdio.h>
#include "mesinkatav2.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;


/* *** ADT untuk baca file eksternal *** */

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (currentChar == BLANK || currentChar == "\n"){
        ADV();
    }
}

void STARTWORD(char* filename)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(filename);
    IgnoreBlank();
    if (currentChar == MARK || currentChar == "\n"){
        EndWord = true;
    } else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (currentChar == MARK || currentChar == "\n"){
        EndWord = true;
    } else{
        CopyWord();
        IgnoreBlank();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((currentChar != MARK) && (currentChar != '\n')) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = (i < NMax) ? i : NMax;
}



