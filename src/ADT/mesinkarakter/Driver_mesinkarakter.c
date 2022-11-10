#include "mesinkarakter.h"
#include <stdio.h>

int main ()
{
    printf("Memulai membaca File mesinkarakter.txt dengan fungsi start\n");
    START("mesinkar.txt");
    printf("File Terbaca\n");
    char karakter = GetCC();
    printf("Karakter pertama pada File mesinkara.txt adalah \'%c\'\n",karakter);
    printf("Mencetak kelayar Isi dari mesinkar.txt\n");
    printf("Line pertama tanpa mark :\n");
    while (!IsFeof() && !IsNewline())
    {
        printf("%c",karakter);
        ADVFILE();
        karakter = GetCC();
    }
    printf("\nLine kedua dengan mark :");
    while(!IsEOP())
    {
        printf("%c",karakter);
        ADVSTOPMARK();
        karakter = GetCC();
    }
    printf("\n========================================================\n");
    printf("Mencoba STARTFILE yang Filenya belum terdefinisi\n");
    printf("Memulai membaca file notexist.txt\n");
    START("notexist.txt");
    printf("Pita kosong ?\n");
    if (IsPitaNull())
    {
        printf("Benar\n");
    }
    else
    {
        printf("Salah\n");
    }
    printf("\n========================================================\n");
    printf("Membaca Inputan dari user\n");
    printf("Masukan Nama Anda : ");
    STARTINPUT();
    karakter = GetCC();
    printf("\nHalo , selamat datang ");
    while(!IsFeof() && !IsNewline())
    {
        printf("%c",karakter);
        ADV();
        karakter = GetCC();
    }
}