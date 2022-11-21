#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "../mesinkata/mesinkata.h"

int main()
{
    printf("Membentuk Map Kosong\n");
    Map M;
    CreateEmpty(&M);
    printf("Apakah Map yang terbentuk kosong ?\n");
    if(IsEmpty(M))
    {
        printf("Benar\n");
    }
    else
    {
        printf("Salah\n");
    }
    
    printf("Apakah Map yang terbentuk Penuh ?\n");
    if(IsFull(M))
    {
        printf("Benar\n");
    }
    else
    {
        printf("Salah\n");
    }

    printf("===================================================================================\n");

    printf("Uji Memasukan nilai ke Map\n");
    int n = 0;
    printf("Masukan Jumlah Masukan : ");
    INPUT();
    WordToInt(CWord,&n);
    
    int i = 0;
    while(i < n)
    {
        char name[50];
        char *temp;
        int nilai = 0;

        printf("Masukan Nama Siswa %d [Maksimal 50 character] : ",i+1);
        INPUT();
        CopyWordtostring(CWord, name, 0 , CWord.Length-1);
        temp = (char *) malloc (CWord.Length * sizeof(char));
        int j = 0;
        while (j <= CWord.Length)
        {
            temp[j] = name[j];
            j++;
        }

        printf("Masukan Nilai Siswa %d : ",i+1);
        INPUT();
        WordToInt(CWord,&nilai);
        Insert(&M,temp,nilai);
        i++;
    }

    printf("\nISI MAP ANDA\n");
    printf("[");
    for (int k = 0 ; k < n ; k++)
    {
        printf("(%s : %d)",M.Elements[k].Key, M.Elements[k].Value);
        if(k != (n-1))
        {
            printf(" , ");
        }
    }
    printf("]\n");

    printf("\n===================================================================================\n");

    printf("Uji Menghapus nilai dari Map\n");

    int jumlah_del = 0;
    printf("Masukan Jumlah Masukan : ");
    INPUT();
    WordToInt(CWord,&jumlah_del);

    int indeks = 0;
    int count = 0;
    while (indeks < jumlah_del)
    {
        char Del[50];
        printf("Masukan Nama Siswa yang ingin dihapus dari Map : ");
        INPUT();
        CopyWordtostring(CWord, Del, 0 , CWord.Length-1);
        if (IsMember(M , Del))
        {
            Delete(&M,Del);
            printf("%s berhasil dihapus dari Map\n",Del);
            count++;
        }
        else
        {
            printf("%s Tidak ada di Map\n",Del);
        }
        indeks++;
    }

    printf("\nISI MAP ANDA\n");
    printf("[");
    for (int z = 0 ; z < n - count ; z++)
    {
        printf("(%s : %d)",M.Elements[z].Key, M.Elements[z].Value);
        if(z != (n - count - 1))
        {
            printf(" , ");
        }
    }
    printf("]\n");
}