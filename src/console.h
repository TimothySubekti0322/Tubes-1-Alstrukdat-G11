#ifndef __CONSOLE__
#define __CONSOLE__

#include "ADT/array/arraydinamik.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"

void STARTBNMO(DynArray *gamesBNM0);

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