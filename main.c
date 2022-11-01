#include <stdio.h>
#include "boolean.h"
#include "console.c"
#include <stdlib.h>



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
     printf("===========================================================================================================================================\n");
     printf(" \n");
     printf("%s",text);
}

void menu(){
    char *listmenu =
    "Diliat dan dipilih yuk list menunya yuk sayang\n"
    "1.CREATEGAME :: Buat game untuk dimainin yuk\n"
    "2.LISTGAME :: Cari tahu list game yang ada di BNMO yuk sayang \n"
    "3.DELETEGAME :: hapus game sesuka hati kamu <33\n"
    "4.QUEUEGAME :: Masukin game ke antrian kamu ya\n"
    "5.PLAYGAME :: Mainin game yang ada di list kamu\n"
    "6.SKIPGAME :: skip game yang ga mau kamu mainin ya\n"
    "7.QUIT :: yakin kamu mau keluar??\n"
    "8.HELP :: kalau bingung pilih help yaa\n";
    printf("%s",listmenu);
}

int compare (char *x, char *y){
    int flag = 0;
 
    // Iterate a loop till the end
    // of both the strings
    while ((*x != '\0' || *y != '\0') && flag == 0) {
        if (*x == *y) {
            x++;
            y++;
        }
        else if ((*x == '\0' && *y != '\0')|| (*x != '\0' && *y == '\0')|| *x != *y) {
            flag = 1;
         }
    }
    return flag;
}

int main(){
    char command[20];
    //Menampilkan screen welcome
    welcome();
    printf("Silahkan masukan command sesuai pilihan yang ada di atas\n");
    printf("ENTER COMMAND: ");
    scanf("%s", command);

    boolean commandValid;
    commandValid = false;

    do{
        if (compare(command, "START") == 0){
            //START();
            commandValid = true;
        }
        else if (compare(command, "LOAD") == 0) {
            //LOAD();
            commandValid = true;
        }
        else {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        }
    } while(commandValid == false);



    boolean endBnmo;
    endBnmo = false;
    printf("\n");
    menu();
    printf("\n");
    printf("ENTER COMMAND: ");
    scanf("%s", command);

    do{
        if (compare(command, "CREATEGAME") == 0){
            //CREATEGAME();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        }
        else if (compare(command, "LISTGAME") == 0) {
            //LISTGAME();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
        else if (compare(command, "DELETEGAME") == 0) {
            //DELETEGAME();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
        else if (compare(command, "QUEUEGAME") == 0) {
            //QUEUEGAME();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
        else if (compare(command, "PLAYGAME") == 0) {
            //PLAYGAME();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
        else if (compare(command, "SKIPGAME") == 0) {
            //SKIPGAME();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
        else if (compare(command, "QUIT") == 0) {
            QUIT();
            endBnmo = true;
        } 
        else if (compare(command, "HELP") == 0) {
            //HELP();
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
        else{
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("ENTER COMMAND: ");
            scanf("%s", command);
        } 
    }while(endBnmo == false);
     

}
