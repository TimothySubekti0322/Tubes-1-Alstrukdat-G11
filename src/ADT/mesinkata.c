#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CWord;
Word CCommand;

void IgnoreBlanks()
{
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

    while (CC == BLANK)
    {
        ADV();
    }
}

void STARTGAME(char *FileName)
{
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */
    START(FileName);
    IgnoreBlanks();
    
    if (IsEOP() || IsEOPC())
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
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyWord */
    IgnoreBlanks();
    if(IsEOP() || IsEOPC())
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
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */
    int i = 0;
    while ((!IsEOP()) && (!IsEOPC()))
    {
        if (i < NMax)
        {
        CWord.TabWord[i] = CC;
        i++;
        }
        ADV();
        
    }
    CWord.TabWord[i] = '\n';
    CWord.Length = i;
}


boolean IsBlank()
{
/* Mengirimkan true jika CWord = BLANK */
    return (CC == BLANK);
}

/* *** ADT untuk baca commands *** */

void IgnoreDot()
{
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */
    while (IsBlank() && IsEOP()) 
    {
        ADVC();
    }
}

void STARTCOMMAND()
{
/* I.S. : CC sembarang 
   F.S. : EndWord = true, dan CC = ENTER; 
          atau EndWord = false, CCommand adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */
    COMMAND();
    IgnoreDot();
    if (IsEOPC())
    {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND()
{
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi 
   F.S. : CCommand adalah Word terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari Word berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.		  
   Proses : Akuisisi Word menggunakan procedure CopyCommand */
    IgnoreDot();
    if (IsEOPC() && !EndWord){
        EndWord = true;
    } else{
        CopyCommand();
        IgnoreDot();
    }
}

void CopyCommand()
{
/* Mengakuisisi Word, menyimpan dalam CCommand
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CCommand berisi Word yang sudah diakuisisi; 
          CC = BLANK atau CC = ENTER; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */
    int i = 0;
    while (!IsBlank() && !IsEOPC()) 
    {
        if (i < NMax)
        {
        CCommand.TabWord[i] = CC;
        i++;
        }
        ADVC();
    }
    CCommand.Length = i;
}

/* *** Additional Function *** */

boolean IsKataSama(Word InputCommand, Word Command)
{
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

    boolean sama = true;
    if (InputCommand.Length != Command.Length) {
        return !sama;
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
   //printf("\n");
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

Word toKata(char* command) 
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

int toInt(char* string)
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