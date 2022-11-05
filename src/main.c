#include <stdio.h>
#include <stdlib.h>

#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
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

int main(){
    welcome();
    
}