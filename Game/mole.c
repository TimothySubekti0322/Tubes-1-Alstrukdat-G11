#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include "mole.h"

Board CreateBoard(){
    Board papan;
    papan.a = CreateStrArrayDyn();
    papan.b = CreateStrArrayDyn();
    papan.c = CreateStrArrayDyn();
    papan.d = CreateStrArrayDyn();
    papan.e = CreateStrArrayDyn();
    int i;
    for(i = 0;i<5;i++){
        InsertStrLast(&papan.a,"O");
        InsertStrLast(&papan.b,"O");
        InsertStrLast(&papan.c,"O");
        InsertStrLast(&papan.d,"O");
        InsertStrLast(&papan.e,"O");
    }

    return papan;

}

void randomnumber(int *x,int *y){
    srand(time(NULL));
    *x = rand() % 5 + 1;
    *y = rand() % 5 + 1;
}

void UbahBoard(Board *papan,int x,int y){
    if(y == 1){
        DeleteStrIn(&papan->a,x-1);
        InsertStrIn(&papan->a,"X",x-1);
    } else if (y == 2){
        DeleteStrIn(&papan->b,x-1);
        InsertStrIn(&papan->b,"X",x-1);
    } else if (y == 3){
        DeleteStrIn(&papan->c,x-1);
        InsertStrIn(&papan->c,"X",x-1);
    } else if (y == 4){
        DeleteStrIn(&papan->d,x-1);
        InsertStrIn(&papan->d,"X",x-1);
    } else if (y == 5){
        DeleteStrIn(&papan->e,x-1);
        InsertStrIn(&papan->e,"X",x-1);
    }
}

boolean IsValid(char *coordinates){
    return ((coordinates[0]>='1' && coordinates[0] <= '5') && (coordinates[2]>='1' && coordinates[2] <= '5') && stringLength(coordinates)==3);
}

boolean IsBlankGrid(Board papan,int x,int y){
    if(y == 1){
        char *n = GetStr(papan.a, x-1); 
        return n == "O";
    } else if(y ==2){
        char *n = GetStr(papan.b, x-1); 
        return n == "O";
    } else if(y == 3){
        char *n = GetStr(papan.c, x-1); 
        return n == "O";
    } else if(y ==4){
        char *n = GetStr(papan.d, x-1); 
        return n == "O";
    } else if(y == 5){
        char *n = GetStr(papan.e, x-1); 
        return n == "O";
    }
    return false;
}
int xcoor(char *coordinates){
    return coordinates[0]-48;
}

int ycoor(char *coordinates){
    return coordinates[2]-48;
}

void PrintPapan(Board papan){
    for(int i = 0;i<5;i++){
        printf("%s ",papan.a.Ar[i]);
    }
    printf("\n");
    for(int i = 0;i<5;i++){
        printf("%s ",papan.b.Ar[i]);
    }
    printf("\n");
    for(int i = 0;i<5;i++){
        printf("%s ",papan.c.Ar[i]);
    }
    printf("\n");
    for(int i = 0;i<5;i++){
        printf("%s ",papan.d.Ar[i]);
    }
    printf("\n");
    for(int i = 0;i<5;i++){
        printf("%s ",papan.e.Ar[i]);
    }
    printf("\n");
}


void mole(){
    printf("Selamat datang pada game Mole. Anda adalah seorang petani dengan lahan seluas 5x5.\n");
    printf("Tetapi ada mole yang selalu merusak tanian Anda. Galilah grid pada lahan Anda untuk mencari molenya.\n");
    printf("Skor yang didapatkan berdasarkan seberapa cepat Anda mencari molenya.\n");
    int score = 25;
    boolean gameover = false;
    Board papan;
    int x,y,xmole,ymole;
    char *coordinates = "6 6";
    papan = CreateBoard();
    while(!gameover){
        PrintPapan(papan);
        randomnumber(&xmole,&ymole);
        while(!IsBlankGrid(papan,xmole,ymole)){
            randomnumber(&xmole,&ymole);
        }
        printf("%d %d cheat hehe\n",xmole,ymole);
        while(!IsValid(coordinates)){
            printf("Masukkan input dengan format 'x y', contoh 2 5: \n");
            INPUT();
            coordinates = wordToString(CWord);
            x = xcoor(coordinates);
            y = ycoor(coordinates);
            GetStr(papan.e, x-1);
            if(!IsValid(coordinates)){
                printf("Koordinat hanya bisa berisi x dan y pada range 1-5.\n");
            }
            if(!IsBlankGrid(papan,x,y)){
                coordinates = "6 6";
                printf("Inputan hanya bisa mengisi grid yang kosong yaitu yang berisi 'O'.\n");
            }
        }
        
        if(x == xmole && y == ymole){
            printf("Selamat Anda sudah menemukan molenya. Skor Anda %d\n",score);
            gameover = true;
        } else{
            UbahBoard(&papan,x,y);
            score -= 1;
        }
        coordinates = "6 6";
    }
}

// int main(){
//     mole();
// }