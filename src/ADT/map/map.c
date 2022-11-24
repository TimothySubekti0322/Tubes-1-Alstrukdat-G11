#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "../../console.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
{
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
    (*M).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M)
{
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return (M.Count == Nil);
}

boolean IsFull(Map M)
{
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return (M.Count == MaxEl);
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
{
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    int i = 0;
    boolean found = false;
    valuetype val = Undefined;
    while ((i < M.Count) && (!found))
    {
        if (M.Elements[i].Key == k)
        {
            val = M.Elements[i].Value;
            found = true;
        }
        else
        {
            i++;
        }
    }
    return val;

}

void Insert(Map *M, keytype k, valuetype v)
{
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if(!IsMember(*M,k))
    {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}

void Delete(Map *M, keytype k)
{
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    if(IsMember(*M,k))
    {
        int i = 0;
        int loc = 0;
        boolean found = false;
        while ((i < (*M).Count) && (!found))
        {
            if (CompareString((*M).Elements[i].Key , k))
            {
                loc = i;
                found = true;
            }
            else
            {
                i++;
            }
        }
        for(int j = loc ; j < ((*M).Count - 1); j++)
        {
            (*M).Elements[j] = (*M).Elements[j+1];
        }
        (*M).Count--;
    }
}

boolean IsMember(Map M, keytype k)
{
/* Mengembalikan true jika k adalah member dari M */
    int i = 0;
    boolean found = false;
    while ((i < M.Count) && (!found))
    {
        if (CompareString((M).Elements[i].Key , k))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

void InsertScoreBoard(Map *M, valuetype v)
{
    printf("Masukan Username [maksimal 20 karakter] : ");
    INPUT();
    char *name;
    // name = (char *) malloc (CWord.Length * sizeof(char)); 
    name = wordToString(CWord);
    printf("\n");
    //printf("\n name = %s\n",name);
    while(IsMember(*M,name))
    {
        printf("Username sudah dipakai , silahkan gunakan username lain\n");
        printf("Masukan Username [maksimal 20 karakter] : ");
        INPUT();
        // char *name;
        // name = (char *) malloc (CWord.Length * sizeof(char));
        name = wordToString(CWord);
        //printf("\n name = %s\n",name);
    }
    
    int asci = 175;
    printf("\n%c USERNAME BERHASIL DIDAFTARKAN %c\n", asci , asci);
    
    if(!IsMember(*M,name))
    {
        int i = 0;
        boolean found = false;
        while ((i < M->Count) && (!found))
        {
            if (v > (*M).Elements[i].Value)
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
        int j;
        for(j = M->Count ; j > i ; j--)
        {
            (*M).Elements[j].Key = (*M).Elements[j-1].Key;
            (*M).Elements[j].Value = (*M).Elements[j-1].Value;
        }
        (*M).Elements[i].Key = name;
        (*M).Elements[i].Value = v;
        (*M).Count++;
    }

}