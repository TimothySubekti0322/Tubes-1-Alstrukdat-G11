#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CWord;
Word CCommand;

void IgnoreNewLine()
{
    while (IsNewline())
    {
        ADV();
    }
}

void IgnoreBlanks()
{
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

    while (IsBlank())
    {
        ADV();
    }
}

void IgnoreDot()
{
/* Mengabaikan satu atau beberapa Titik
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */
    while (IsEOP()) 
    {
        ADV();
    }
}

/* *** START dan Akuisisi *** */
void STARTFILE(char *FileName)
{
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */
    START(FileName);
    if(IsPitaNull())
    {
        EndWord = true;
    }
    else
    {
        IgnoreBlanks();
        
        if (IsFeof())
        {
            EndWord = true;
        }
        else
        {
            EndWord = false;
            CopyLineFile();
        }
    }
}

void INPUT()
{
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */
    STARTINPUT();
    IgnoreBlanks();
    
    if (IsNewline())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyLine();
    }
}

void ADVWORD()
{
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyWord */
    IgnoreBlanks();
    if(IsEOP() || IsNewline() || IsFeof())
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVLINEFILE()
{
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyWord */
    IgnoreNewLine();
    if(IsNewline())
    {
        EndWord = true;
    }
    else
    {
        CopyLineFile();
    }
}

void ADVLINE()
{
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyWord */
    IgnoreNewLine();
    if(IsNewline())
    {
        EndWord = true;
    }
    else
    {
        CopyLine();
    }
}

/* *** AKUISISI KATA *** */
void CopyWord()
{
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */
    int i = 0;
    while (!IsEOP() && !IsBlank() && !IsNewline() && !IsFeof())
    {
        if (i < NMax)
        {
        CWord.TabWord[i] = CC;
        i++;
        }
        ADV();
        
    }
    CWord.Length = i;
}

void CopyLineFile()
{
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */
    int i = 0;
    while (!IsEOP() && !IsNewline() && !IsFeof())
    {
        if (i < NMax)
        {
        CWord.TabWord[i] = CC;
        i++;
        }
        ADV();
        
    }
    CWord.Length = i;
}

void CopyLine()
{
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */
    int i = 0;
    while (!IsNewline())
    {
        if (i < NMax)
        {
        CWord.TabWord[i] = CC;
        i++;
        }
        ADV();
        
    }
    CWord.Length = i;
}

/* boolean*/
boolean IsBlank()
{
/* Mengirimkan true jika CWord = BLANK */
    return (CC == BLANK);
}
