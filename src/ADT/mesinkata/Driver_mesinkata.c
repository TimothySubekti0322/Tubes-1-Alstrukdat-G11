#include "mesinkata.h"
#include <stdio.h>

int main()
{
    printf("Memulai membaca file mesinkata.txt\n");
    STARTFILE("mesinkata.txt");
    printf("Kata pertama dari mesinkata.txt adalah \"");
    int i = 0;
    int j = CWord.Length;
    while (i < j)
    {
        printf("%c",CWord.TabWord[i]);
        i++;
    }
    printf("\" dengan panjang %d\n",j);
    printf("ADVLINEFILE\n");
    ADVLINEFILE();
    printf("Kata kedua dari mesinkata.txt adalah \"");
    i = 0;
    j = CWord.Length;
    while (i < j)
    {
        printf("%c",CWord.TabWord[i]);
        i++;
    }
    printf("\"\n");
    printf("Maju dengan ADVWORD , maka perlu IgnoreNewLine\n");
    IgnoreNewLine();
    ADVWORD();
    printf("Kata ketiga dari mesinkata.txt adalah \"");
    i = 0;
    j = CWord.Length;
    while (i < j)
    {
        printf("%c",CWord.TabWord[i]);
        i++;
    }
    printf("\"\n");
    printf("CC berada pada MARK \".\" dan kemudian diikuti dengan Blanks , maka perlu IgnoreDot dan IgnoreBlanks\n");
    IgnoreDot();
    IgnoreBlanks();
    printf("ADVLINE\n");
    ADVLINE();
    printf("Kata keempat dari mesinkata.txt adalah \"");
    i = 0;
    j = CWord.Length;
    while (i < j)
    {
        printf("%c",CWord.TabWord[i]);
        i++;
    }
    printf("\"\n");
    ADVLINEFILE();
    printf("Kata kelima dari mesinkata.txt adalah \"");
    i = 0;
    j = CWord.Length;
    while (i < j)
    {
        printf("%c",CWord.TabWord[i]);
        i++;
    }
    printf("\"\n");
    printf("The End\n");
    
    printf("===============================================================\n");

    printf("Masukan Nama Anda : ");
    INPUT();
    printf("Halo Selamat Datang ");
    i = 0;
    j = CWord.Length;
    while (i < j)
    {
        printf("%c",CWord.TabWord[i]);
        i++;
    }
    printf("\n");
    
}