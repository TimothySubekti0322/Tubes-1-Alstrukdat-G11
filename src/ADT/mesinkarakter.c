<<<<<<< HEAD
#include "mesinkarakter.h"

static FILE * pita;
static int retval;

char currentChar;
boolean EOP;

/* *** ADT untuk baca file eksternal *** */

void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen(filename,"r");
=======
#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char *FileName)
{

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    pita = fopen(FileName,"r");
>>>>>>> 0a19d9aac65e305cb74b2e2aceecc23c5b917684
    ADV();
}

void ADV()
<<<<<<< HEAD
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
=======
{
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

    retval = fscanf(pita, "%c" , &currentChar);
    if (IsEOP()) 
    {
>>>>>>> 0a19d9aac65e305cb74b2e2aceecc23c5b917684
        fclose(pita);
    }
}

<<<<<<< HEAD



=======
char GetCC()
{
/* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOP()
{
/* Mengirimkan true jika currentChar = MARK */
    return (currentChar == MARK);
}
>>>>>>> 0a19d9aac65e305cb74b2e2aceecc23c5b917684
