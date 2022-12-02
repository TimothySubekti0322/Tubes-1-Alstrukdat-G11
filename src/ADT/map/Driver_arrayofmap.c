#include <stdio.h>
#include <stdlib.h>
#include "arrayofmap.h"

int main()
{
    ArrayMap ArrMap;
    MakeEmptyArrMap(&ArrMap);
    printf("Banyaknya Element Efektif %d\n", NbElmtArrMap(ArrMap));
    printf("Banyaknya Element Maksimum %d\n", MaxNbElArrMap(ArrMap));
    printf("Apakah Array Map Kosong ?\n");
    if(IsEmptyArrMap(ArrMap))
    {
        printf("Ya\n");
    }
    else
    {
        printf("Tidak\n");
    }

    printf("Apakah Array Map Penuh ?\n");
    if(IsFullArrMap(ArrMap))
    {
        printf("Ya\n");
    }
    else
    {
        printf("Tidak\n");
    }

    printf("Indeks First Element %d\n", GetFirstIdxArrMap(ArrMap));
    printf("Indeks Last Element dari Array kosong = %d\n", GetLastIdxArrMap(ArrMap));

    Map M1;
    CreateEmpty(&M1);
    Insert(&M1, "A", 1);

    Map M2;
    CreateEmpty(&M2);
    Insert(&M2, "B", 2);

    Map M3;
    CreateEmpty(&M3);
    Insert(&M3, "C", 3);

    InsertFirst(&ArrMap, M1);
    InsertLast(&ArrMap, M3);
    InsertAt(&ArrMap, M2, 1);

    int indeks;
    printf("Masukan indeks yang ingin diakses : ");
    scanf("%d", &indeks);

    if(IsIdxValidArrMap(ArrMap,indeks))
    {
        printf("Indeks yang anda masukan valid\n");
        if(IsIdxEffArrMap(ArrMap,indeks))
        {
            printf("Indeks yang anda masukan efektif\n");
            printf("Value pertama dari Elemen pada indeks %d adalah %s\n", indeks, GetElmtArrMap(ArrMap,indeks).Elements[0].Key);
        }
        else
        {
            printf("Indeks yang anda masukan tidak efektif\n");
        }
    }
    else
    {
        printf("Indeks yang anda masukan tidak valid\n");
    }

    Map M4;
    CreateEmpty(&M4);
    Insert(&M4, "D", 4);

    printf("Memasukan Map baru pada indeks 4\n");
    SetElArrMap(&ArrMap, 4 , M4);

    printf("Key Elemen pertama pada Map Index 4 adalah %s\n", GetElmtArrMap(ArrMap,4).Elements[0].Key);

    ArrayMap arrmap2;
    MakeEmptyArrMap(&arrmap2);
    SetTabArrMap(ArrMap, &arrmap2);

    printf("Banyaknya Element Efektif %d\n", NbElmtArrMap(arrmap2));
    printf("Ubah banyak element efektif menjadi 2\n");

    SetNeffArrMap(&arrmap2, 2);

    printf("Banyaknya Element Efektif arraymap 2 adalah %d\n", NbElmtArrMap(arrmap2));

    printf("\n===========================================================================================================\n");

    printf("\nTesting Delete\n");

    ArrayMap arrmap3;
    MakeEmptyArrMap(&arrmap3);
    SetTabArrMap(ArrMap, &arrmap3);

    printf("Banyaknya Element Efektif Array Map 3 adalah %d\n", NbElmtArrMap(arrmap3));

    printf("Delete Elemen indeks 1\n");
    DeleteAt(&arrmap3, 1);

    printf("Delete Elemen indeks 0\n");
    DeleteFirst(&arrmap3);

    printf("Delete Elemen indeks terakhir dari Neff\n");
    DeleteLast(&arrmap3);

    printf("Banyaknya Element Efektif Array Map 3 Sekarang adalah %d\n", NbElmtArrMap(arrmap3));

    return 0;
}