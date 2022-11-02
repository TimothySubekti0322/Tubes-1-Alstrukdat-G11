<<<<<<< HEAD
#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "boolean.h"
#include <stdio.h>
#define MARK '.'



=======
/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "D:/Semester 3/ALSTRUKDAT/TUBES 1/Tubes-1-Alstrukdat-G11/src/boolean.h"

#define MARK '.'
>>>>>>> 0a19d9aac65e305cb74b2e2aceecc23c5b917684
/* State Mesin */
extern char currentChar;
extern boolean EOP;

<<<<<<< HEAD
/*
  pada implementasi (mesin_kar.c), perlu ditambahkan variabel static 
  global yang menyimpan pembacaan file pita.
*/

/* *** Membaca dari File *** */
void START(char* filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */


void ADV();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */

/* *** Membaca dari terminal *** */

=======
void START(char *FileName);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */
>>>>>>> 0a19d9aac65e305cb74b2e2aceecc23c5b917684

#endif