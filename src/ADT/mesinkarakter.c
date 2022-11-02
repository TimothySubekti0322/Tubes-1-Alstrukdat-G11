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
    ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}




