/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../boolean.h"

#define MARK '.'
#define ENTER '\n'

/* State Mesin */
extern char CC;
extern boolean EOP;

void START(char *FileName);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari FileName.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void STARTINPUT();
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != ENTER maka EOP akan padam (false)
    Jika CC = ENTER maka EOP akan menyala (true) */

void ADVSTOPMARK();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */


void ADV();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = ENTER
Jika CC = ENTER maka EOP akan menyala (true) */


void ADVFILE();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != End-Of-File
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = End-Of-File
Jika CC = End-Of-File maka EOP akan menyala (true) */


char GetCC();
/* Mengirimkan CC */


boolean IsEOP();
/* Mengirimkan true jika CC = MARK */


boolean IsNewline();
/* Mengirimkan true jika CC = ENTER */

boolean IsFeof();
/* Mengirimkan true jika*/

boolean IsPitaNull();
/* Mengembalikan true jika pita NULL*/

#endif