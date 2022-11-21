#include "stackint.h"
#include <stdio.h>

int main()
{
    StackInt S;
    printf("Membuat StackInt kosong.\n");
    CreateEmptyStackInt(&S);
    printf("StackInt kosong berhasil dibuat.\n");
    printf("\nApakah StackInt kosong?\n");

    if (IsStackIntEmpty(S)) // Pengetesan fungsi IsStackIntEmpty
    {
        printf("StackInt kosong\n");
    }
    else
    {
        printf("StackInt tidak kosong\n");
    }

    printf("\nApakah StackInt penuh?\n");
    if (IsStackIntFull(S)) // Pengetesan fungsi IsStackIntFull
    {
        printf("StackInt penuh\n");
    }
    else
    {
        printf("StackInt tidak penuh\n");
    }

    // Keperluan pembatas tes
    int i = 1;
    while (i < 50)
    {
        printf("=");
        i++;
    }
    printf("=\n");

    // Pengetesan fungsi PushStackInt
    printf("\nMenambahkan elemen ke StackInt\n");
    PushStackInt(&S, 2);
    PushStackInt(&S, 14);
    PushStackInt(&S, 30);
    PushStackInt(&S, 61);
    PushStackInt(&S, 72);
    PushStackInt(&S, 193);
    printf("Penambahan elemen berhasil.\n");

    // Melihat elemen TOP dari StackInt
    printf("Elemen teratas dari StackInt : %d\n", InfoTop(S));

    // Pengetesan fungsi PopStackInt
    printf("\nMenghapus elemen dari StackInt\n");
    infotype d, e, f;
    PopStackInt(&S, &d);
    PopStackInt(&S, &e);
    PopStackInt(&S, &f);
    printf("Penghapusan elemen berhasil.\n");

    // Melihat elemen TOP dari StackInt
    printf("Elemen teratas dari StackInt : %d\n", InfoTop(S));

    return 0;
}