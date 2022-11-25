/* Indeks yang digunakan [FirstIdxArrMap..LastIdxArrMap] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen Array Map
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Array Map kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff - 1 */
#include <stdio.h>
#include "arrayofmap.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Array Map kosong */
void MakeEmptyArrMap(ArrayMap *ArrMap)
{
/* I.S. sembarang */
/* F.S. Terbentuk ArrMap kosong dengan kapasitas LastIdxArrMap-FirstIdxArrMap+1 */
    Neff(*ArrMap) = 0;
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(ArrayMap ArrMap)
{
/* Mengirimkan banyaknya elemen efektif ArrMap */
/* Mengirimkan nol jika ArrMap kosong */
    return Neff(ArrMap);
}

/* *** Daya tampung container *** */
int MaxNbElArrMap(ArrayMap ArrMap)
{
/* Mengirimkan maksimum elemen yang dapat ditampung oleh ArrMap */
/* *** Selektor INDEKS *** */
    return LastIdxArrMap - FirstIdxArrMap + 1;
}


/* *** Selektor INDEKS *** */
IdxArrMap GetFirstIdxArrMap(ArrayMap ArrMap)
{
/* Prekondisi : ArrMap tidak kosong */
/* Mengirimkan indeks first element ArrMap */
    return FirstIdxArrMap;
}

IdxArrMap GetLastIdxArrMap(ArrayMap ArrMap)
{
/* Prekondisi : ArrMap tidak kosong */
/* Mengirimkan indeks last element ArrMap */
/* *** Menghasilkan sebuah elemen *** */
    return Neff(ArrMap) - 1;
}

ElTypeArrMap GetElmtArrMap(ArrayMap ArrMap, IdxArrMap j)
{
/* Prekondisi : ArrayMap tidak kosong, i antara FirstIdx(ArrMap)..LastIdx(ArrMap) */
/* Mengirimkan elemen ArrMap yang ke-j */

    return TI(ArrMap)[j];
}

/* *** Selektor SET : Mengubah nilai Array Map dan elemen Array Map *** */
/* Untuk type private/limited private pada bahasa tertentu */

void SetTabArrMap(ArrayMap ArrMapin, ArrayMap *ArrMapout)
{
/* I.S. ArrMapin terdefinisi, sembarang */
/* F.S. ArrMapout berisi salinan ArrMapin */
/* Assignment ArrMapHsl -> ArrMapin */
    Neff(*ArrMapout) = Neff(ArrMapin);
    for (int i = 0; i < Neff(ArrMapin); i++)
    {
        TI(*ArrMapout)[i] = TI(ArrMapin)[i];
    }
}

void SetElArrMap(ArrayMap *ArrMap, IdxArrMap j, ElTypeArrMap M)
{
/* I.S. ArrMap terdefinisi, sembarang */
/* F.S. Elemen ArrMap yang ke-j bernilai M */
/* Mengeset nilai elemen Array Map yang ke-j sehingga bernilai M */
    TI(*ArrMap)[j] = M;
    if (j == Neff(*ArrMap))
    {
        Neff(*ArrMap)++;
    }
}

void SetNeffArrMap(ArrayMap *ArrMap, IdxArrMap j)
{
/* I.S. ArrMap terdefinisi, sembarang */
/* F.S. indeks efektif ArrMap bernilai j */
/* Mengset nilai indeks elemen efektif sehingga bernilai j */
    Neff(*ArrMap) = j;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrMap(ArrayMap ArrMap, IdxArrMap j)
{
/* Prekondisi : j sembarang */
/* Mengirimkan true jika j adalah indeks yang valid utk ukuran ArrMap */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (j >= FirstIdxArrMap && j <= LastIdxArrMap);
}

boolean IsIdxEffArrMap(ArrayMap ArrMap, IdxArrMap i)
{
/* Prekondisi : j sembarang*/
/* Mengirimkan true jika j adalah indeks yang terdefinisi utk ArrMap yaitu antara FirstIdx(ArrMap)..LastIdx(ArrMap) */
    return (i >= FirstIdxArrMap && i <= Neff(ArrMap) - 1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test Array Map kosong *** */
boolean IsEmptyArrMap(ArrayMap ArrMap)
{
/* Mengirimkan true jika ArrMap kosong, mengirimkan false jika ArrMap Tidak kosong */
    return (Neff(ArrMap) == 0);
}

/* *** Test Array Map penuh *** */
boolean IsFullArrMap(ArrayMap ArrMap)
{
/* Mengirimkan true jika ArrMap penuh, mengirimkan false jika ArrMap Tidak Penuh */
    return (Neff(ArrMap) == MaxNbElArrMap(ArrMap));
}

void InsertMapFirst(ArrayMap *ArrMap, ElTypeArrMap M)
{
/* I.S. ArrMap terdefinisi, mungkin kosong. */
/* F.S. M menjadi first element ArrMap. */
/* Jika ArrMap penuh, maka ArrMap tetap penuh. */
    if (IsFullArrMap(*ArrMap))
    {
        printf("Array Map penuh\n");
    }
    else
    {
        for (int i = Neff(*ArrMap); i > 0; i--)
        {
            TI(*ArrMap)[i] = TI(*ArrMap)[i - 1];
        }
        TI(*ArrMap)[0] = M;
        Neff(*ArrMap)++;
    }
}

void InsertMapAt(ArrayMap *ArrMap, ElTypeArrMap M, IdxArrMap j)
{
/* I.S. ArrMap terdefinisi, tidak kosong, j merupakan indeks lojik yang valid di ArrMap. */
/* F.S. M disisipkan dalam ArrMap pada indeks ke-j (bukan menimpa elemen di j). */
/* Jika ArrMap penuh, maka ArrMap tetap penuh. */
    if (IsFullArrMap(*ArrMap))
    {
        printf("Array Map penuh\n");
    }
    else
    {
        for (int i = Neff(*ArrMap); i > j; i--)
        {
            TI(*ArrMap)[i] = TI(*ArrMap)[i - 1];
        }
        TI(*ArrMap)[j] = M;
        Neff(*ArrMap)++;
    }
}

void InsertMapLast(ArrayMap *ArrMap, ElTypeArrMap M)
{
/* I.S. ArrMap terdefinisi, mungkin kosong. */
/* F.S. M menjadi last element ArrMap. */
/* Jika ArrMap penuh, maka ArrMap tetap penuh. */
    if (IsFullArrMap(*ArrMap))
    {
        printf("Array Map penuh\n");
    }
    else
    {
        int index = NbElmtArrMap(*ArrMap);
        (*ArrMap).ElArrMap[index] = M;
        Neff(*ArrMap)++;
    }
}

void DeleteMapFirst(ArrayMap *ArrMap)
{
/* I.S. ArrMap terdefinisi, tidak kosong. */
/* F.S. first element ArrMap dihapus dari ArrMap. */
    if (IsEmptyArrMap(*ArrMap))
    {
        printf("Array Map kosong\n");
    }
    else
    {
        for (int i = 0; i < Neff(*ArrMap) - 1; i++)
        {
            TI(*ArrMap)[i] = TI(*ArrMap)[i + 1];
        }
        Neff(*ArrMap)--;
    }
}

void DeleteMapAt(ArrayMap *ArrMap, IdxArrMap j)
{
/* I.S. ArrMap terdefinisi, tidak kosong,j merupakan indeks lojik yang valid di ArrMap. */
/* F.S. Elemen ArrMap pada indeks ke-j dihapus dari ArrMap. */
    if (IsEmptyArrMap(*ArrMap))
    {
        printf("Array Map kosong\n");
    }
    else
    {
        for (int i = j; i < Neff(*ArrMap) - 1; i++)
        {
            TI(*ArrMap)[i] = TI(*ArrMap)[i + 1];
        }
        Neff(*ArrMap)--;
    }
}

void DeleteMapLast(ArrayMap *ArrMap)
{
/* I.S. ArrMap terdefinisi, tidak kosong. */
/* F.S. last element ArrMap dihapus dari ArrMap. */
    if (IsEmptyArrMap(*ArrMap))
    {
        printf("Array Map kosong\n");
    }
    else
    {
        Neff(*ArrMap)--;
    }
}