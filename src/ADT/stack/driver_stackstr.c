#include "stackstr.h"
#include <stdio.h>

int main ()
{
    StackStr S;
    printf("Membuat StackStr kosong.\n");
    CreateEmptyStackStr(&S);
    printf("StackStr kosong berhasil dibuat.\n");
    printf("\nApakah StackStr kosong?\n");

    if (IsStackStrEmpty(S)) // Pengetesan fungsi IsStackStrEmpty
    {
        printf("StackStr kosong\n");
    }
    else
    {
        printf("StackStr tidak kosong\n");
    }

    printf("\nApakah StackStr penuh?\n");
    if (IsStackStrFull(S)) // Pengetesan fungsi IsStackStrFull
    {
        printf("StackStr penuh\n");
    }
    else
    {
        printf("StackStr tidak penuh\n");
    }

    // Keperluan pembatas tes
    int i = 1;
    while (i < 50) 
    {
        printf("=");
        i++;
    }
    printf("=\n");

    // Pengetesan fungsi PushStackStr
    printf("\nMenambahkan elemen ke StackStr\n");
    PushStackStr(&S, "It's me");
    PushStackStr(&S, "Hi");
    PushStackStr(&S, "I'm the problem");
    PushStackStr(&S, "It's me");
    PushStackStr(&S, "At tea time");
    PushStackStr(&S, "Everybody agrees");
    printf("Penambahan elemen berhasil.\n");

    // Melihat elemen TOP dari StackStr
    printf("Elemen teratas dari StackStr : %s\n", INFOTop(S));

    // Pengetesan fungsi PopStackStr
    printf("\nMenghapus elemen dari StackStr\n");
    strtype a, b, c;
    PopStackStr(&S, &a);
    PopStackStr(&S, &b);
    PopStackStr(&S, &c);
    printf("Penghapusan elemen berhasil.\n");

    // Melihat elemen TOP dari StackStr
    printf("Elemen teratas dari StackStr : %s\n", INFOTop(S));

    return 0;
}