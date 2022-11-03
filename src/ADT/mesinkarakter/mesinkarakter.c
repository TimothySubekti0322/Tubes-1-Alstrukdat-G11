#include <stdio.h>
#include "mesinkarakter.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void START(char *FileName)
{

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
    pita = fopen(FileName,"r");
    ADV();
}

void ADV()
{
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

    retval = fscanf(pita, "%c" , &CC);
    if (IsEOP()) 
    {
        fclose(pita);
    }
}

void COMMAND() 
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != ENTER maka EOP akan padam (false)
    Jika CC = ENTER maka EOP akan menyala (true) */
{
    pita = stdin;
    ADVC();
}

void ADVC()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = ENTER
Jika CC = ENTER maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&CC);
    if (IsNewline()) {
        // fclose(pita); --> Membiarkan agar pita dapat terus terbaca oleh mesin
    }
}

char GetCC()
{
/* Mengirimkan CC */
    return CC;
}

boolean IsEOP()
{
/* Mengirimkan true jika CC = MARK */
    return (CC == MARK);
}

boolean IsNewline()
{
/* Mengirimkan true jika CC = ENTER */
    return (CC == ENTER);
}