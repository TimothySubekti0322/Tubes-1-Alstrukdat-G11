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
    while (!IsEOP() && !IsBlank())
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
    while (!IsEOP() && !IsNewline())
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

/* *** ADT untuk baca commands *** */



/* *** Additional Function *** */

boolean IsKataSama(Word InputCommand, Word Command)
{
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

    boolean sama = true;
    if (InputCommand.Length != Command.Length) {
        return (!sama);
    } else {
        int i = 0;
        while (sama && (i < Command.Length)) {
            if (InputCommand.TabWord[i] != Command.TabWord[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

void PrintWord(Word CWord)
{
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */
   for (int i = 0 ; i < CWord.Length ; i++)
   {
    printf("%c",CWord.TabWord[i]);
   }
   printf("\n");
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        *(string + i) = currentWord.TabWord[i];
        i++;
    }
    *(string + i) = '\0';
}

boolean CompareString(char *string1 , char *string2)
{
    boolean equal = true;
    int i = 0;
    while ((*(string1 + i) != '\0') && (*(string2 + i) != '\0') && equal)
    {
        if (*(string1 + i) != *(string2 + i))
        {
            equal = false;
        }
        else
        {
        i++;
        }
    }
}


void PrintString(char *string)
{
    /* Mencetak string
       I.S : String terdefinisi
       F.S : string tercetak ke layar */
    int i = 0;
    while(*(string + i) != '\0')
    {
        printf("%c", *(string + i));
        i++;
    }
    printf("\n");
}

int stringLength (char* string) 
/* Mengirimkan panjang sebuah string */
{
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

Word StringtoWord(char* command) 
/* Mengirimkan kata yang elemen of arraynya berasal dari command */
{
    int i;
    Word output;
    for (i = 0; i < stringLength(command); i++) {
        output.TabWord[i] = command[i];
    }
    output.Length = stringLength(command);
    return output;
}

int StringtoInt(char* string)
{
    /* Mengubah sebuah string menjadi integer*/
    int i = 0;
    int hasil = 0;
    while(*(string + i) != '\0')
    {
        hasil = hasil*10 + (*(string+i) - '0');
        i++;
    }
    return hasil;
}