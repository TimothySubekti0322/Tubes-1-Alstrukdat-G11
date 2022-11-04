#include <stdio.h>
#include "mesinkarakter.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

/* *** START *** */
void START(char *FileName)
{

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari FileName.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
    pita = fopen(FileName,"r");
    ADV();
}

void STARTINPUT() 
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != ENTER maka EOP akan padam (false)
    Jika CC = ENTER maka EOP akan menyala (true) */
{
    pita = stdin;
    ADV();
}

/* *** ADV *** */
void ADVSTOPMARK()
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

void ADV()
{
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = ENTER
Jika CC = ENTER maka EOP akan menyala (true) */
    retval = fscanf(pita,"%c",&CC);
    // if (IsNewline()) {
    //     // fclose(pita); --> Membiarkan agar pita dapat terus terbaca oleh mesin
    // }
}

void ADVFILE() 
{
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != End-Of-File
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = End-Of-File
Jika CC = End-Of-File maka EOP akan menyala (true) */
    retval = fscanf(pita,"%c",&CC);
    if(IsFeof())
    {
        fclose(pita);
    }
}

/* *** GET CHARACTER *** */
char GetCC()
{
/* Mengirimkan CC */
    return CC;
}

/* *** boolean *** */
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

boolean IsFeof()
{
/* Mengirimkan true jika*/
    return(feof(pita));
}

boolean IsPitaNull()
{
    /* Mengembalikan true jika pita NULL*/
    return (pita == NULL);
}