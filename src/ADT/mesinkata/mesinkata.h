/* File: mesinWord.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"

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

void IgnoreNewLine();

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void IgnoreDot();
/* Mengabaikan satu atau beberapa Titik
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */

/* *** START dan Akuisisi *** */
void STARTFILE(char *FileName);
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = EOF;
          atau EndWord = false, CWord adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */

void INPUT();
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = ENTER;
          atau EndWord = false, CWord adalah Word yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Word */


void ADVWORD();
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyWord */

void ADVLINEFILE();
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin MARK
          Jika CC = Enter dan Feof, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyWord */


void ADVLINE();
/* I.S. : CC adalah karakter pertama Word yang akan diakuisisi
   F.S. : CWord adalah Word terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari Word berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.
   Proses : Akuisisi Word menggunakan procedure CopyLine */


/* *** AKUISISI KATA *** */
void CopyWord();
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */

void CopyLineFile();
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = ENTER
          Feof(pita) mungkin true;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */


void CopyLine();
/* Mengakuisisi Word, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari Word
   F.S. : CWord berisi Word yang sudah diakuisisi;
          CC = ENTER
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Word melebihi NMax, maka sisa Word "dipotong" */


/* *** boolean *** */
boolean IsBlank();
/* Mengirimkan true jika CC = BLANK */


/* *** Additional Function *** */

boolean IsKataSama(Word InputCommand, Word Command);
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

void PrintWord(Word CWord);
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */

void wordToString(Word currentWord, char *string);
/* Mengubah Word menjadi string*/

boolean CompareString(char *string1 , char *string2);
/* Mengirimkan true jika string1 = string2 */


void PrintString(char *string);
/* Mencetak string
   I.S : String terdefinisi
   F.S : string tercetak ke layar */


int stringLength (char* string);
/* Mengirimkan panjang sebuah string */


Word StringtoWord(char* command);
/* Mengirimkan kata yang elemen of arraynya berasal dari command */


int StringtoInt(char* string);
/* Mengubah sebuah string menjadi integer*/
 
#endif