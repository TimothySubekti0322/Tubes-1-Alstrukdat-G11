#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    
    if (IsEOP())
    {
        EndWord = true;
    }
    
    else
    {
        EndWord = false;
        CopyWord();
    }

}

void ADVWORD()
{
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if(IsEOP())
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}


void CopyWord()
{
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((!IsEOP()) && (!IsBlank()))
    {
        if (i < NMax)
        {
        currentWord.TabWord[i] = currentChar;
        i++;
        }
        ADV();
        
    }
    currentWord.Length = i;
}

void PrintWord(Word Currentword)
{
/* Mencetak current word
   I.S : Currentword tidak kosong dan terdefinisi
   F.S : isi dari Currentword dicetak ke layar */
   for (int i = 0 ; i < Currentword.Length ; i++)
   {
    printf("%c",Currentword.TabWord[i]);
   }
   printf("\n");
}

boolean IsBlank()
{
/* Mengirimkan true jika currentWord = BLANK */
    return (currentChar == BLANK);
}
