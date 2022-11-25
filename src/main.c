#include <stdio.h>
#include <stdlib.h>

#include "console.h"


void welcome(){
    char *screen =  
    ".______   .__   __. .___  ___.   ______   \n" 
    "|   _  \\  |  \\ |  | |   \\/   |  /  __  \\  \n"
    "|  |_)  | |   \\|  | |  \\  /  | |  |  |  |\n"
    "|   _  <  |  . `  | |  |\\/|  | |  |  |  |\n"
    "|  |_)  | |  |\\   | |  |  |  | |  `--'  | \n"
    "|______/  |__| \\__| |__|  |__|  \\______/\n";
     

     char *text =
     "WELCOME TO BNMO <33\n"
     "START :: MAININ BNMO DONG SAYANG\n"
     "LOAD  :: LOAD GAME YANG TERSEDIA YUK SAYANG\n"
     "HELP  :: BUTUH BANTUAN SAYANG\n"
     "QUIT  :: JANGAN KELUAR SAYANG T_T\n";


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
    ArrayMap MapGame;
    StackStr History;
    ArrayGame = CreateStrArrayDyn();
    MakeEmptyArrMap(&MapGame);
    CreateEmptyStackStr(&History);
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
                STARTBNMO(&ArrayGame,&MapGame);
                //LOADFILE(&ArrayGame,"config.txt");
                // ShowStrArrayDyn(ArrayGame);
                // printf("%d",ArrayGame.Neff);
            }

            /* Command LOAD */
            else if ((CWord.TabWord[0] == 'L') && (CWord.TabWord[1] == 'O') && (CWord.TabWord[2] == 'A') && (CWord.TabWord[3] == 'D'))
            {
                char inputfile[50];
                CopyWordtostring(CWord, inputfile, 5 , CWord.Length-1);
                LOADFILE(&ArrayGame,inputfile,&MapGame,&History);
                // printf("%s", CWord);
                //printf("%s", inputfile);
            }

            /* Command HELP*/
            else if (IsKataSama(CWord,StringtoWord("HELP")))
            {
                HELP();
            }

            else if (IsKataSama(CWord, StringtoWord("QUIT")))
            {
                endProgram = true;
                printf("Anda keluar dari game BNMO.\n");
                printf("Bye bye ...\n");
                /* Memanggil Fungsi Quit*/
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
                CreateGame(&ArrayGame, &MapGame);
            }
            else if (IsKataSama(CWord, StringtoWord("LIST GAME")))
            {
                LISTGAME(ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("DELETE GAME")))
            {
                DELETEGAME(&ArrayGame,&QueueGame,&MapGame);
            }
            else if (IsKataSama(CWord, StringtoWord("QUEUE GAME")))
            {
                QUEUEGAME(&QueueGame, ArrayGame);
            }
            else if (IsKataSama(CWord, StringtoWord("PLAY GAME")))
            {
                PlayGame(&QueueGame, &History,&MapGame , ArrayGame);
            }
            else if ((CWord.TabWord[0] == 'S') && (CWord.TabWord[1] == 'K') && (CWord.TabWord[2] == 'I') && (CWord.TabWord[3] == 'P') && (CWord.TabWord[4] == 'G') && (CWord.TabWord[5] == 'A')&& (CWord.TabWord[6] == 'M') && (CWord.TabWord[7] == 'E') && (CWord.TabWord[8] == ' '))
            {
                int number = CWord.TabWord[9] - '0';
                SkipGame(&QueueGame,number,&MapGame , ArrayGame , &History);
            }

            /* SKIP GAME jika spasi adalah valid*/
            else if ((CWord.TabWord[0] == 'S') && (CWord.TabWord[1] == 'K') && (CWord.TabWord[2] == 'I') && (CWord.TabWord[3] == 'P') && (CWord.TabWord[4] == ' ') && (CWord.TabWord[5] == 'G')&& (CWord.TabWord[6] == 'A') && (CWord.TabWord[7] == 'M') && (CWord.TabWord[8] == 'E') && (CWord.TabWord[9] == ' '))
            {
                int number = CWord.TabWord[10] - '0';
                SkipGame(&QueueGame,number,&MapGame , ArrayGame , &History);
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
                Save(ArrayGame , inputfiles , History , MapGame);

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
            else if (IsKataSama(CWord, StringtoWord("SCOREBOARD")))
            {
                SCOREBOARD(ArrayGame,MapGame);
            }
            else if (IsKataSama(CWord, StringtoWord("RESET SCOREBOARD")))
            {
                RESETSCOREBOARD(ArrayGame,&MapGame);
            }

            else if (IsKataSama(CWord, StringtoWord("HISTORY")))
            {
                int n = History.TOP + 1;
                HISTORY(History,n);
            }

            else if ((CWord.TabWord[0] == 'H') && (CWord.TabWord[1] == 'I') && (CWord.TabWord[2] == 'S') && (CWord.TabWord[3] == 'T') && (CWord.TabWord[4] == 'O') && (CWord.TabWord[5] == 'R')&& (CWord.TabWord[6] == 'Y') && (CWord.TabWord[7] == ' '))
            {
                char *x;
                x = (char *) malloc(sizeof(char));
                CopyWordtostring(CWord,x,8,CWord.Length-1);
                int n = 0; 
                n = StringtoInt(x);
                HISTORY(History,n);
            }
            else if (IsKataSama(CWord, StringtoWord("RESET HISTORY")))
            {
                RESETHISTORY(&History);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
    }

}