#include "arraydinamikstr.h"
#include "../../console.h"
#include <stdio.h>

int main()
{
    ArrayDyn Array;
    
    printf("Terbentuk Array Kosong\n");
    Array = CreateStrArrayDyn();
    printf("Jika Array Empty , maka Angka 1 tercetak\n");
    if (IsStrEmpty(Array))
    {
        printf("1\n");
    }
    printf("Banyak Elemen Array %d\n",StrLength(Array));
    printf("Besar Kapasitas Array %d\n",GetStrCapacity(Array));

    printf("=======================================================================\n");
    printf("Memasukan \"Timothy\" sebagai element pertama array\n");
    InsertStrFirst(&Array,"Timothy");
    ShowStrArrayDyn(Array);
    printf("Memasukan element \"Ken Azizan\" Sebagai element terakhir array\n");
    InsertStrLast(&Array,"Ken Azizan");
    ShowStrArrayDyn(Array);
    printf("Memasukan \"Ivan\" di tengah tengah \"Timothy\" dan \"Ken Azizan\"\n");
    InsertStrIn(&Array,"Ivan",1);
    ShowStrArrayDyn(Array);

    printf("=======================================================================\n");
    printf("Copy Array pertama ke Array 2\n");
    ArrayDyn Array2 = CopyStrArrayDyn(Array);
    printf("Isi Array 2 : \n");
    ShowStrArrayDyn(Array2);
    printf("Reverse Array :\n");
    ReverseStrArrayDyn(&Array2);
    ShowStrArrayDyn(Array2);
    
    printf("=======================================================================\n");
    printf("Memeriksa Apakah ada \"Shulhan\" dan \"Nicholas\" di Array2 ? Jika tidak ada maka akan ditambahkan di akhir Array 2\n");
    if (FindStrArrayDyn(Array2, "Shulhan") == -1)
    {
        printf("Tidak Ada \"Shulhan\" di Array 2\n");
        InsertStrLast(&Array2,"Shulhan");
        printf("\"Shulhan\" Berhasil ditambahkan ke Array2\n");
    }
    else
    {
        printf("Ada \"Shulhan\" di Array 2\n");
    }
    if (FindStrArrayDyn(Array2, "Nicholas") == -1)
    {
        printf("Tidak Ada \"Nicholas\" di Array 2\n");
        InsertStrLast(&Array2,"Nicholas");
        printf("\"Nicholas\" Berhasil ditambahkan ke Array2\n");
    }
    else
    {
        printf("Ada \"Nicholas\" di Array 2\n");
    }
    ShowStrArrayDyn(Array2);

    printf("=======================================================================\n");
    printf("Array 1 : \n");
    ShowStrArrayDyn(Array);
    printf("Delete Element pertama Array\n");
    DeleteStrFirst(&Array);
    ShowStrArrayDyn(Array);
    printf("Delete Element terakhir Array\n");
    DeleteStrLast(&Array);
    ShowStrArrayDyn(Array);
    printf("Delete Element yang tersisa\n");
    DeleteStrIn(&Array,0);
    ShowStrArrayDyn(Array);
    printf("Dealokasi Array\n");
    DealokasiStrArrayDyn(&Array);
}