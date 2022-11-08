#include <stdio.h>
#include <stdlib.h>

#include "console.h"


void welcome(){
    char *screen =
     "██████  ███    ██ ███    ███  ██████ \n"
     "██   ██ ████   ██ ████  ████ ██    ██  \n"
     "██████  ██ ██  ██ ██ ████ ██ ██    ██ \n"
     "██   ██ ██  ██ ██ ██  ██  ██ ██    ██ \n"
     "██████  ██   ████ ██      ██  ██████ ' \n";
     

     char *text =
     "WELCOME TO BNMO <33\n"
     "START :: MAININ BNMO DONG SAYANG\n"
     "LOAD  :: LOAD GAME YANG TERSEDIA YUK SAYANG\n";


     printf("%s",screen);
     printf(" \n");
     printf("============================================================================================================================\n");
     printf(" \n");
     printf("%s",text);
}

int main()
{
    ArrayDyn ArrayGame;
    Queue QueueGame;
    ArrayGame = MakeArrayDin();
    CreateQueue(&QueueGame);
    boolean endProgram = false;

    /* Display Main menu */
    welcome();
    while (!endProgram)
    {
        printf("\nENTER COMMAND: ");
        INPUT();
        //printf("%s\n", CWord);
        //ADVCommand();
        //printf("%s\n", CWord);
        
        /* Belum Start / Load */
        if (IsEmpty(ArrayGame))
        {
            /* Command START*/
            if (IsKataSama(CWord, StringtoWord("START")))
            {
                STARTBNMO(&ArrayGame);
            }

            /* Command LOAD */
            else if ((CWord[0] == 'L') && (CWord[1] == 'O') && (CWord[2] == 'A') && (Cword[3] == 'D'))
            {
                char inputfile[50];
                CopyWordtostring(CWord, inputfile, 5 , CWord.Length-1);
                LOADFILE(&ArrayGame,inputfile);
                // printf("%s", CWord);
                //printf("%s", inputfile);
            }

            /* Command HELP*/
            else if (IsKataSama(CWord,StringtoWord("HELP")))
            {
                HELP();
            }

            /* Command lain*/
            else
            {
               printf("Program belum memiliki file konfigurasi\n");
               printf("Silakan load file dengan command LOAD <filename>\n"); 
            }
        }

        /* Sudah Start / Load */
        else
        {
            if (IsKataSama(CWord,StringtoWord("CREATE GAME")))
            {
                    /* Memanggil function Create Game*/
            }
            else if (IsKataSama(CWord, StringtoWord("LIST GAME")))
            {
                LISTGAME(ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("DELETE GAME")))
            {
                DELETEGAME(&ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("QUEUE GAME")))
            {
                /* Memanggil function Queue Game */
            }
            else if (IsKataSama(CWord, StringtoWord("PLAY GAME")))
            {
                /* Memanggil function Play Game */
            }
            else if ((CWord[0] == 'S') && (CWord[1] == 'K') && (CWord[2] == 'I') && (Cword[3] == 'P') && (Cword[4] == 'G') && (Cword[5] == 'A')&& (Cword[6] == 'M') && (Cword[7] == 'E'))
            {
                /* Memanggil function Skip Game */
            }

            else if (IsKataSama(CWord, StringtoWord("HELP")))
            {
                HELP();
            }

            else if ((CWord[0] == 'S') && (CWord[1] == 'A') && (CWord[2] == 'V') && (Cword[3] == 'E'))
            {

                /* Memanggil Fungsi Save*/


                //ADVCommand();
                //char filename[50];
                //wordtoString(CWord, filename);                
                //SAVE(&ArrayGame, filename);
            }

            else if (IsKataSama(CWord, StringtoWord("QUIT")))
                {
                    QUIT(endProgram);
                    printf("Anda keluar dari game BNMO.\n");
                    printf("Bye bye ...\n");
                    /* Memanggil Fungsi Quit*/
                }

            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
    }

}