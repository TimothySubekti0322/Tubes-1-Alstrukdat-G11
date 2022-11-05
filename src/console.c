#include <stdio.h>
#include <stdlib.h>
#include "console.h"


void STARTBNMO(DynArray *gamesBNMO){
     STARTFILE("config.txt");
    int jumlahGame;
    jumlahGame = atoi(CWord.TabWord);
    ADVLINEFILE();

    int i;
    i = 0;
    while (CC != MARK ){

        int i = 0;
        
        while (i < jumlahGame){
            char *namaGame;
            namaGame = (char*) malloc(CWord.Length * sizeof (char));

            int k = 0;
            while (k < CWord.Length){
                namaGame[k] = CWord.TabWord[k];
                k = k+1;
            }
            InsertLast(gamesBNMO, namaGame);
            i = i +1;
            ADVLINEFILE();
        }

    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

boolean IsKataSama(Word InputCommand, Word Command)
{
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

    boolean sama = true;
    if (InputCommand.Length != Command.Length) {
        return (!sama);
    } else {
        int i = 0;
        while (sama && (i < Command.Length)) {
            if (InputCommand.TabWord[i] != Command.TabWord[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

void PrintWord(Word CWord)
{
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */
   for (int i = 0 ; i < CWord.Length ; i++)
   {
    printf("%c",CWord.TabWord[i]);
   }
   printf("\n");
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        *(string + i) = currentWord.TabWord[i];
        i++;
    }
    *(string + i) = '\0';
}

boolean CompareString(char *string1 , char *string2)
{
    boolean equal = true;
    int i = 0;
    while ((*(string1 + i) != '\0') && (*(string2 + i) != '\0') && equal)
    {
        if (*(string1 + i) != *(string2 + i))
        {
            equal = false;
        }
        else
        {
        i++;
        }
    }
}


void PrintString(char *string)
{
    /* Mencetak string
       I.S : String terdefinisi
       F.S : string tercetak ke layar */
    int i = 0;
    while(*(string + i) != '\0')
    {
        printf("%c", *(string + i));
        i++;
    }
    printf("\n");
}

int stringLength (char* string) 
/* Mengirimkan panjang sebuah string */
{
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

Word StringtoWord(char* command) 
/* Mengirimkan kata yang elemen of arraynya berasal dari command */
{
    int i;
    Word output;
    for (i = 0; i < stringLength(command); i++) {
        output.TabWord[i] = command[i];
    }
    output.Length = stringLength(command);
    return output;
}

int StringtoInt(char* string)
{
    /* Mengubah sebuah string menjadi integer*/
    int i = 0;
    int hasil = 0;
    while(*(string + i) != '\0')
    {
        hasil = hasil*10 + (*(string+i) - '0');
        i++;
    }
    return hasil;
}

void concat(char *string1, char *string2, char *string3)
{
    /* Menggabungkan string 1 dan string 2
   I.S : string 1, string2 , dan string3 terdefinisi ; string 3 kosong
   F.S : string3 berisi gabungan dari string1 dan string2*/
    int i = 0;
    int j = 0;

    while (string1[i] != '\0') {
        string3[j] = string1[i];
        i++;
        j++;
    }

    i = 0;
    while (string2[i] != '\0') {
        string3[j] = string2[i];
        i++;
        j++;
    }
    string3[j] = '\0';
}

void CopyWordtostring(Word Input, char *string, int length)
{
    int i;
    for(i = 0 ; i < length ; i++)
    {
        *(string + i) = Input.TabWord[i];
    }
    *(string + i) = '\0';
}