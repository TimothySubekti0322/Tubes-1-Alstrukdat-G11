/* File: mesinWord.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkarakter.h"

#define NMax 100
#define BLANK ' '

typedef struct 
{
	char TabWord[NMax]; /* container penyimpan Word, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;


/* State Mesin Word */
extern boolean EndWord;
extern Word CWord;
extern Word CCommand;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTGAME(char *FileName);
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */

void ADVWORD();
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */


boolean IsBlank();
/* Mengirimkan true jika CWord = BLANK */


/* *** ADT untuk membaca commands *** */

void IgnoreDot();
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */

void STARTCOMMAND();
/* I.S. : CC sembarang 
   F.S. : EndWord = true, dan CC = ENTER; 
          atau EndWord = false, CCommand adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */

void ADVCOMMAND();
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi 
   F.S. : CComand adalah Word terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari Word berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.		  
   Proses : Akuisisi Word menggunakan procedure SalinCommand */

void CopyCommand();
/* Mengakuisisi Word, menyimpan dalam CComand
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CComand berisi Word yang sudah diakuisisi; 
          CC = BLANK atau CC = ENTER; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */


/* *** FUNGSI TAMBAHAN *** */

boolean IsKataSama(Word InputCommand, Word Command);
/* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

void PrintWord(Word CWord);
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */

int stringLength (char* string);
/* Mengirimkan panjang sebuah string */

Word toWord(char* command);
/* Mengirimkan Word yang elemen of arraynya berasal dari command */

int toInt(char* string);
/* Mengubah sebuah string menjadi integer*/

#endif