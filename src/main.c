#include <stdio.h>
#include <stdlib.h>

#include "console.h"


void welcome(){
    char *screen =  
    ".______   .__   __. .___  ___.   ______   \n" 
    "|   _  \  |  \ |  | |   \/   |  /  __  \  \n"
    "|  |_)  | |   \|  | |  \  /  | |  |  |  |\n"
    "|   _  <  |  . `  | |  |\/|  | |  |  |  |\n"
    "|  |_)  | |  |\   | |  |  |  | |  `--'  | \n"
    "|______/  |__| \__| |__|  |__|  \______/\n";
     

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
    QueueStr QueueGame;
    ArrayGame = CreateStrArrayDyn();
    CreateStrQueue(&QueueGame);
    boolean endProgram = false;

    /* Display Main menu */
    welcome();
    while (!endProgram)
    {
        printf("\nENTER COMMAND: ");
        INPUT();
        // printf("%s\n", CWord);
        //ADVCommand();
        //printf("%s\n", CWord);
        
        /* Belum Start / Load */
        if (IsStrEmpty(ArrayGame))
        {
            /* Command START*/
            if (IsKataSama(CWord, StringtoWord("START")))
            {
                STARTBNMO(&ArrayGame);
                //LOADFILE(&ArrayGame,"config.txt");
                // ShowStrArrayDyn(ArrayGame);
                // printf("%d",ArrayGame.Neff);
            }

            /* Command LOAD */
            else if ((CWord.TabWord[0] == 'L') && (CWord.TabWord[1] == 'O') && (CWord.TabWord[2] == 'A') && (CWord.TabWord[3] == 'D'))
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
                CreateGame(&ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("LIST GAME")))
            {
                LISTGAME(ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("DELETE GAME")))
            {
                DELETEGAME(&ArrayGame,&QueueGame);
            }
            else if (IsKataSama(CWord, StringtoWord("QUEUE GAME")))
            {
                QUEUEGAME(&QueueGame, ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("PLAY GAME")))
            {
                PlayGame(&QueueGame);
            }
            else if ((CWord.TabWord[0] == 'S') && (CWord.TabWord[1] == 'K') && (CWord.TabWord[2] == 'I') && (CWord.TabWord[3] == 'P') && (CWord.TabWord[4] == 'G') && (CWord.TabWord[5] == 'A')&& (CWord.TabWord[6] == 'M') && (CWord.TabWord[7] == 'E') && (CWord.TabWord[8] == ' '))
            {
                int number = CWord.TabWord[9] - '0';
                SkipGame(&QueueGame,number);
            }

            else if (IsKataSama(CWord, StringtoWord("HELP")))
            {
                HELP();
            }

            else if ((CWord.TabWord[0] == 'S') && (CWord.TabWord[1] == 'A') && (CWord.TabWord[2] == 'V') && (CWord.TabWord[3] == 'E'))
            {
                char inputfiles[50];
                CopyWordtostring(CWord, inputfiles, 5 , CWord.Length-1);
                //printf("%s",inputfiles);
                Save(ArrayGame, inputfiles);

                //ADVCommand();
                //char filename[50];
                //wordtoString(CWord, filename);                
                //SAVE(&ArrayGame, filename);
            }

            else if (IsKataSama(CWord, StringtoWord("QUIT")))
                {
                    endProgram = true;
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