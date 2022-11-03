#include <stdio.h>
#include <stdlib.h>
#include "ADT/mesinkata.h"

void concat(char *string1, char *string2, char *string3)
{
    /* I.S : string1 , string2 , dan string3 terdefinisi, string3 kosong
       F.S : string 3 berisi Gabungan dari element string1 dan element string2*/
    
    int i = 0;
    int j = 0;

    while (*(string1 + i) != '\0') {
        *(string3 + j) = *(string1 + i);
        i++;
        j++;
    }

    i = 0;
    while (*(string2 + i) != '\0') {
        *(string3 + j) = *(string2 + i);
        i++;
        j++;
    }
    *(string3 + j) = '\0';
}

void LOADFILE(ArrayDin *Games, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    char string[50];
    char *temp;
    int i;
    int amount;
    int arrayNumber = 0;

    START(directory);
    if (pita == NULL)
    {
        printf("File tidak dapat dibuka. Silahkan masukkan nama file lain.\n");
    }
    else
    {
        fclose(pita);
        STARTWORD(directory, 1);
        wordToString(currentWord, string);
        amount = atoi(string);
        ADVWORD(1);
        for (int j = 0; j < amount; j++)
        {
            wordToString(currentWord, string);
            temp = (char *) malloc (currentWord.Length * sizeof(char));
            i = 0;
            while (i <= currentWord.Length)
            {
                temp[i] = string[i];
                i++;
            }
            InsertLast(Games, temp);
            ADVWORD(1);
        }
        if (directory == "config.txt")
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }   
    }
}