#include "../../boolean.h"
#include "map.h"

#ifndef ARRAY_MAP_
#define ARRAY_MAP_

/* Kamus Umum */

#define UndefIdxArrMap -999 /* indeks tak terdefinisi*/
#define LastIdxArrMap 99
#define FirstIdxArrMap 0

/* Definisi elemen dan koleksi objek */
typedef int IdxArrMap;
typedef Map ElTypeArrMap;

typedef struct
{
    Map ElArrMap[LastIdxArrMap - FirstIdxArrMap + 1];  /* memori tempat penyimpan elemen (container) */
    int NeffArrMap;                                    /* banyaknya elemen efektif */
} ArrayMap;

/* Pendefinisian fungsi makro untuk mempermudah pengaksesan Stack */
#define Neff(ArrMap) (ArrMap).NeffArrMap
#define TI(ArrMap) (ArrMap).ElArrMap

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Array Map kosong */
void MakeEmptyArrMap(ArrayMap *ArrMap);
/* I.S. sembarang */
/* F.S. Terbentuk ArrMap kosong dengan kapasitas LastIdxArrMap-FirstIdxArrMap+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(ArrayMap ArrMap);
/* Mengirimkan banyaknya elemen efektif ArrMap */
/* Mengirimkan nol jika ArrMap kosong */

/* *** Daya tampung container *** */
int MaxNbElArrMap(ArrayMap ArrMap);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh ArrMap */
/* *** Selektor INDEKS *** */

IdxArrMap GetFirstIdxArrMap(ArrayMap ArrMap);
/* Prekondisi : ArrMap tidak kosong */
/* Mengirimkan indeks first element ArrMap */

IdxArrMap GetLastIdxArrMap(ArrayMap ArrMap);
/* Prekondisi : ArrMap tidak kosong */
/* Mengirimkan indeks last element ArrMap */
/* *** Menghasilkan sebuah elemen *** */

ElTypeArrMap GetElmtArrMap(ArrayMap ArrMap, IdxArrMap j);
/* Prekondisi : ArrayMap tidak kosong, i antara FirstIdx(ArrMap)..LastIdx(ArrMap) */
/* Mengirimkan elemen ArrMap yang ke-j */

/* *** Selektor SET : Mengubah nilai Array Map dan elemen Array Map *** */
void SetTabArrMap(ArrayMap ArrMapin, ArrayMap *ArrMapout);
/* I.S. ArrMapin terdefinisi, sembarang */
/* F.S. ArrMapout berisi salinan ArrMapin */
/* Assignment ArrMapHsl -> ArrMapin */

void SetElArrMap(ArrayMap *ArrMap, IdxArrMap j, ElTypeArrMap M);
/* I.S. ArrMap terdefinisi, sembarang */
/* F.S. Elemen ArrMap yang ke-j bernilai M */
/* Mengeset nilai elemen Array Map yang ke-j sehingga bernilai M */

void SetNeffArrMap(ArrayMap *ArrMap, IdxArrMap j);
/* I.S. ArrMap terdefinisi, sembarang */
/* F.S. indeks efektif ArrMap bernilai j */
/* Mengset nilai indeks elemen efektif sehingga bernilai j */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrMap(ArrayMap ArrMap, IdxArrMap j);
/* Prekondisi : j sembarang */
/* Mengirimkan true jika j adalah indeks yang valid utk ukuran ArrMap */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEffArrMap(ArrayMap ArrMap, IdxArrMap i);
/* Prekondisi : j sembarang*/
/* Mengirimkan true jika j adalah indeks yang terdefinisi utk ArrMap yaitu antara FirstIdx(ArrMap)..LastIdx(ArrMap) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test Array Map kosong *** */
boolean IsEmptyArrMap(ArrayMap ArrMap);
/* Mengirimkan true jika ArrMap kosong, mengirimkan false jika ArrMap Tidak kosong */

/* *** Test Array Map penuh *** */
boolean IsFullArrMap(ArrayMap ArrMap);
/* Mengirimkan true jika ArrMap penuh, mengirimkan false jika ArrMap Tidak Penuh */

void InsertFirst(ArrayMap *ArrMap, ElTypeArrMap M);
/* I.S. ArrMap terdefinisi, mungkin kosong. */
/* F.S. M menjadi first element ArrMap. */

void InsertAt(ArrayMap *ArrMap, ElTypeArrMap M, IdxArrMap j);
/* I.S. ArrMap terdefinisi, tidak kosong, j merupakan indeks lojik yang valid di ArrMap. */
/* F.S. M disisipkan dalam ArrMap pada indeks ke-j (bukan menimpa elemen di j). */

void InsertLast(ArrayMap *ArrMap, ElTypeArrMap M);
/* I.S. ArrMap terdefinisi, mungkin kosong. */
/* F.S. M menjadi last element ArrMap. */

void DeleteFirst(ArrayMap *ArrMap);
/* I.S. ArrMap terdefinisi, tidak kosong. */
/* F.S. first element ArrMap dihapus dari ArrMap. */

void DeleteAt(ArrayMap *ArrMap, IdxArrMap j);
/* I.S. ArrMap terdefinisi, tidak kosong,j merupakan indeks lojik yang valid di ArrMap. */
/* F.S. Elemen ArrMap pada indeks ke-j dihapus dari ArrMap. */

void DeleteLast(ArrayMap *ArrMap);
/* I.S. ArrMap terdefinisi, tidak kosong. */
/* F.S. last element ArrMap dihapus dari ArrMap. */
#endif