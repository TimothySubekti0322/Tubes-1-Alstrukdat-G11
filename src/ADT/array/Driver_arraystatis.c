#include "arraystatis.h"
#include <stdio.h>

int main()
{
    printf("Array Kosong Terbentuk\n");
    StatArray Array = CreateStatArray();
    
    boolean empty = IsEmptyStat(Array);

    printf("Apakah Array kosong ? %d\n",empty);
    if (empty)
    {
        printf("Benar\n");
    }
    else
    {
        printf("Tidak Kosong\n");
    }

    int panjang = LengthStat(Array);
    printf("Panjang Array = %d\n", panjang);

    printf("=============================================================================================\n");

    printf("Memasukan angka 1 - 100 [maksimum size of array]\n");
    for (int j = 0 ; j < Size ; j++)
    {
        InsertLStat(&Array,j+1);
    }

    printf("Array 1 : \n");
    ShowStatArray(Array);

    printf("Element pertama = %d\n", GetStat(Array,0));


    printf("Hapus Element pertama\n");
    DeleteFStat(&Array);
    printf("ELement Pertama = %d\n", GetStat(Array,0));
    
    printf("=============================================================================================\n");

    printf("Membalikan Element pada Array\n");
    ReverseStatArray(&Array);
    printf("Array 1 : \n");
    ShowStatArray(Array);

    printf("=============================================================================================\n");
    printf("Copy 1/2 Element dari array diatas ke array yang lain\n");
    
    StatArray Array2 = CopyStatArray(Array);

    for (int i = 0 ; i < Size/2 ; i++)
    {
        DeleteLStat(&Array2);
    }
    printf("Array 2 : \n");
    ShowStatArray(Array2);

    printf("=============================================================================================\n");
    printf("Posisi Angka 73 di array adalah %d\n",FindStatArray(Array2,73));
    printf("Posisi Angka 30 di array adalah %d\n",FindStatArray(Array2,30));

    return 0;
}